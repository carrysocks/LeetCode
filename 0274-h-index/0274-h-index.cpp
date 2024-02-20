class Solution {
public:
    int hIndex(vector<int>& citations) {
        // check h 1 -> 1000 
        // check n times for each iteration
        // O ( 1000 * 5000 )
        int mx_h = 0;
        int mx = -1;
        for(int i=0;i<citations.size();i++){
            mx = max(mx, citations[i]);
        }
        
        for(int h=1;h<=1000;h++){
            
            if(h > mx) break;
            int temp = 0;
            for(int i=0;i<citations.size();i++){
                if(citations[i] >= h) temp++;
            }
            
            if(temp >= h) mx_h = h;
        }
        
        return mx_h;
    }
};