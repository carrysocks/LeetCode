class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,int> visited;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end() && visited[t[i]]++ < 1) m[s[i]]=t[i];
            else if(m[s[i]] != t[i]) return false;
        }
        return true;
    }
};