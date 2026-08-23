// Problem: 1927. Sum Game
// Runtime: 4 ms (Beats 47.55%)
// Memory: 13.8 MB (Beats 97.67%)

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), diff = 0, q1 = 0, q2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') q1++;
            else diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') q2++;
            else diff -= num[i] - '0';
        }

        // If number of '?' is odd, Alice can always make sums unequal
        if ((q1 + q2) % 2) return true;

        // Bob can force equality only when the required difference
        // can be balanced by the '?' positions.
        return diff != (q2 - q1) * 9 / 2;
    }
};