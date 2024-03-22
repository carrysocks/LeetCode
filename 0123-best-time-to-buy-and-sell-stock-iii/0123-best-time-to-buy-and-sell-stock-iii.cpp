class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int mn_price1 = prices[0];
        int mn_price2 = prices[0];
        int mx_profit1 = 0;
        int mx_profit2 = 0;

        for(int i=1;i<n;i++){
            mn_price1 = min(mn_price1, prices[i]);
            mx_profit1 = max(mx_profit1, prices[i] - mn_price1);

            mn_price2 = min(mn_price2, prices[i] - mx_profit1);
            mx_profit2 = max(mx_profit2, prices[i] - mn_price2);
        }

        return mx_profit2;
    }
};