package org.example;

import java.util.*;

public class P1_TwoSum {
    public static int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int compVal = target - nums[i];

            if (!map.containsKey(compVal)) {
                map.put(nums[i], i);
            } else {
                return new int[] {map.get(compVal), i};
            }
        }

        return new int[] {};
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(twoSum(new int[]{2, 7, 11, 15}, 9)));
    }
}
