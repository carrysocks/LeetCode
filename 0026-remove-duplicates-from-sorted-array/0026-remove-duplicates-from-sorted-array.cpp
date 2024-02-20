class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> m;
        int idx = 0;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(m[val] == 0){
                m[val] = 1;
                nums[idx++] = val;
            }
        }
        
        return idx;
    }
};