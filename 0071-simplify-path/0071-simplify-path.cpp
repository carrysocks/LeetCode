class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        bool isSlash = false;
        string temp = "";
        for(int i=0;i<path.size();i++){
            char c = path[i];
            if(c == '/'){
                if(isSlash && temp != "" && temp != "."){
                    if(temp == ".." && !s.empty()) s.pop();  
                    else if(temp != "..") s.push(temp);
                }
                isSlash = true;
                temp = "";
            }
            else temp += c;
        }

        if(temp != "" && temp != "."){
            if(temp == ".." && !s.empty()) s.pop();
            else if(temp != "..") s.push(temp);
        }

        string ans = "";
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }

        if(ans == "") return "/";
        return ans;
    }
};