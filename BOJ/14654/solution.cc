#include <cstdio>

using namespace std;

int x[303], y[303];
int winner(int x, int y){
    if(x == y)return 0;
    if(x == 1){
        if(y == 2)return 1;
        else
            return -1;
    }else if(x == 2){
        if(y == 1)return -1;
        else
            return 1;
    }else if(x == 3){
        if(y == 1)return 1;
        else
            return -1;
    }
}

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)scanf("%d", &x[i]);
    for(int i=0; i<n; i++)scanf("%d", &y[i]);

    int ans = 0;
    int le = 0, ri = 0;
    int l = 0, r = 0;
    for(int i=0; i<n; i++){
        int z = winner(x[i], y[i]);
        if(z == 0){
            if(ri == 0)ri++, le = 0;
            else
                le++, ri = 0;
        }else{
            if(z == -1)le++, ri = 0;
            else
                ri++, le = 0;
        }
        if(ans < le)ans = le;
        if(ans < ri)ans = ri;
    }

    printf("%d\n", ans);

}
