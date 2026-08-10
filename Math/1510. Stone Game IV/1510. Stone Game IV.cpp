// Problem: 1510. Stone Game IV
// Runtime: 135 ms (Beats 21.80%)
// Memory: 9 MB (Beats 73.64%)

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j*j<=i;j++)
                if(!dp[i-j*j]) dp[i]=1;
        return dp[n];
    }
};