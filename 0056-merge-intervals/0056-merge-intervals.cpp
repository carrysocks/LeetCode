class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i=0;i<n;i++){
            int j=i;
            int l = intervals[i][0];
            int a = intervals[i][1], r = intervals[i][1];
            while(j+1<n){
                int b = intervals[j+1][0];
                int c = intervals[j+1][1];
                if(a < b) break;
                else if(a >= b && a < c){
                    j++;
                    a = c;
                    r = c;
                }
                else{
                    j++;
                    r = a;
                }
            }

            i=j;
            ans.push_back({l, r});
        }
        return ans;
    }
};