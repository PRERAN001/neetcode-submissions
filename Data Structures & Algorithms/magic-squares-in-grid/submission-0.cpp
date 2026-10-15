
class Solution {
public:
    bool checkNumbers(int i, int j, vector<vector<int>>& grid) {
        bool seen[10] = {};

        for (int a = i; a < i + 3; a++) {
            for (int b = j; b < j + 3; b++) {
                int x = grid[a][b];

                if (x < 1 || x > 9 || seen[x]) {
                    return false;
                }

                seen[x] = true;
            }
        }

        return true;
    }

    bool checkRows(int i, int j, vector<vector<int>>& grid) {
        int target = 0;

        for (int b = j; b < j + 3; b++) {
            target += grid[i][b];
        }

        for (int a = i; a < i + 3; a++) {
            int sum = 0;

            for (int b = j; b < j + 3; b++) {
                sum += grid[a][b];
            }

            if (sum != target) return false;
        }

        return true;
    }

    bool checkColumns(int i, int j, vector<vector<int>>& grid) {
        int target = 0;

        for (int a = i; a < i + 3; a++) {
            target += grid[a][j];
        }

        for (int b = j; b < j + 3; b++) {
            int sum = 0;

            for (int a = i; a < i + 3; a++) {
                sum += grid[a][b];
            }

            if (sum != target) return false;
        }

        return true;
    }

    bool checkDiagonals(int i, int j, vector<vector<int>>& grid) {
        int d1 = 0, d2 = 0;

        for (int k = 0; k < 3; k++) {
            d1 += grid[i + k][j + k];
            d2 += grid[i + k][j + 2 - k];
        }

        return d1 == d2 &&
               d1 == grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
    }

    bool valid(int i, int j, vector<vector<int>>& grid) {
        return checkNumbers(i, j, grid) &&
               checkRows(i, j, grid) &&
               checkColumns(i, j, grid) &&
               checkDiagonals(i, j, grid);
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (n < 3 || m < 3) return 0;

        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (valid(i, j, grid)) {
                    count++;
                }
            }
        }

        return count;
    }
};
