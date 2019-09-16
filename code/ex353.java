class SnakeGame {
    private Queue<int[]> queue = new LinkedList<>();
    private Set<Integer> block = new HashSet<>();
    private int[][] f;
    private int fi = 0;
    private int m, n;
    private int score = 0;
    private int i, j;

    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    public SnakeGame(int width, int height, int[][] food) {
        m = height;    n = width;
        
        f = food;
        
        queue.offer(new int[]{0, 0});
        block.add(0);
        i = 0; j = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    public int move(String direction) {
        int[] tail = queue.peek();
        if (direction.equals("U")) {
            if (i - 1 < 0 || (block.contains((i - 1) * n + j) && !(i - 1 == tail[0] && j == tail[1])))
                return -1;
            else    i--;
        }
        else if (direction.equals("L")) {
            if (j - 1 < 0 || (block.contains(i * n + j - 1) && !(i == tail[0] && j - 1 == tail[1])))
                return -1;
            else    j--;
        }
        else if (direction.equals("R")) {
            if (j + 1 >= n || (block.contains(i * n + j + 1) && !(i == tail[0] && j + 1 == tail[1])))
                return -1;
            else    j++;
        }
        else if (direction.equals("D")) {
            if (i + 1 >= m || (block.contains((i + 1) * n + j) && !(i + 1 == tail[0] && j == tail[1])))
                return -1;
            else    i++;
        }

        // Meets the food
        if (fi < f.length && i == f[fi][0] && j == f[fi][1]) {
            queue.offer(new int[]{i, j});
            block.add(i * n + j);
            score++;
            fi++;
        }
        else {    // Not meet any food
            queue.offer(new int[]{i, j});
            int[] out = queue.poll();
            block.remove(out[0] * n + out[1]);
            block.add(i * n + j);
        }
        
        return score;
    }
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */