class Solution {
public:
    int calculate(string s) {

        stack<int> st;
        int ans = 0;
        int temp = 0;
        int sign = 1;

        for(int i=0;i<s.size();i++){
            if('0' <= s[i] && s[i] <= '9'){
                temp = temp * 10 + (s[i] - '0');
            }
            else if(s[i] == '+'){
                ans += sign * temp;
                temp = 0;
                sign = 1;
            }
            else if(s[i] == '-'){
                ans += sign * temp;
                temp = 0;
                sign = -1;
            }
            else if(s[i] == '('){
                st.push(ans);
                st.push(sign);
                sign = 1;
                ans = 0;
                temp = 0;
            }
            else if(s[i] == ')'){
                ans += sign * temp;
                int lsign = st.top(); st.pop();
                int lans = st.top(); st.pop();
                lans += lsign * ans;
                ans = lans;
                temp = 0;
                sign = 1;
            }
        }

        ans += sign * temp;

        return ans;
    }
};