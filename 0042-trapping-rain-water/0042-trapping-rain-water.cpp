class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // maximum height for each index
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        int mx_left = 0;
        int mx_right = 0;
        for(int i=0;i<n;i++){
            if(mx_left < height[i]) mx_left = height[i];
            left[i] = mx_left;
        }
        
        for(int i=n-1;i>=0;i--){
            if(mx_right < height[i]) mx_right = height[i];
            right[i] = mx_right;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans + min(left[i], right[i]) - height[i];
        }
        
        return ans;
    }
};