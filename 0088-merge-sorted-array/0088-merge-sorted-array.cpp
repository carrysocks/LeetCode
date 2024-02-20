class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int idx1 = 0, idx2 = 0;
        while(idx1 < m && idx2 < n){
            if(nums1[idx1] <= nums2[idx2]){
                temp.push_back(nums1[idx1++]);
            }
            else if(nums1[idx1] > nums2[idx2]){
                temp.push_back(nums2[idx2++]);
            }
        }
        
        while(idx1 < m){
            temp.push_back(nums1[idx1++]);
        }
        while(idx2 < n){
            temp.push_back(nums2[idx2++]);
        }
        
        for(int i=0;i<m+n;i++){
            nums1[i] = temp[i];
        }
    }
};