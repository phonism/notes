import java.util.*;

class MyStack {
    Queue<Integer> q = new LinkedList<Integer>();
    // Push element x onto stack
    public void push(int x) {
        q.add(x);
    }

    // Removes the element on top of the stack
    public void pop() {
        Queue<Integer> p = new LinkedList<Integer>();
        while (!q.isEmpty()) {
            if (q.size() == 1) {
                break;
            }
            p.add(q.remove());
        }
        q = p;
    }

    // Get the top element
    public int top() {
        Queue<Integer> p = new LinkedList<Integer>();
        while (q.peek() != null) {
            if (q.size() == 1) {
                p.add(q.element());
                int tmp = q.element();
                q = p;
                return tmp;
            }
            p.add(q.remove());
        }
        return 0;
    }

    // Return whether the stack is empty
    public boolean empty() {
        return q.isEmpty();
    }
}

public class implement_stack_using_queues {
    
    public void run() {
        MyStack s = new MyStack();
        s.push(1);
        s.push(2);
        System.out.println(s.top());
        s.pop();
        System.out.println(s.empty());
    }

    public static void main(String[] args) {
        new implement_stack_using_queues().run();
    }
}
