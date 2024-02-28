package org.example;

import java.util.ArrayList;

//class MinStack {
//    public MinStack() {
//        this.valuesList = new ArrayList<>();
//    }
//
//    public void push(int val) {
//        valuesList.add(val);
//        counter++;
//        this.min = Math.min(this.min, val);
//    }
//
//    public void pop() {
//        if (counter != 0) {
//            valuesList.remove(--counter);
//
//            this.min = Integer.MAX_VALUE;
//            for (var val : this.valuesList) {
//                this.min = Math.min(this.min, val);
//            }
//        }
//    }
//
//    public int top() {
//        return valuesList.get(counter - 1);
//    }
//
//    public int getMin() {
//        return min;
//    }
//
//    private final ArrayList<Integer> valuesList;
//    private int min = Integer.MAX_VALUE;
//    private int counter = 0;
//}

class MinStack {

    private record Node(Node next, int val, int min) {
    }

    private Node head;

    public MinStack() {
    }

    public void push(int val) {
        if (this.head == null) {
            head = new Node(null, val, val);
        } else {
            head = new Node(head, val, Math.min(head.min, val));
        }
    }

    public void pop() {
        head = head.next;
    }

    public int top() {
        if (head == null) {
            return Integer.MAX_VALUE;
        } else {
            return head.val;
        }
    }

    public int getMin() {
        return head.min;
    }
}

public class P155_MinStack {
    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-1);
        System.out.println(minStack.getMin());
        System.out.println(minStack.top());
        minStack.pop();
        System.out.println(minStack.getMin());
    }
}
