class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxIdx = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mxIdx >= n-1) return true;
            else if(nums[i] == 0 && mxIdx == i) return false;
            if(i + nums[i] > mxIdx) mxIdx = i + nums[i];
        }
        
        return true;
    }
};