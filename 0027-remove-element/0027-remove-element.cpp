class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                temp.push_back(nums[i]);
            }
        }
        
        int k = temp.size();
        for(int i=0;i<k;i++){
            nums[i] = temp[i];
        }
        
        return k;
    }
};