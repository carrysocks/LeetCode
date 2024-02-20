class Solution {
public:
    int recur(int idx, int buy, vector<int>& prices){
        if(idx == prices.size()) return 0;
        int profit = 0;
        
        if(buy){
            int sell = prices[idx] + recur(idx+1, 0, prices);
            int pass = recur(idx+1, 1, prices);
            profit = max(sell, pass);
        }
        else{
            int cur_buy = -prices[idx] + recur(idx+1, 1, prices);
            int pass = recur(idx+1, 0, prices);
            profit = max(cur_buy, pass);
        }
        
        return profit;
    }
    
    //memoization
    int recur_mem(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx == prices.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        
        if(buy){
            int sell = prices[idx] + recur_mem(idx+1, 0, prices, dp);
            int pass = recur_mem(idx+1, 1, prices, dp);
            profit = max(sell, pass);
        }
        else{
            int cur_buy = -prices[idx] + recur_mem(idx+1, 1, prices, dp);
            int pass = recur_mem(idx+1, 0, prices, dp);
            profit = max(cur_buy, pass);
        }
        
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return recur_mem(0, 0, prices, dp);
    }
};


// recursive 
// if buy state, sell or pass
// if not buy state, buy or pass
// memoization
// dp[idx][buy] = max of profit 