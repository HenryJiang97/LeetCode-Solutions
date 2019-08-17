class Solution {
    public boolean judgeCircle(String moves) {
        Map<Character, int[]> navi = new HashMap<>();
        navi.put('U', new int[]{-1, 0});
        navi.put('D', new int[]{1, 0});
        navi.put('L', new int[]{0, -1});
        navi.put('R', new int[]{0, 1});
        int[] pos = new int[]{0, 0};
        
        for (char c : moves.toCharArray()) {
            pos[0] += navi.get(c)[0];
            pos[1] += navi.get(c)[1];
        }
        
        return pos[0] == 0 && pos[1] == 0;
    }
}