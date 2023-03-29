/*
Idea , behind the code , is that

   It states that we only change those 'O' to 'X'
   which lies in a region of 'O' where , boundaries are 'X'.
   means , if any 'O' in any region present in boundary of grid then it's one part is surrounded by outside world
   means all 4 boundaries are not equal to 'X'
   so , first we start traversing from these grid boundary nodes and make all their connected nodes equal to 'P' (visited)
   and remaining 'O' which are not in any connection with boundary 'O' , they remain same
   so we make them equal to 'X'
   and at last , we change all 'P' to 'O'
*/

class Solution {
public:

    vector<int> dr = {-1 , 0 , 1 , 0};
    vector<int> dc = {0 , -1 , 0 , 1};
    void dfs(int r , int c , int n , int m , vector<vector<char>>& board){

        for(int i=0;i<4;i++){
            int x = r + dr[i];
            int y = c + dc[i];

            if(x<0 || x>=n || y<0 || y>=m) continue;

            if(board[x][y]=='O'){
                board[x][y] = 'P';
                dfs(x,y,n,m,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
       int n = board.size();
        int m = board[0].size();
        vector<int> temp_i = {0 , n-1};
        vector<int> temp_j = {0 , m-1};
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                board[i][0] = 'P';
                dfs(i , 0 , n , m , board);
            }
            if(board[i][m-1]=='O'){
                board[i][m-1] = 'P';
                dfs(i , m-1 , n , m , board);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                board[0][i] = 'P';
                dfs(0 , i , n , m , board);
            }
            if(board[n-1][i]=='O'){
                board[n-1][i] = 'P';
                dfs(n-1 , i , n , m , board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                if(board[i][j]=='P') board[i][j] = 'O';
            }
        }
        // return board;
    }
};
