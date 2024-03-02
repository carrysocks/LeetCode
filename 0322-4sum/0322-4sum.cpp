class Solution {
    vector<vector<int> > res;
    vector<int> arr;
    void dfs(int depth, int start, int n, int sum, vector<int> num)
    {
        if(depth==3 && sum==0)
        {
            res.push_back(arr);
            return;
        }
        if(depth==3)
        {
            return;
        }
        if(start<n)
        {
            arr[depth]=num[start];
            dfs(depth+1, start+1, n, sum-num[start], num);
            dfs(depth, start+1, n, sum, num);
        }
        return;
    }

public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len=num.size();
        sort(num.begin(),num.end());
        arr.resize(3);
        dfs(0,0,len,target,num);
        vector<vector<int> >::iterator it;
        it=unique(res.begin(),res.end());
        res.resize(distance(res.begin(),it));
        return res;
    }
};
