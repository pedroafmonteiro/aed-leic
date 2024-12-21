#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int R, C;
        cin >> R >> C;
        vector<string> maze(R);
        int startX, startY, endX, endY;
        for(int i=0;i<R;i++){
            cin >> maze[i];
            for(int j=0;j<C;j++) {
                if(maze[i][j]=='P'){ startX=i; startY=j;}
                if(maze[i][j]=='T'){ endX=i; endY=j;}
            }
        }
        vector<vector<int>> moves(R, vector<int>(C, -1));
        queue<pair<int, int>> q;
        q.push({startX, startY});
        moves[startX][startY]=0;
        int dirs[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(auto dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(nx >=0 && nx <R && ny >=0 && ny <C && maze[nx][ny]!='#' && moves[nx][ny]==-1){
                    moves[nx][ny] = moves[x][y] +1;
                    q.push({nx, ny});
                    if(nx == endX && ny == endY){
                        break;
                    }
                }
            }
        }
        cout << moves[endX][endY] << "\n";
    }
}