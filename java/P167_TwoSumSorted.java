package org.example;

import java.util.*;

public class P167_TwoSumSorted {
//    public static int[] twoSum(int[] numbers, int target) {
//        Map<Integer, Integer> numToInd = new HashMap<>();
//
//        for (int i = 0; i < numbers.length; i++) {
//            int complement = target - numbers[i];
//
//            if (numToInd.containsKey(complement)) {
//                return new int[] {numToInd.get(complement), i};
//            } else {
//                numToInd.put(numbers[i], i);
//            }
//        }
//        return new int[]{};
//    }

    public static int[] twoSum(int[] numbers, int target) {
        int leftInd = 0;
        int rightInd = numbers.length - 1;
        int offer = numbers[leftInd] + numbers[rightInd];

        while (offer != target) {
            if (offer > target) {
                rightInd--;
            } else {
                leftInd++;
            }
            offer = numbers[leftInd] + numbers[rightInd];
        }
        return new int[] {leftInd + 1, rightInd + 1};
    }

    public static void main(String[] args) {
        int[] numbers = new int[]{0, 2, 9, 11, 15};
        int target = 11;
        System.out.println(Arrays.toString(twoSum(numbers, target)));
    }
}
