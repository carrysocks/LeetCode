class Solution {
public:
    string minWindow(string s, string t) {
        int ms = s.size(), n = t.size(), count = 0;
        
        unordered_map<char, int> m;
        unordered_map<char, int> tmp_m;
        
        for(auto c : t){
            m[c] += 1;
            count++;
        }
        
        if(s == t) return s;
        
        int l = 0, r = 0, cnt = 0;
        int mn = 1e9, ml = 0, mr = 0;
        while(r < ms){
            char c = s[r];
            if(m.find(c) != m.end()){
                
                if(tmp_m[c] + 1 <= m[c]) cnt++;
                tmp_m[c] += 1;
                
                while((m.find(s[l]) == m.end()) || (tmp_m[s[l]] > m[s[l]])){
                    if(r == 0) break;
                    if(m.find(s[l]) != m.end()) tmp_m[s[l]] -= 1;
                    l++;
                }
                
                if(cnt >= count && mn > (r - l + 1)){
                    mn = r - l + 1;
                    ml = l;
                    mr = r;
                }
            }
            r++;
            
        }
        
        if(mn == 1e9) return "";
        return s.substr(ml, mn);
    }
};