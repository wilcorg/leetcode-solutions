package org.example;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class P128_LongestConsecutive {
    public static int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        Set<Integer> set = new HashSet<>();
        int currentCount = 0;
        int maxCount = 0;

        for (int num : nums) {
            set.add(num);
        }

        for (int num : nums) {
            if (!set.contains(num - 1)) {
                int temp = num;
                currentCount = 1;

                while (set.contains(temp + 1)) {
                    currentCount += 1;
                    temp += 1;
                }
            }
            maxCount = Math.max(currentCount, maxCount);
        }
        return maxCount;
    }

//    public static int longestConsecutive(int[] nums) {
//// Step 1: Handle the base case when the array is empty.
//        if (nums.length == 0) {
//            return 0;
//        }
//
//        HashSet<Integer> set = new HashSet<>();
//
//        // Step 2: Insert all elements of 'nums' into the hash set 'set'.
//        for (int num : nums) {
//            set.add(num);
//        }
//
//        int cnt = 1;        // Initialize a counter for the current consecutive sequence length.
//        int longest = 0;    // Initialize a variable to store the maximum consecutive sequence length.
//
//        // Step 3: Iterate through the elements of 'nums'.
//        for (int num : nums) {
//            // Step 4: If the current element 'num' is the start of a sequence (no 'num-1' in 'set'),
//            if (!set.contains(num - 1)) {
//                int x = num; // Update 'x' to the current element 'num'.
//                cnt = 1;
//                // Step 5: While consecutive elements exist in 'set', increment 'cnt' and 'x'.
//                while (set.contains(x + 1)) {
//                    cnt++;
//                    x = x + 1;
//                }
//            }
//
//            // Step 6: Update 'longest' with the maximum of 'longest' and 'cnt'.
//            longest = Math.max(longest, cnt);
//        }
//
//        // Step 7: Return 'longest' as the result.
//        return longest;
//    }


    public static void main(String[] args) {
        int[] input = new int[]{100, 4, 200, 1, 3, 2};
//        int[] input = new int[]{9,1,4,7,3,-1,0,5,8,-1,6};
//        int[] input = new int[]{0, 1, 2, 4, 8, 5, 6, 7, 9, 3, 55, 88, 77, 99, 999999999};
//        int[] input = new int[]{0,3,7,2,5,8,4,6,0,1};
        System.out.println(longestConsecutive(input));
    }
}
