class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        int n = height.size();
        int l = 0;
        int r = n-1;
        
        while(l < r){
            int s = (r - l) * min(height[l], height[r]);
            if(mx < s){
                mx = s;
            }
            
            if(height[l] <= height[r]) l++;
            else r--;
        }
        return mx;
    }
};