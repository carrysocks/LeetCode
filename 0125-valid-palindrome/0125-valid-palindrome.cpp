class Solution {
public:    
    bool isPalindrome(string s) {
        string str = "";
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if('a' <= c && c <= 'z') str += c;
            else if('A' <= c && c <= 'Z') str += tolower(c);
            else if('0' <= c && c <='9') str += c;
        }
        
        int n = str.size();
        for(int i=0;i<n/2;i++){
            if(str[i] != str[n-1-i]) return false;
        }
        
        return true;
    }
};