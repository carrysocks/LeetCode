class Solution {
public:
    vector<vector<int>> ans;
    void backtracking(vector<int>& val, int start, int n, int cnt, int k){
        if(cnt == k){
            ans.push_back(val);
            return;
        }

        for(int i=start;i<=n;i++){
            val.push_back(i);
            backtracking(val, i+1, n, cnt+1, k);
            val.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtracking(temp, 1, n, 0, k);
        return ans;
    }
};