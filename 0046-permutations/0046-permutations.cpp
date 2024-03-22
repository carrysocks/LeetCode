class Solution {
public:
    vector<vector<int>> ans;

    void permutation(vector<int>& nums, vector<int>& temp, vector<int>& visited, int start, int n){
        if(start == n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            visited[i] = 1;
            temp.push_back(nums[i]);
            permutation(nums, temp, visited, start+1, n);
            temp.pop_back();
            visited[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<int> visited(n, 0);
        permutation(nums, temp, visited, 0, n);

        return ans;
    }
};