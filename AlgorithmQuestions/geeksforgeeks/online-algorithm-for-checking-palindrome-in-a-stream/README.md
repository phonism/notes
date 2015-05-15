### Question:
Given a stream of characters (characters are received one by one), write a function that prints 'Yes' if a character makes the complete string palindrome, else prints 'No'.

### Solution:
Let input string be str[0...n-1]. A **Simple Solution** is to do following for every character str[i] in input string. Check if substring str[0...i] is palindrome, then print yes, else print no.

A **Better Solution** is to use the idea of Rolling Hash used in Rabin Karp algorithm. The idea is to keep track of reverse of first half and second half (we also use first half and reverse of second half) for every index.
