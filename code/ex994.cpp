class Solution {
public:
    int orangesRotting(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		queue<vector<int>> que;
		int freshOranges = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 2)
					que.push({i, j});
                else if (matrix[i][j] == 1)
                    freshOranges++;
            }
        if (freshOranges == 0)    return 0;

		int minutes = 0;
		while (!que.empty()) {
			int size = que.size();
			for (int z = size; z > 0; z--) {
				auto out = que.front();    que.pop();
				int i = out[0], j = out[1];
				for (auto& d : dir) {
					int ni = i + d[0], nj = j + d[1];
					if (ni < 0 || nj < 0 || ni >= m || nj >= n || matrix[ni][nj] != 1)    continue;
					matrix[ni][nj] = 2;
					if (--freshOranges == 0)    return minutes + 1;
					que.push({ni, nj});
				}
			}
			minutes++;
		}

		return -1;
    }
};