class Solution {
public:
    int romanToInt(string s) {
        map<string, int> m;
        
        m["I"] = 1;
        m["V"] = 5;
        m["X"] = 10;
        m["L"] = 50;
        m["C"] = 100;
        m["D"] = 500;
        m["M"] = 1000;
        
        m["IV"] = 4; m["IX"] = 9;
        m["XL"] = 40; m["XC"] = 90;
        m["CD"] = 400; m["CM"] = 900;
        
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(i != s.size()-1 && m[s.substr(i, 2)] != 0){
                 ans += m[s.substr(i,2)];
                 i++;
            }
            else{
                ans += m[s.substr(i,1)];
            }
        }
        
        return ans;
    }
};