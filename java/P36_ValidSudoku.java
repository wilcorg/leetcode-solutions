package org.example;

import java.util.HashSet;
import java.util.Set;

public class P36_ValidSudoku {
    public static boolean isValidSudoku(char[][] board) {
        Set<Character> digits;
        Set<Character> digitsSecond;

        for (int y = 0; y < 9; y += 3) {
            for (int x = 0; x < 9; x += 3) {
                digits = new HashSet<>();

                for (int ty = y; ty < y + 3; ty++) {
                    for (int tx = x; tx < x + 3; tx++) {

                        if (board[ty][tx] != '.') {
                            if (digits.contains(board[ty][tx])) {
                                return false;
                            } else {
                                digits.add(board[ty][tx]);
                            }
                        }
                    }
                }
            }
        }

        for (int y = 0; y < 9; y++) {
            digits = new HashSet<>();
            digitsSecond = new HashSet<>();
            for (int x = 0; x < 9; x++) {
                if (board[y][x] != '.') {
                    if (digits.contains(board[y][x])) {
                        return false;
                    } else {
                        digits.add(board[y][x]);
                    }
                }

                if (board[x][y] != '.') {
                    if (digitsSecond.contains(board[x][y])) {
                        return false;
                    } else {
                        digitsSecond.add(board[x][y]);
                    }

                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        char[][] board = new char[][]{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}
                , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
                , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
                , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
                , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
                , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
                , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
                , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
                , {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

        System.out.println(isValidSudoku(board));
    }
}
