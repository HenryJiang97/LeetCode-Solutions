class SnakeGame {
    unordered_map<string, vector<int>> dir{{"U", {-1, 0}}, {"D", {1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}};
    vector<vector<int>> food;
    int m, n, i, j, f, l;
    queue<int> que;
    unordered_set<int> occupied;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->food = food;
        m = height;    n = width;
        i = 0;    j = 0;    f = 0;    l = 0;
        occupied.insert(0);
        que.push(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        vector<int>& d = dir[direction];
        i += d[0];    j += d[1];
        if (i < 0 || j < 0 || i >= m || j >= n)    return -1;
        if (f < food.size() && i == food[f][0] && j == food[f][1]) {
            f++;
            que.push(i * n + j);
            occupied.insert(i * n + j);
            return ++l;
        } else {
            occupied.erase(que.front());
            que.pop();
            if (occupied.count(i * n + j) > 0)    return -1;
            que.push(i * n + j);
            occupied.insert(i * n + j);
            return l;
        }
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */