class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (!m) return res;
        int n = matrix[0].size();
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

        for (int i = 0, x = 0, y = 0, d = 0; i < m * n; i++) {
            res.push_back(matrix[x][y]);
            matrix[x][y] = 1e9;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= m || b < 0 || b >= n || matrix[a][b] == 1e9) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }

        return res;
    }
};