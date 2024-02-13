import java.util.*;

class MinStack {
    private Stack<Integer> mainStack;
    private Stack<Integer> minStack;

    public MinStack() {
        mainStack = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int data) {
        mainStack.push(data);
        if (minStack.isEmpty() || data <= minStack.peek()) {
            minStack.push(data);
        }
    }

    public void pop() {
        if (!mainStack.isEmpty()) {
            if ( mainStack.pop() == minStack.peek()) {
                minStack.pop();
            }
        }
    }

    public int getMin() {
        if (!minStack.isEmpty()) {
            return minStack.peek();
        }
        throw new EmptyStackException(); // Handle this case appropriately in your application
    }
}

public class Min_Stack {
    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(0);
        minStack.push(10);
        minStack.push(20);
        System.out.println("Minimum element: " + minStack.getMin());
    }
}
