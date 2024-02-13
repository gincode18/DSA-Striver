import java.util.*;

public class LoopDetect {
    public static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    static Node push(int newData, Node head) {
        Node newNode = new Node(newData);
        newNode.next = head;
        head = newNode;
        return head;
    }

    boolean LoopDetect(Node head) {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    // Function to print the linked list
    static void printLinkedList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String arg[]) {
        Node list = new Node(20);
        list = push(41, list);
        list = push(5, list);
        list = push(10, list);
    

        LoopDetect ld = new LoopDetect();
        System.out.println("Loop detected: " + ld.LoopDetect(list));

        // Print the linked list
        System.out.println("Linked List:");
        printLinkedList(list);
    }
}
