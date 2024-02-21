class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int idx=0;idx<strs[0].size();idx++){
            
            for(int i=1;i<strs.size();i++){
                if(idx >= strs[i].size()){
                    return ans;
                }
                else if(strs[0][idx] != strs[i][idx]){
                    return ans;
                }
            }
            
            ans += strs[0][idx];
        }
        
        return ans;
    }
};