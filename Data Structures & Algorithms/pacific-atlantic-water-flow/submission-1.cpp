
class Solution {
public:
    int n, m;
    bool p, a;

    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {

        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j]) {
            return;
        }

        vis[i][j] = true;

        if (i == 0 || j == 0) {
            p = true;
        }

        if (i == n - 1 || j == m - 1) {
            a = true;
        }

        if (p && a) return;

        if (i + 1 < n && heights[i + 1][j] <= heights[i][j])
            dfs(i + 1, j, heights, vis);

        if (i - 1 >= 0 && heights[i - 1][j] <= heights[i][j])
            dfs(i - 1, j, heights, vis);

        if (j + 1 < m && heights[i][j + 1] <= heights[i][j])
            dfs(i, j + 1, heights, vis);

        if (j - 1 >= 0 && heights[i][j - 1] <= heights[i][j])
            dfs(i, j - 1, heights, vis);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<bool>> vis(n, vector<bool>(m, false));

                p = false;
                a = false;

                dfs(i, j, heights, vis);

                if (p && a) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
