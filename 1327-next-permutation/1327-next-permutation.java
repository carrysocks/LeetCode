public class Solution {
    public void nextPermutation(int[] num) {
        for (int i = num.length-1; i>0; i--){
            if (num[i] > num[i-1]){
                // switch i-1 and a slightly bigger one
                // NOT switch i and i-1 !!!
                switchWithBigger(num, i-1);
                // then sort i -> length-1
                reverse(num, i, num.length-1);
                return;
            }
        }
        // i =0
        reverse(num, 0, num.length-1);
        
    }
    public static void switchWithBigger(int[]a, int i){
        int switchPosition = i+1;
        int delta = Integer.MAX_VALUE;
        for (int j = a.length-1; j>i; j--){
            if (a[j]> a[i]&& (a[j]-a[i])<delta){
                switchPosition = j;
                delta = a[j]-a[i];
            }
        }
        swap(a, switchPosition,i );
    }
    private void swap( int[] num, int j, int k )
    {
        int temp = num[j];
        num[j] = num[k];
        num[k] = temp ;
    }
    private void reverse( int[] num, int j, int k)
    {
        while(j<k)
        {
            swap(num,j,k );
            j++;k--;
        }
    }


}