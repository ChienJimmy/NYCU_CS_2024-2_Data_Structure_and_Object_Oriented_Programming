#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> maze(H, vector<char>(W));
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> walkable(H, vector<int>(W));
    if (maze[0][0] == '#') {
        cout << "No\n";
        return 0;
    }

    walkable[0][0] = 1;
    for (int p = 0; p < H+W-1; p++){
        for (int i = p-W+1; i < H;i++){
            int j = p-i;
            if (j >= 0 && j < W && i >= 0 && i < H) {
                if (maze[i][j] == '#') {
                    walkable[i][j] = 0;
                } else {
                    if (i > 0) walkable[i][j] += walkable[i-1][j];
                    if (j > 0) walkable[i][j] += walkable[i][j-1];
                }
            }
        }
    }
    /*
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cout << walkable[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << ((walkable[H-1][W-1] != 0) ? "YES\n" : "NO\n");
    
    
    return 0;
}