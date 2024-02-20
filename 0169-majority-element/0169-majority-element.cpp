class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] += 1;
        }
        
        int mx = -1;
        int ans = 0;
        for(auto p : m){
            if(mx < p.second){
                ans = p.first;
                mx = p.second;
            }
        }
        
        return ans;
    }
};