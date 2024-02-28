package org.example;

import java.util.Stack;

public class P20_ValidParentheses {
    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.add(c);
            } else {
                if (stack.isEmpty()) return false;

                switch (c) {
                    case ')' -> {
                        if (stack.pop() != '(') return false;
                    }
                    case ']' -> {
                        if (stack.pop() != '[') return false;
                    }
                    case '}' -> {
                        if (stack.pop() != '{') return false;
                    }
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String s = "()[]}";
        System.out.println(isValid(s));

    }
}
