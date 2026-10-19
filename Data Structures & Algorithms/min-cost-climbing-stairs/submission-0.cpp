class Solution {
public:
    int dpsolveeeee(vector<int>& v, int i, vector<int>& dp) {
        if (i <= 1) {
            return v[i];
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int one = v[i] + dpsolveeeee(v, i - 1, dp);
        int two = v[i] + dpsolveeeee(v, i - 2, dp);

        return dp[i] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        return min(dpsolveeeee(cost, n - 1, dp),
                   dpsolveeeee(cost, n - 2, dp));
    }
};