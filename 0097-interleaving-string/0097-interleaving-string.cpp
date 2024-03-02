class Solution {
public:
    int dp[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        
        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                else if(j==0) dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
                else dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }

        return dp[s1.size()][s2.size()];
    }
};