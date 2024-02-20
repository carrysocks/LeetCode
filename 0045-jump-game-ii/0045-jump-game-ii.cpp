class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[10005];
        int n = nums.size();
        for(int i=0;i<10005;i++) dp[i] = 1e9;
        dp[0] = 0;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j >= n) break;
                dp[i+j] = min(dp[i+j], dp[i] + 1);
            }
        }
        
        return dp[n-1];
    }
};