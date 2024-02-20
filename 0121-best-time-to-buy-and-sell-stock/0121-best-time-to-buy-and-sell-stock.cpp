class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx_profit = 0;
        int mn_stock = 1e9;
            
        for(int i=0;i<prices.size();i++){
            if(mn_stock >= prices[i]){
                mn_stock = prices[i];
            }
            else{
                int profit = prices[i] - mn_stock;
                if(mx_profit < profit) mx_profit = profit;
            }
        }
        
        return mx_profit;
    }
};