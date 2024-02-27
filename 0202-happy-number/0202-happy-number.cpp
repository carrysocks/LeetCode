class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> m;
        
        while(true){
            
            int sum = 0;
            m[n] = 1;
            while(n){
                sum += (n%10)*(n%10);
                n /= 10;
            }
            
            sum += (n % 10) * (n % 10);
            
            if(sum == 1) return true;
            if(m[sum] >= 1) return false;
            n = sum;
        }
        
        return false;
    }
};