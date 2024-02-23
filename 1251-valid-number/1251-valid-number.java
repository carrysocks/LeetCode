public class Solution {
    public boolean isNumber(String s) {
        s.replaceAll("\\s", "");
        int n = s.length();
        if(n == 0) return false;
        char tmp;
        for(int i = 0; i < n ; i++){
            tmp = s.charAt(i);
            if(tmp == '.' || tmp == 'e' || tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '%'){
                return isNumber(s.substring(0, i)) & isNumber(s.substring(i+1));
            }else if(!(tmp >= '0' && tmp <= '9')) return false;
        }
        return true;
    }
}