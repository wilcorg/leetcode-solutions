package org.example;

public class P14_LongestCommonPrefix {
//    public static String longestCommonPrefix(String[] strs) {
//        String result = "";
//        int maxPrefixLength = Integer.MAX_VALUE;
//        boolean failed = false;
//
//        for (String string: strs) {
//            maxPrefixLength = Math.min(maxPrefixLength, string.length());
//        }
//
//        for (int i = 0; i < maxPrefixLength; i++) {
//            char expect = strs[0].charAt(i);
//
//            for (String string: strs) {
//                if (string.charAt(i) != expect) {
//                    failed = true;
//                    break;
//                }
//            }
//
//            if (failed) {
//                break;
//            }
//            result += expect;
//        }
//
//        return result;
//    }

    public static String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }

        String prefix = strs[0];

        for (int i = 1; i < strs.length; i++) {
            while (strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);

                if (prefix.isEmpty()) {
                    return "";
                }
            }
        }
        return prefix;
    }
    public static void main(String[] args) {
//        String[] strs = new String[]{"flower", "flow", "flight"};
        String[] strs = new String[]{"cir", "car"};
        System.out.println(longestCommonPrefix(strs));
    }
}
