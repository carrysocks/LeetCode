class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0, mx = 0, n = s.size(), len = 0; 
        string temp = "";
        
        
        while(r < n){
            size_t pos = temp.find(s[r]);
            temp += s[r++];
            len++;
            if(pos == string::npos){
                mx = max(mx, len);
                continue;
            }
            
            temp = temp.substr(pos+1);
            len -= (pos+1);
            mx = max(mx, len);
        }
        
        return mx;
    }
};