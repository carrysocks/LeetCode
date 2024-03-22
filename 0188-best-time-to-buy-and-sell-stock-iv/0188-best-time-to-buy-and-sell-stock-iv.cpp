class Solution {
public:
    int dp[1005][105];
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        for(int j=1;j<=k;j++){
            int minPrice = prices[0];
            for(int i=1;i<n;i++){
                minPrice = min(minPrice, prices[i] - dp[i-1][j-1]);
                dp[i][j] = max(dp[i-1][j], prices[i] - minPrice);
            }
        }

        return dp[n-1][k];
    }
};