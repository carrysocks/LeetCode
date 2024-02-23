class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // O ( (10000 - 5000) * 5000 )
        
        int len = words[0].size();
        int full_len = words.size() * len; 
        map<string, int> m;
        vector<int> ans;
        
        for(int i=0;i<words.size();i++){
            m[words[i]] += 1;
        }
        
        for(int i=0;i<len;i++){
            map<string, int> temp_map;
            int l = i, cnt = 0;
            
            for(int r=i;r+len<=s.size();r+=len){
                string word = s.substr(r, len);
                
                if(m.find(word) != m.end()){
                    temp_map[word]++;
                    cnt++;
                    
                    while(temp_map[word] > m[word]){
                        string left_word = s.substr(l, len);
                        temp_map[left_word]--;
                        cnt--;
                        l += len;
                    }
                    
                    if(cnt == words.size()){
                        ans.push_back(l);
                        string left_word = s.substr(l, len);
                        temp_map[left_word]--;
                        cnt--;
                        l += len;
                    }
                }
                else{
                    temp_map.clear();
                    cnt = 0;
                    l = r + len;
                }
            }
            
            
        }
        
        return ans;
    }
};
