package org.example;

import java.util.*;

public class P347_TopKFrequent {

    public static int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        List<List<Integer>> bucket = new ArrayList<>(Collections.nCopies(nums.length + 1, null));
        int[] result = new int[k];

        for (int num : nums) {
            freqMap.merge(num, 1, Integer::sum);
        }

        for (int key : freqMap.keySet()) {
            int freq = freqMap.get(key);

            List<Integer> values;
            if (bucket.get(freq) == null) {
                values = new ArrayList<>();
            } else {
                values = bucket.get(freq);
            }
            values.add(key);
            bucket.set(freq, values);
        }

        int resIndex = 0;
        for (int i = bucket.size() - 1; i >= 0; i--) {

            if (bucket.get(i) != null) {
                for (int val : bucket.get(i)) {
                    result[resIndex++] = val;

                    if (resIndex == k) {
                        return result;
                    }
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{4,1,-1,2,-1,2,3};
        int k = 2;

        System.out.println(Arrays.toString(topKFrequent(nums, k)));
    }
}
