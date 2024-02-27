class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> tv(26, 0);
        
        if(s.size()!=t.size()) return false;
        for(int i=0;i<t.size();i++) tv[(t[i]-'a')]++;
        for(int i=0;i<s.size();i++) if(tv[(s[i])-'a']-- <= 0) return false;
        return true;
    }
};