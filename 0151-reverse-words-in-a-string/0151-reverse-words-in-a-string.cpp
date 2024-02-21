class Solution {
public:
     string split(string s, char delimeter){
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        
        while(tokenStream >> token){
            tokens.insert(tokens.begin(), token);
        }
        
        string ans = "";
        for(int i=0;i<tokens.size();i++){
            if(i == 0) ans += tokens[i];
            else{
                ans += " ";
                ans += tokens[i];
            }
        }
        
        return ans;
    }
    
    string reverseWords(string s) {
        return split(s, ' ');
    }
};