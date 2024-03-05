class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ans = "";

        while(i >= 0 || j >= 0 || carry){
            int cur = (i >= 0 ? a[i] - '0' : 0) 
                    + (j >= 0 ? b[j] - '0' : 0)
                    + carry;
            i--; j--;
            if(cur < 2){
                ans += to_string(cur);
                carry = 0;
            }
            else{
                ans += to_string(cur - 2);
                carry = 1;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};