class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        
        dp[0] = {1};
        for(int i=1;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                if(j == 0 || j == i) temp.push_back(1);
                else temp.push_back(dp[i-1][j-1] + dp[i-1][j]);
            }
            dp[i] = temp;
        }

        return dp;
    }
};