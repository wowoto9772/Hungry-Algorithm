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

        int v;
        scanf("%d", &v);

        printf("%d %d\n", v, cnt(v));

    }

}
