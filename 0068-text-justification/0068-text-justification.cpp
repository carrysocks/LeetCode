class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int line_length = 0, word_length = 0;
        int num = 0;
        vector<string> temp;
        vector<string> ans;
        string tmp = "";
        
        for(int w=0;w<words.size();w++){
            string word = words[w];
            if(line_length != 0 && line_length + 1 + word.size() > maxWidth){                
                int blank_length = maxWidth - word_length;
                int base = (num == 1 ? blank_length : blank_length / (num - 1));
                int r = (num == 1 ? 0 : blank_length % (num-1));
                int idx = 0;
                
                for(int i=0;i<num;i++){
                    if(i != 0 && i == num-1){
                        tmp += temp[i];
                    }
                    else{
                        tmp += temp[i];
                        int d = (i < r ? base + 1 : base); 
                        string spaces = "";
                        for(int l=0;l<d;l++) spaces += " ";
                        tmp += spaces;
                    }
                }
                
                ans.push_back(tmp);
                
                temp.clear();
                num = 0;
                line_length = 0;
                word_length = 0;
                tmp = "";
            }
            
            temp.push_back(word);
            if(line_length == 0) line_length -= 1;
            line_length += word.size() + 1;
            word_length += word.size();
            num += 1;
        }
        
        if(temp.size() > 0){
            for(int i=0;i<temp.size();i++){
                if(i != 0) tmp += " ";
                tmp += temp[i];
            }
            
            for(int i=tmp.size();i<maxWidth;i++){
                tmp += " ";
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};