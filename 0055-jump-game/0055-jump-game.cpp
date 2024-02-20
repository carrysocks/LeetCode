class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump[10005];
        int n = nums.size();
        
        for(int i=0;i<10005;i++) jump[i] = 0;
        
        jump[0] = 1;
        
        for(int i=0;i<n;i++){
            
            if(i != 0 && jump[i] == 0) continue;
            
            for(int j=1;j<=nums[i];j++){
                if(i+j >= n) break;
                jump[i+j] = 1;
            }
        }
        
        return jump[n-1];
    }
};