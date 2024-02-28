class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!n ) return n;
        int left=0,right=0;
        while(right<n){
            if(A[right]!=elem){
                A[left++]= A[right];
            }else{
                right++;
            }
        }
        
        return left+1;
        
    }
};