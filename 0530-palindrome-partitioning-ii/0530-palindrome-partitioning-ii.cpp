class Solution {
public:
    int doCount(char* s,int i,int n)
    {
       static int count=0;
       if(i<n)
       {
         if(s[i]!=s[n])
           count++;
        doCount(s,++i,--n);
       }
        return count;
    }
    int minCut(string s)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char *c = new char[s.length() + 1];
        strcpy(c,s.c_str());
        return doCount(c,0,strlen(c)-1;
        
    }
};