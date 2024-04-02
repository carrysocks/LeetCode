class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dp(ans, "", n, 0);
        return ans;
    }

    void dp(vector<string>& ans, string str, int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(str);
            return;
        }

        if(left > 0) dp(ans, str + "(", left - 1, right + 1);
        if(right > 0) dp(ans, str + ")", left, right - 1);
    }
};