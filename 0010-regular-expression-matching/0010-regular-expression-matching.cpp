class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(21, vector<bool>(21, false));
        dp[0][0] = true;

        for(int j=1;j<=m;j++){
            dp[0][j] = (p[j-1] == '*') && (dp[0][j-2]);
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1] != '*'){
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
                else{
                    dp[i][j] = dp[i][j-2] || 
                    (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};