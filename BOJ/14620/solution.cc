#include <cstdio>
#include <algorithm>

using namespace std;

int dr[] = {1, -1, 0, 0, 0};
int dc[] = {0, 0, -1, 1, 0};
int c[13][13];

bool outLine(int v, int n){
    int x = v/n, y = v%n;
    for(int i=0; i<4; i++){
        int a = x+dr[i], b = y+dc[i];
        if(a < 0 || a >= n || b < 0 || b >= n)return true;
    }
    return false;
}


int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &c[i][j]);
        }
    }
    
    int ans = 200 * 5 * 3;
        
    for(int i=0; i<n*n; i++){
        if(outLine(i, n))continue;
        for(int j=i+1; j<n*n; j++){
            if(outLine(j, n))continue;
            for(int k=j+1; k<n*n; k++){
                if(outLine(k, n))continue;
                int x[] = {i/n, j/n, k/n};
                int y[] = {i%n, j%n, k%n};
                bool flag = false;
                for(int a=0; a<3; a++){
                    for(int b=a+1; b<3; b++){
                        if(abs(x[a] - x[b]) + abs(y[a] - y[b]) <= 2)flag = true;
                    }
                }
                if(!flag){
                    int tmp = 0;
                    for(int a=0; a<3; a++){
                        for(int b=0; b<5; b++){
                            tmp += c[x[a]+dr[b]][y[a]+dc[b]];
                        }
                    }
                    if(ans > tmp)ans = tmp;
                }
            }
        }
    }
    
    printf("%d\n", ans);
    
}