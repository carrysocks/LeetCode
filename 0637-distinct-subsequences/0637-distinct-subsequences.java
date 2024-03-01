public class Solution {
    public int numDistinct(String S, String T) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        int [] cnt = new int[T.length()+1];
        
        
        for(int j = 0; j <= T.length(); j++){
            cnt[j] = 0;
        }
        /*
        for(int i = 0; i <= S.length(); i++){
            cnt[i][0] = 1;
        }
        */
        cnt[0] = 1;
        
        for(int i = 0; i < S.length(); i++){
            for(int j = T.length(); j >= 0; j++){
                //cnt[i+1][j+1] = cnt[i][j+1];
                if(S.charAt(i) == T.charAt(j)){
                    cnt[j+1] += cnt[j];
                }
            }
        }
        
        return cnt[T.length()];
    }
}