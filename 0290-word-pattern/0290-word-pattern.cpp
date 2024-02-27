class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        string token;
        vector<string> tokens;
        while(getline(iss, token, ' ')) tokens.push_back(token);

        unordered_map<char,int> m1;
        unordered_map<string,int> m2;
        if(pattern.size() != tokens.size()) return false;
        for(int i=0;i<pattern.size();i++){
            if(m1[pattern[i]] != m2[tokens[i]]) return false;
            m1[pattern[i]] = m2[tokens[i]] = i+1;
        }
        return true;
    }
};