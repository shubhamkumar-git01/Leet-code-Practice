// Problem: 3524. Find X Value of Array I
// Runtime: 186 ms (Beats 21.43%)
// Memory: 151 MB (Beats 81.25%)

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);

            // Start a new subarray
            ndp[num % k]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newRem = (r * (num % k)) % k;
                ndp[newRem] += dp[r];
            }

            // Add all subarrays ending here
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};