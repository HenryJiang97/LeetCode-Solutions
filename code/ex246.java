class Solution {
    public boolean isStrobogrammatic(String num) {
        String[] dict = new String[]{"0", "1", "a", "b", "c", "d", "9", "e", "8", "6"};
        String newNum = "";
        for (int i = num.length() - 1; i >= 0; i--)
            newNum += dict[num.charAt(i) - '0'];
        return num.equals(newNum);
    }
}