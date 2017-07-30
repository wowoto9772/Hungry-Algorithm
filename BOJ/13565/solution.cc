#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

char str[1003][1003];
bool chk[1003][1003];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int main(){
    
    int r, c;
    scanf("%d %d", &r, &c);
    
    for(int i=0; i<r; i++){
        scanf("%s", str[i]);
    }
       
    queue < pair<int,int> > q;
    
    for(int i=0; i<c; i++){
        if(str[0][i] == '0'){
            chk[0][i] = true;
            q.emplace(0, i);
        }
    }
        
    while(!q.empty()){
        pair<int,int> e = q.front(); q.pop();
        for(int i=0; i<4; i++){
            pair<int,int> f = {e.first + dr[i], e.second + dc[i]};
            if(f.first < 0 || f.first >= r || f.second < 0 || f.second >= c)continue;
            if(chk[f.first][f.second] || str[f.first][f.second] == '1')continue;
            chk[f.first][f.second] = true;
            q.emplace(f);
        }
    }
    
    bool flag = false;
    for(int i=0; i<c; i++)flag |= chk[r-1][i];
    
    printf("%s\n", (flag) ? "YES" : "NO");

}