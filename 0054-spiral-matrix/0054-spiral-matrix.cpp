class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), y = 0, x = 0, dir = 1;
        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, 1, 0, -1};
        int visited[101][101] = {{0}};
        vector<int> ans;
        
        while(ans.size() < n*m){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            ans.push_back(matrix[y][x]);
            visited[y][x] = 1;
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]){
                dir = (dir + 1) % 4;
                ny = y + dy[dir];
                nx = x + dx[dir];
            }
            
            y = ny, x = nx;
        }
        
        return ans;
    }
};