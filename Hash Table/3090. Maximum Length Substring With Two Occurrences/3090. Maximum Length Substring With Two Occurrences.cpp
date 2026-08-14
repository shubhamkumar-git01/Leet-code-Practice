// Problem: 3090. Maximum Length Substring With Two Occurrences
// Runtime: 0 ms (Beats 100.00%)
// Memory: 9 MB (Beats 95.50%)

class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);

        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;

            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};