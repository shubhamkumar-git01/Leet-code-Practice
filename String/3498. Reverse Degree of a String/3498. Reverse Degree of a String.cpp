// Problem: 3498. Reverse Degree of a String
// Runtime: 3 ms (Beats 16.14%)
// Memory: 9.7 MB (Beats 47.88%)

class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int reverseValue = 'z' - s[i] + 1;
            ans += reverseValue * (i + 1);
        }

        return ans;
    }
};