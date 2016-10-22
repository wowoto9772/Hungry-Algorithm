#include <cstdio>

using namespace std;

int cnt(int v){

    int ret = 1;

    for(int i=2; i*i <= v; i++){
        if(v%i)continue;
        int c = 0;
        while(!(v%i)){
            v /= i;
            c++;
        }
        ret *= (++c);
    }

    if(v != 1)ret <<= 1;

    return ret;

}

int main(){

    int n;
    scanf("%d", &n);

    while(n--){

        int l, r;
        scanf("%d %d", &l, &r);

        int c = 0;

        for(int i=l; i<=r; i++){
            int d = cnt(i);
            if(c < d)c = d;
        }

        printf("%d\n", c);

    }

}
