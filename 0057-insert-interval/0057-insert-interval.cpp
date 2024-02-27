class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i;
        vector<vector<int>> ans;
        for(i=0;i<n;i++){
            if(intervals[i][1] < newInterval[0]) ans.push_back(intervals[i]);
            else break;
        }
        
        for(;i<n;i++){
            if(newInterval[1] < intervals[i][0]) break;
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        
        ans.push_back(newInterval);
        
        for(;i<n;i++) ans.push_back(intervals[i]);
        
        return ans;
    }
};