package org.example;

import java.util.*;

public class P2273_WithoutAnagrams {

//    public static List<String> removeAnagrams(String[] words) {
//
//        if (words.length == 1) {
//            return List.of(words);
//        }
//
//        List<String> result = new ArrayList<>();
//
//        char[] wordOneArray = words[0].toCharArray();
//        Arrays.sort(wordOneArray);
//        String wordOneSorted = new String(wordOneArray);
//        result.add(words[0]);
//
//        for (int i = 1; i < words.length; i++) {
//
//            char[] wordTwoArray = words[i].toCharArray();
//            Arrays.sort(wordTwoArray);
//            String wordTwoSorted = new String(wordTwoArray);
//
//            if (!wordOneSorted.equals(wordTwoSorted)) {
//                wordOneSorted = wordTwoSorted;
//                result.add(words[i]);
//            }
//        }
//        return result;
//    }

    public static List<String> removeAnagrams(String[] words) {
        List<String> result = new ArrayList<>();
        String wordOneSorted = "";

        for (String word : words) {
            char[] wordTwoArray = word.toCharArray();
            Arrays.sort(wordTwoArray);
            String wordTwoSorted = new String(wordTwoArray);

            if (!wordTwoSorted.equals(wordOneSorted)) {
                result.add(word);
                wordOneSorted = wordTwoSorted;
            }
        }
        return result;
    }


    public static void main(String[] args) {
//        String[] stdin = new String[] {"abba", "baba", "bbaa", "cd", "cd"};
        String[] stdin = new String[] {"a", "b", "a"};
        System.out.println(removeAnagrams(stdin));
    }
}
