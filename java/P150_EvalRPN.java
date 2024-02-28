package org.example;

import java.util.Stack;

public class P150_EvalRPN {
//    public static int evalRPN(String[] tokens) {
//        Stack<Integer> values = new Stack<>();
//
//        for (String token : tokens) {
//            if (token.matches("-?[0-9]+")) {
//                values.push(Integer.valueOf(token));
//            } else {
//                int val2 = values.pop();
//                int val1 = values.pop();
//
//                switch (token) {
//                    case "+" -> values.push(val1 + val2);
//                    case "-" -> values.push(val1 - val2);
//                    case "*" -> values.push(val1 * val2);
//                    case "/" -> values.push(val1 / val2);
//                }
//            }
//        }
//
//        return values.pop();
//    }

    public static int evalRPN(String[] tokens) {
        Stack<Integer> values = new Stack<>();

        for (String token : tokens) {
            if ("+-*/".contains(token)) {
                int val2 = values.pop();
                int val1 = values.pop();

                switch (token) {
                    case "+" -> values.push(val1 + val2);
                    case "-" -> values.push(val1 - val2);
                    case "*" -> values.push(val1 * val2);
                    case "/" -> values.push(val1 / val2);
                }
            } else {
                values.push(Integer.parseInt(token));
            }
        }

        return values.pop();
    }
    public static void main(String[] args) {
        String[] tokens = new String[]{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        System.out.println(evalRPN(tokens));
    }
}
