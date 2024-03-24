class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            if(s.empty() || s.top().first >= temperatures[i]) s.push({temperatures[i], i});
            else{
                while(!s.empty() && s.top().first < temperatures[i]){
                    int idx = s.top().second;
                    ans[idx] = i - idx;
                    s.pop();
                }

                s.push({temperatures[i], i});
            }
        }

        return ans;
    }
};