// Problem: 940. Distinct Subsequences II
// Runtime: 0 ms (Beats 100.00%)
// Memory: 8.9 MB (Beats 62.00%)

class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        vector<long long> last(26, 0);
        long long total = 1;  // empty subsequence

        for (char c : s) {
            int idx = c - 'a';

            long long newTotal = (2 * total - last[idx] + MOD) % MOD;

            last[idx] = total;
            total = newTotal;
        }

        return (total - 1 + MOD) % MOD;
    }
};