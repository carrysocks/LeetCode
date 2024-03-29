class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        vector<long long> dp(n+3, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4;i<=n;i++){
            dp[i] = (dp[i-1]*2 + dp[i-3]) % mod;
        }

        return dp[n];
    }
};