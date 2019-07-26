// e: 0 1 3 5 7 8 9
// f: 4 5
// g: 8
// h: 3 8
// i: 5 6 8 9
// n: 1 7 9
// o: 0 1 2 4
// r: 0 3 4
// s: 6 7
// t: 2 3 8
// u: 4
// v: 5 7
// w: 2
// x: 6
// z: 0
// Don't use 'e' and 'n' for calculation, they appears multiple times in the English of digits

import java.util.*;

class Solution {
    public String originalDigits(String s) {
        char[] arr = s.toCharArray();
        
        // Get the appearance of each char
        int[] app = new int[26];
        for (char c : arr) {
            app[c - 'a']++;
        } 
        
        // Array contains the appearence of each digit
        int[] num = new int[10];
        
        num[8] = app['g' - 'a'];       
        num[4] = app['u' - 'a'];
        num[2] = app['w' - 'a'];
        num[6] = app['x' - 'a'];
        num[0] = app['z' - 'a'];
        num[3] = app['t' - 'a'] - num[2] - num[8];
        num[7] = app['s' - 'a'] - num[6];
        num[5] = app['f' - 'a'] - num[4];
        num[9] = app['i' - 'a'] - num[5] - num[6] - num[8];
        num[1] = app['o' - 'a'] - num[0] - num[2] - num[4];

        // Form the original digits from English
        String res = "";
        for (int i = 0; i < 10; i++) {
            for (int n = 0; n < num[i]; n++) {
                res += String.valueOf(i);
            }
        }
        
        return res;
    }
}