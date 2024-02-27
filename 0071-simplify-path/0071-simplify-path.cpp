class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string temp = "", ans = "";
        for(int i=0;i<path.size();i++){
            char c = path[i];
            if(c == '/') continue;

            while(i < path.size() && path[i] != '/'){
                temp += path[i++];
            }

            if(temp == ".") continue;
            else if(temp == ".."){
                if(!s.empty()) s.pop();
            }
            else s.push(temp);
            temp = "";
        }

        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }

        if(ans.size() == 0) return "/";
        return ans;
    }
};