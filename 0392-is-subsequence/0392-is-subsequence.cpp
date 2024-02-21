class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> m;
        for(int i=0;i<t.size();i++) m[t[i]].push_back(i);
        
        int prev = -1;
        for(char c : s){
            auto it = m.find(c);
            if(it == m.end()) return false;
            vector<int> val = it->second;
            int idx = upper_bound(val.begin(), val.end(), prev) - val.begin();
            if(idx == val.size()) return false;
            prev = val[idx];
        }
        
        return true;
    }
};