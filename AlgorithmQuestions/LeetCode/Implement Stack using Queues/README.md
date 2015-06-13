### Implement Stack using Queues
Implement the following operations of a stack using queues.
+ `push(x)` -> Push element x onto stack
+ `pop()` -> Removes the element on top of the stack
+ `top()` -> Get the top element
+ `empty()` -> Return whether the stack is empty

**Notes:**
+ You must use *only* standard operations of a queue -> which means only `push to back`, `peek/pop from front`, `size`, and `is empty` operations are valid.
+ Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
+ You may assume that all operations are valid (for example, no pop or top opeartions will be called on an empty stack).

### Solution
+ `push(x)` -> just use queue.push(x)
+ `pop()` -> we traverse the queue and use a extra queue to store the element except the last element
+ `top()` -> same as `pop()` but we store all the elements and return the last element
+ `empty()` -> just use queue.empty()
