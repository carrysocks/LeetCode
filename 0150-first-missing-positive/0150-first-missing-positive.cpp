class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=0; i<n;){
            if(A[i]>0 && A[i]<n && A[A[i]]!=A[i]){
                swap(A[A[i]], A[i]);
            }else{
                i++;
            }
        }
        int k=1;
        while(k<n && A[k]==k)
            k++;
        if(A[0]==k)
            return k+1;
        else
            return k;
    }
};