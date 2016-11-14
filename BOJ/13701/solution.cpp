#include <cstdio>

using namespace std;

unsigned int exist[1200003];

int main(){

    int n;
    while(scanf("%d", &n) == 1){
        unsigned i = n>>5;
        unsigned v = 1<<(n%32);
        if((exist[i] & v) == v)continue;
        exist[i] |= v;
        printf("%d ", n);
    }

}
