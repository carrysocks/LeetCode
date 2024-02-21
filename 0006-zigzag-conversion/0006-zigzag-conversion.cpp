class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> adj[1001];
        
        int n = s.size();
        
        if(numRows == 1) return s;
        
        for(int i=0;i<n;i+=(2*numRows-2)){
            
            for(int j=0;j<numRows;j++){
                if(i+j >= n) break;
                adj[j].push_back(s[i+j]);
            }
            for(int j=0;j<numRows-2;j++){
                if(i+numRows+j >= n) break;
                adj[numRows-j-2].push_back(s[i+numRows+j]);
            }
        }
        
        string ans = "";
        for(int i=0;i<numRows;i++){
            for(auto j : adj[i]) ans += j;
        }
            
        return ans;
    }
};