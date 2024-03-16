public class Solution {
    public int largestRectangleArea(int[] height) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int l = 0;
        int r = height.length-1;
        if(r == -1)
            return 0;
        int max_size = Math.min(height[l], height[r])*(r - l+1);
        while(l <= r){
            if(height[l] < height[r]){
                int tmp = height[l];
                while(l <= r && height[l] <= tmp)
                    l++;
                if(l > r)
                    break;
                tmp = Math.min(height[l], height[r])*(r - l +1);
                max_size = Math.max(max_size, tmp);
            } else{
                int tmp = height[r];
                while(l <= r && height[r] <= tmp)
                    r--;
                if(l > r)
                    break;
                tmp = Math.min(height[l], height[r])*(r - l+1);
                max_size = Math.max(max_size, tmp);
            }
        }
        return max_size;
    }
}