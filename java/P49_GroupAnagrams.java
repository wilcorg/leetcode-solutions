package org.example;

import java.util.*;

public class P49_GroupAnagrams {
//    public static List<List<String>> groupAnagrams(String[] strs) {
//        if (strs.length == 0) {
//            return new ArrayList<>();
//        }
//
//        List<Boolean> anaToSkip = new ArrayList<>(Collections.nCopies(strs.length, Boolean.FALSE));
//        List<List<String>> result = new ArrayList<>();
//
//        while (anaToSkip.contains(Boolean.FALSE)) {
//            int ungroupedIndex = anaToSkip.indexOf(Boolean.FALSE);
//            List<String> anaPartit = new ArrayList<>(List.of(strs[ungroupedIndex]));
//            anaToSkip.set(ungroupedIndex, Boolean.TRUE);
//
//            for (int i = 0; i < strs.length; i++) {
//                if (!anaToSkip.get(i)) {
//                    if (isAnagram(strs[i], anaPartit.getFirst())) {
//                        anaPartit.add(strs[i]);
//                        anaToSkip.set(i, Boolean.TRUE);
//                    }
//                }
//            }
//            result.add(anaPartit);
//        }
//
//        return result;
//    }
//
//    public static boolean isAnagram(String s, String t) {
//
//        if (s.length() != t.length())
//            return false;
//
//        char[] sArr = s.toCharArray();
//        char[] tArr = t.toCharArray();
//
//        Arrays.sort(sArr);
//        Arrays.sort(tArr);
//
//        String s1 = new String(sArr);
//        String t1 = new String(tArr);
//
//        return s1.equals(t1);
//    }

    public static List<List<String>> groupAnagrams(String[] strs) {
       List<List<String>> result = new ArrayList<>();
       Map<String, List<String>> map = new HashMap<>();

       for (String str : strs) {
           char[] charArray = str.toCharArray();
           Arrays.sort(charArray);
           String sortedAnagram = new String(charArray);

           if (map.containsKey(sortedAnagram)) {
               map.get(sortedAnagram).add(str);
           } else {
               List<String> anagramPartit = new ArrayList<>();
               anagramPartit.add(str);
               map.put(sortedAnagram, anagramPartit);
           }
       }

       for (var entry : map.entrySet()) {
           result.add(entry.getValue());
       }

       return result;
    }

    public static void main(String[] args) {
        String[] strs = new String[]{"eat", "tea", "tan", "ate", "nat", "bat"};
//        String[] strs = new String[]{""};
        System.out.println(groupAnagrams(strs));
    }
}
