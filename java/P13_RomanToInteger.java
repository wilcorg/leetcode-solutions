package org.example;

import java.util.HashMap;
import java.util.Map;

public class P13_RomanToInteger {
    static Map<Character, Integer> map = new HashMap<>() {{
        put('I', 1);
        put('V', 5);
        put('X', 10);
        put('L', 50);
        put('C', 100);
        put('D', 500);
        put('M', 1000);
    }};

//    static public int romanToInt(String s) {
//        int result = 0;
//
//        for (int i = s.length() - 1; i >= 0; i--) {
//            char target = s.charAt(i);
//
//            switch (target) {
//                case 'I' -> result += map.get(target);  // 1
//                case 'V' -> {
//                    if (i >= 1 && s.charAt(i - 1) == 'I') {
//                        result += 4;  // 4
//                        i--;
//                    } else {
//                        result += map.get(target);  // 5
//                    }
//                }
//                case 'X' -> {
//                    if (i >= 1 && s.charAt(i - 1) == 'I') {
//                        result += 9;  // 9
//                        i--;
//                    } else {
//                        result += map.get(target);  // 10
//                    }
//                }
//                case 'L' -> {
//                    if (i >= 1 && s.charAt(i - 1) == 'X') {
//                        result += 40;  // 40
//                        i--;
//                    } else {
//                        result += map.get(target);  // 50
//                    }
//                }
//                case 'C' -> {
//                    if (i >= 1 && s.charAt(i - 1) == 'X') {
//                        result += 90;  // 90
//                        i--;
//                    } else {
//                        result += map.get(target);  // 100
//                    }
//                }
//                case 'D' -> {
//                    if (i >= 1 && s.charAt(i - 1) == 'C') {
//                        result += 400;  // 400
//                        i--;
//                    } else {
//                        result += map.get(target);  // 500
//                    }
//                }
//                case 'M' -> {
//                    if (i >= 1 && s.charAt(i - 1) == 'C') {
//                        result += 900;  // 90
//                        i--;
//                    } else {
//                        result += map.get(target);  // 1000
//                    }
//                }
//            }
//        }
//        return result;
//    }

    static public int romanToInt(String s) {
        int result = 0;
        char last = 'I';

        for (int i = s.length() - 1; i >= 0; i--) {
            char current = s.charAt(i);

            if (map.get(last) > map.get(current)) {
                result -= map.get(current);
            } else {
                result += map.get(current);
            }
            last = current;
        }
        return result;
    }

    public static void main(String[] args) {
//        String input = "III";
//        String input = "LVIII";
        String input = "MCMXCIV";
        System.out.println(romanToInt(input));
    }
}
