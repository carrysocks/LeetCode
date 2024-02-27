class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> v(10, 0);
        for(int i=0;i<9;i++){
            for(int k=0;k<10;k++) v[k] = 0;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                int val = (board[i][j] - '0');
                if(v[val] > 0) return false;
                v[val] = 1;
            }
        }
        
        for(int i=0;i<9;i++){
            for(int k=0;k<10;k++) v[k] = 0;
            for(int j=0;j<9;j++){
                if(board[j][i] == '.') continue;
                int val = (board[j][i] - '0');
                if(v[val] > 0) return false;
                v[val] += 1;
            }
        }
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<10;k++) v[k] = 0;
                for(int p=0;p<3;p++){
                    for(int q=0;q<3;q++){
                        int y = i*3 + p;
                        int x = j*3 + q;
                        if(board[y][x] == '.') continue;
                        int val = (board[y][x] - '0');
                        if(v[val] > 0) return false;
                        v[val] += 1;
                    }
                }
            }
        }
        
        return true;
    }
};