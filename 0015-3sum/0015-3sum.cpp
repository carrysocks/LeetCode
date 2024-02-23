class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i=0;i<n-1;i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int target = -nums[i];
            int l = i+1;
            int r = n-1;
            
            while(l < r){
                if(nums[l] + nums[r] < target) l++;
                else if(nums[l] + nums[r] > target) r--;
                else{
                    vector<int> triple = {nums[i], nums[l], nums[r]};
                    ans.push_back(triple);
                    while(l < r && triple[1] == nums[l]) l++;
                    while(l < r && triple[2] == nums[r]) r--;
                }
            }
        }
        
        return ans;
    }
};
