#include <cstdio>

using namespace std;

int b[103], t[1003];

int main(){

    int n, w, L;
    scanf("%d %d %d", &n, &w, &L);

    for(int i=1; i<=n; i++){
        scanf("%d", &t[i]);
    }

    int l = 1, c = 0, m = 0;

    while(true){
        m++;
        for(int i=1; i<=w; i++){
            b[i-1] = b[i];
        }
        b[w] = 0;
        c -= t[b[0]];
        if(b[0] == n)break;
        if(c + t[l] <= L){
            c += t[l];
            b[w] = l++;
        }
    }

    printf("%d\n", m);

}
