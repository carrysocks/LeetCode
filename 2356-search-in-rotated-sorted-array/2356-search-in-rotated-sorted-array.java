public class Solution {
    public int search(int[] A, int target) {
        int lo = 0;
        int hi = A.length-1;
        int mid;
        while (lo < hi) {
            mid = lo + (hi-lo)/2;
            if (A[mid] == target) return mid;
            if (A[mid] > A[lo]) {
                if (target < A[mid] && target >= A[lo])
                    hi = mid-1;
                else
                    lo = mid+1;
            } else {
                if (target > A[mid] && target <= A[hi])
                    lo = mid+1;
                else
                    hi = mid-1;
            }
        }
        return A[lo] == target ? 1 : -1;
    }
}