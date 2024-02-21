class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> num(n, 1);
        
        if(n == 1) return 1;
        
        for(int i=0;i<n-1;i++){
            if(ratings[i] < ratings[i+1]){
                num[i+1] = num[i] + 1;
            }
        }
        
        for(int i=n-1;i>0;i--){
            if(ratings[i-1] > ratings[i]){
                num[i-1] = max(num[i-1], num[i]+1);
            }
        }
       
        int ans = 0;
        for(int k : num) ans += k;
        return ans;
    }
};

    