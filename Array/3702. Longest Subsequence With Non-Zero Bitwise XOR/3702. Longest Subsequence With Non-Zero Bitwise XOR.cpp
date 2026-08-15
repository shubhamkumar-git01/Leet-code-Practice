// Problem: 3702. Longest Subsequence With Non-Zero Bitwise XOR
// Runtime: 0 ms (Beats 100.00%)
// Memory: 171.4 MB (Beats 22.70%)

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        long long xr = 0;

        for (int x : nums)
            xr ^= x;

        if (xr != 0)
            return n;

        for (int x : nums) {
            if (x != 0)
                return n - 1;
        }

        return 0;
    }
};