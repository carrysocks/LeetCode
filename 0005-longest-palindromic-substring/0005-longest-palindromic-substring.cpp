class Solution {
public:
    int dp[1001][1001];
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i=0;i<n;i++) dp[i][i] = true;

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(s[i] == s[j]){
                    if(i-j == 1 || dp[j+1][i-1]){
                        dp[j][i] = true;
                    }
                }
            }
        }

        int mx = 1;
        string mxSubstring = string(1, s[0]);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(dp[i][j] && (j-i+1) > mx){
                    mx = j-i+1;
                    mxSubstring = s.substr(i,j-i+1); 
                }
            }
        }

        return mxSubstring;
    }
};