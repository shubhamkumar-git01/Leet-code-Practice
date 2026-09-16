// Problem: 1621. Number of Sets of K Non-Overlapping Line Segments
// Runtime: 39 ms (Beats 59.81%)
// Memory: 53 MB (Beats 34.11%)

class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

        // 0 segments banane ka 1 way
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {
            long long prefix = 0;

            for (int i = 1; i < n; i++) {

                // Previous states ka prefix sum
                prefix = (prefix + dp[i - 1][j - 1]) % MOD;

                // Either:
                // 1. Current point ko use nahi karte
                // 2. Ek segment current point par end karte hain
                dp[i][j] = (dp[i - 1][j] + prefix) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};