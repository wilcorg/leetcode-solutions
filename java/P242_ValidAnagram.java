package org.example;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class P242_ValidAnagram {
//    public static boolean isAnagram(String s, String t) {
//        if (s.length() != t.length()) {
//            return false;
//        }
//
//        Map<Character, Integer> sMap = new HashMap<>();
//        Map<Character, Integer> tMap = new HashMap<>();
//
//        for (int i = 0; i < s.length(); i++) {
//            Character sChar = s.charAt(i);
//            Character tChar = t.charAt(i);
//
//            sMap.merge(sChar, 1, Integer::sum);
//            tMap.merge(tChar, 1, Integer::sum);
//        }
//
//        for (var character : sMap.keySet()) {
//            if (!sMap.get(character).equals(tMap.get(character))) {
//                return false;
//            }
//        }
//        return true;
//    }

    public static boolean isAnagram(String s, String t) {

        if (s.length() != t.length())
            return false;

        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();

        Arrays.sort(sArr);
        Arrays.sort(tArr);

        String s1 = new String(sArr);
        String t1 = new String(tArr);

        return s1.equals(t1);
    }

    public static void main(String[] args) {
        System.out.println(isAnagram("anagram", "nagaram"));
        System.out.println(isAnagram("rat", "car"));
    }
}
