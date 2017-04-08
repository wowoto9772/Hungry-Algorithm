#include <cstdio>
#include <algorithm>

using namespace std;

int e[23][23];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &e[i][j]);
        }
    }

    int ans = 0;

    for(int i=0; i<4*4*4*4*4; i++){
        int f[23][23] = {};
        for(int a=0; a<n; a++)for(int b=0; b<n; b++)f[a][b] = e[a][b];
        int v = i;
        for(int j=0; j<5; j++){
            int x = v % 4;
            v >>= 2;
            int g[23][23] = {};
            for(int a=0; a<n; a++)for(int b=0; b<n; b++)g[a][b] = f[a][b];
            if(x == 0){
                for(int a=0; a<n; a++){
                    for(int b=0; b<n-1; b++){
                        if(g[a][b] == 0){
                            bool swp = false;
                            for(int c=b+1; c<n; c++){
                                if(g[a][c]){
                                    swap(g[a][b], g[a][c]);
                                    swp = true;
                                    break;
                                }
                            }
                            if(swp)b--;
                        }else{
                            for(int c=b+1; c<n; c++){
                                if(g[a][c]){
                                    if(g[a][c] == g[a][b]){
                                        g[a][b] += g[a][c];
                                        g[a][c] = 0;
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }else if(x == 1){
                for(int a=0; a<n; a++){
                    for(int b=n-1; b>0; b--){
                        if(g[a][b] == 0){
                            bool swp = false;
                            for(int c=b-1; c>=0; c--){
                                if(g[a][c]){
                                    swap(g[a][b], g[a][c]);
                                    swp = true;
                                    break;
                                }
                            }
                            if(swp)b++;
                        }else{
                            for(int c=b-1; c>=0; c--){
                                if(g[a][c]){
                                    if(g[a][c] == g[a][b]){
                                        g[a][b] += g[a][c];
                                        g[a][c] = 0;
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }else if(x == 2){
                for(int a=0; a<n; a++){
                    for(int b=0; b<n-1; b++){
                        if(g[b][a] == 0){
                            bool swp = false;
                            for(int c=b+1; c<n; c++){
                                if(g[c][a]){
                                    swap(g[b][a], g[c][a]);
                                    swp = true;
                                    break;
                                }
                            }
                            if(swp)b--;
                        }else{
                            for(int c=b+1; c<n; c++){
                                if(g[c][a]){
                                    if(g[c][a] == g[b][a]){
                                        g[b][a] += g[c][a];
                                        g[c][a] = 0;
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }else{
                for(int a=0; a<n; a++){
                    for(int b=n-1; b>0; b--){
                        if(g[b][a] == 0){
                            bool swp = false;
                            for(int c=b-1; c>=0; c--){
                                if(g[c][a]){
                                    swap(g[b][a], g[c][a]);
                                    swp = true;
                                    break;
                                }
                            }
                            if(swp)b++;
                        }else{
                            for(int c=b-1; c>=0; c--){
                                if(g[c][a]){
                                    if(g[c][a] == g[b][a]){
                                        g[b][a] += g[c][a];
                                        g[c][a] = 0;
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            for(int a=0; a<n; a++)for(int b=0; b<n; b++)f[a][b] = g[a][b];
        }
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                ans = max(ans, f[a][b]);
            }
        }
    }
    printf("%d\n", ans);

}
