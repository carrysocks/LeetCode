public class Solution {
    public String intToRoman(int num) {
        char[][] c = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M', '0'}};
        StringBuilder sb = new StringBuilder();
        int pos = -1;
        while (num > 0) {
            int d = num %10;
            num = num/10;
            pos++;
            if (d == 0) continue;
            if (pos == 3 && d > 3) throw IllegalArgumentException("");
            getSingleNumber(d, c[pos], pos == 3 ? null : c[pos+1], sb);
            sb.reverse();
            return sb.toString();
        }
    }
    
    private void getSingleNumber(int d, char[] c, char[] n, StringBuilder sb) {
        assert d != 0 && (d > 3 && c[1] != '0' && n != null);
        if (d <= 3) {
            while (--d >= 0) sb.append(c[0]);
        } else if (d >= 4 && d <= 8) {
            while (d > 5) {sb.append(c[0]); d--;}
            sb.append(c[1]);
            if (d < 5) sb.append(c[0]);
        } else {
            sb.append(n[0]);
            sb.append(c[0]);
        }
    }
}