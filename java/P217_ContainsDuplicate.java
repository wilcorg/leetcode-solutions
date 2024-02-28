package org.example;

import java.util.HashSet;
import java.util.Set;

public class P217_ContainsDuplicate {
    public static boolean containsDuplicate(int[] nums) {
        System.gc();

        Set<Integer> hashSet = new HashSet<>();

        for (var num : nums) {
            if (!hashSet.add(num)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(containsDuplicate(new int[] {1, 1, 2, 3, 4}));
    }
}