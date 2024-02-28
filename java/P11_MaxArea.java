package org.example;

public class P11_MaxArea {
    public static int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxS = 0;

        while (left < right) {
            int min = Math.min(height[left], height[right]);
            maxS = Math.max((right - left) * min, maxS);

            while (left < right && min >= height[left]) {
                left++;
            }
            while (left < right && min >= height[right]) {
                right--;
            }
        }
        return maxS;
    }

    public static void main(String[] args) {
        int[] input = new int[]{1,8,6,2,5,4,8,3,7};
//        int[] input = new int[]{1,1};
        System.out.println(maxArea(input));
    }
}
