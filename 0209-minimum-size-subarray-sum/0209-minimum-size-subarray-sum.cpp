class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0, mn = 1e9;
        while(r < n){
            sum += nums[r++];
            while(sum >= target){
                mn = min(mn, r - l);
                sum -= nums[l++];
            }
        }
        
        return (mn == 1e9 ? 0 : mn);
    }
};

    
    
    
