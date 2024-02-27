class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int i=0, n=points.size();
        int ans=0;
        while(i<n){
            vector<int> interval = points[i++];
            int r = interval[1];
            while(i<n && r >= points[i][0]){
                interval[0] = min(interval[0], points[i][0]);
                interval[1] = max(interval[1], points[i][1]);
                r = min(r, points[i][1]);
                i++;
            }
            ans++;
        }
        return ans;
    }
};