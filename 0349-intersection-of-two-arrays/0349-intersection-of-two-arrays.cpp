class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num(nums1.begin(), nums1.end());
        vector<int> ans;
        for(int n : nums2){
            if(num.count(n)){
                ans.push_back(n);
                num.erase(n);
            }
        }

        return ans;
    }
};