// Problem: 1872. Stone Game VIII
// Runtime: 101 ms (Beats 74.82%)
// Memory: 87.2 MB (Beats 84.19%)

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Total prefix sum up to current position
        int prefix = accumulate(stones.begin(), stones.end(), 0);

        // dp represents the best score difference
        // starting from the current state.
        int dp = prefix;

        // Build prefix sums from right to left
        for (int i = n - 2; i >= 1; i--) {
            prefix -= stones[i + 1];

            dp = max(dp, prefix - dp);
        }

        return dp;
    }
};