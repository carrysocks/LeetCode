class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        for(auto digit : digits) ans.push_back(digit);
        int n = ans.size();
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            if(ans[i] + carry >= 10){
                ans[i] = 0;
                carry = 1;
            }
            else{
                ans[i] += carry;
                carry = 0;
                break;
            }
        }

        if(carry) ans.insert(ans.begin(), 1);
        return ans;
    }
};