// Problem: 3471. Find the Largest Almost Missing Integer
// Runtime: 8 ms (Beats 31.27%)
// Memory: 32.6 MB (Beats 29.45%)

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            for (int x : st) {
                cnt[x]++;
            }
        }

        int ans = -1;

        for (auto &p : cnt) {
            if (p.second == 1) {
                ans = max(ans, p.first);
            }
        }

        return ans;
    }
};