class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // O ( 6 * N (2 * 10^4)) -> O(N)
        
        int n = tops.size();
        int ans = 1e9;
        for(int i=1;i<=6;i++){
            int cnt_top = 0;
            int cnt_bottom = 0;
            bool non_top = false;
            bool non_bottom = false;
            for(int j=0;j<n;j++){
                if(tops[j] != i){
                    if(bottoms[j] == i) cnt_top++;
                    else non_top = true;
                }
                
                if(bottoms[j] != i){
                    if(tops[j] == i) cnt_bottom++;
                    else non_bottom = true;
                }
            }
            
            if(!non_top) ans = min(ans, cnt_top);
            if(!non_bottom) ans = min(ans, cnt_bottom);
        }
        
        if(ans == 1e9) return -1;
        return ans;
    }
};