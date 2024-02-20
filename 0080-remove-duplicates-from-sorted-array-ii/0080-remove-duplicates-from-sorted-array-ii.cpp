class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        int depth = 1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] != nums[i]){
                nums[idx++] = nums[i];
                depth = 1;
            }
            else if(depth < 2){
                nums[idx++] = nums[i];
                depth++;
            }
        }
        
        return idx;
    }
};