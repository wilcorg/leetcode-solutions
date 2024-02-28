package org.example;

import java.util.Arrays;

public class P238_ProductExceptSelf {
//    public static int[] productExceptSelf(int[] nums) {
//        int totalProduct = 1;
//        boolean firstZero = false;
//        int[] result = new int[nums.length];
//
//        for (int num : nums) {
//            if (num == 0) {
//                if (firstZero) {
//                    return result;
//                } else {
//                    firstZero = true;
//                }
//            } else {
//                totalProduct *= num;
//            }
//        }
//
//        for (int i = 0; i < nums.length; i++) {
//            if (firstZero) {
//                if (nums[i] == 0) {
//                    result[i] = totalProduct;
//                } else {
//                    result[i] = 0;
//                }
//            } else {
//                result[i] = totalProduct / nums[i];
//            }
//        }
//
//        return result;
//    }
    
    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        // result[i] = 1 * result[0] * result[1] * ... * result[i - 1]
        int prefix = 1;
        for(int i = 0; i < n; i += 1) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        // result[i] = result[i] * result[n - 1] * result[n - 2] * ... * result[i + 1]
        int postfix = 1;
        for(int i = n - 1; i >= 0; i -= 1) {
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }


    public static void main(String[] args) {
        int[] input = new int[]{1, 2, 3, 4};
//        int[] input = new int[]{-1,1,0,-3,3};
//        int[] input = new int[]{-1,0,0,-3,3};
        System.out.println(Arrays.toString(productExceptSelf(input)));
    }
}
