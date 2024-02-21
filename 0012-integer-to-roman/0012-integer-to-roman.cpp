class Solution {
public:
    string intToRoman(int num) {
        vector<int> Value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> Symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        int idx = 0;
        string ans = "";
        while(num){
            if(num >= Value[idx]){
                ans += Symbol[idx];
                num -= Value[idx];
            }
            else{
                idx++;
            }
        }
        
        return ans;
    }
};