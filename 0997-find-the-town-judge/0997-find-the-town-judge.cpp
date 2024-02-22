class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // trust, trusted count
        vector<pair<int,int>> v(n+1, {0,0});
        for(int i=0;i<trust.size();i++){
            int a = trust[i][0];
            int b = trust[i][1];
            v[a].first += 1;
            v[b].second += 1;
        }
        
        for(int i=1;i<=n;i++){
            if(v[i].first == 0 && v[i].second == (n-1)) return i;
        }
        
        return -1;
    }
};