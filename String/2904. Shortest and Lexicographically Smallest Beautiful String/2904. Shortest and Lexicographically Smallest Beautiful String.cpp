// Problem: 2904. Shortest and Lexicographically Smallest Beautiful String
// Runtime: 0 ms (Beats 100.00%)
// Memory: 8.6 MB (Beats 82.87%)

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), cnt = 0, l = 0, best = n + 1;
        string ans = "";

        for (int r = 0; r < n; r++) {
            cnt += s[r] == '1';

            while (cnt > k) {
                cnt -= s[l++] == '1';
            }

            if (cnt == k) {
                while (s[l] == '0') l++;

                string cur = s.substr(l, r - l + 1);

                if (cur.size() < best || 
                   (cur.size() == best && cur < ans)) {
                    best = cur.size();
                    ans = cur;
                }
            }
        }

        return ans;
    }
};