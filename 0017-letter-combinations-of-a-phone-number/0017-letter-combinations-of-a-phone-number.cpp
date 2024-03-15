class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> words = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> ans;
        
        if(digits == "") return ans;
        ans.push_back("");
        for(auto digit : digits){
            
            vector<string> temp;
            for(auto c : words[digit - '0']){
                for(auto str : ans){
                    temp.push_back(str + c);
                }
            }
            
            ans.swap(temp);
        }
        
        return ans;
    }
};