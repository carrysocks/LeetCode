class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0, counter = t.size(), min_start = 0, min_len = INT_MAX;
        
        vector<int> m(128, 0);
        
        for(auto c : t) m[c]++;
        
        while(end < s.size()){
            if(m[s[end]] > 0) counter--;
            m[s[end]]--;
            end++;
            
            while(counter == 0){
                if(end - start < min_len){
                    min_start = start;
                    min_len = end - start;
                }
                
                m[s[start]]++;
                if(m[s[start]] > 0) counter++;
                start++;
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};