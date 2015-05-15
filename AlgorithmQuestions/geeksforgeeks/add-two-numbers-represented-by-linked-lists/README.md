### Question:
Given two numbers represented by two lists, write a function that returns sum list. The sum list is list representation of addition of two input numbers.

### Example:
+ Input:
    - First List: 7->5->9->4->6 // represents number 64957
    - Second List: 8->4 // represents number 48
+ Output:
    - Resultant List: 5->0->0->5->6 // represents number 65505

### Solution:
Traverse both lists. One by one pick nodes of both lists and add the values. If sum is more than 10 then make carry as 1 and reduce sum. If one list has more elements than the other consider remaining values of this list as 0.
