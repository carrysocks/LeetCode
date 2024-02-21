class Solution {
public:
    string split(string s, char delimeter){
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);

        while(getline(tokenStream, token, delimeter)){
            tokens.push_back(token);
        }
        
        for(int i=0;i<tokens.size();i++){
            cout << " i : " << i << ' ' << tokens[i] << endl;
        }
        return tokens[tokens.size()-1]; 
    }
    
    int lengthOfLastWord(string s) {
        size_t first_not_space = s.find_first_not_of(' ');
        size_t last_not_space = s.find_last_not_of(' ');
        size_t i = s.find('n');
        
        s = s.substr(first_not_space, last_not_space - first_not_space + 1);
        return split(s, ' ').size();
    }
};