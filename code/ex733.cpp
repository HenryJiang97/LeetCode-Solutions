const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
    int m, n;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();    n = image[0].size();
        dfs(image, sr, sc, image[sr][sc], newColor);
        image[sr][sc] = newColor;
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int i, int j, int originColor, int newColor) {
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || image[ni][nj] != originColor || image[ni][nj] == newColor)    
                continue;
            image[ni][nj] = newColor;
            dfs(image, ni, nj, originColor, newColor);
        }
    }
};