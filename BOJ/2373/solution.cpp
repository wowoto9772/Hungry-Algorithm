#include <cstdio>

using namespace std;

int p[100] = {1, 1, 2};

int func(int n, int c){

    if(n < p[c])return func(n, c-1);
    else if(n == p[c])return n;
    else
        return func(n-p[c], c-1);

}

int main(){

    int top = 0;

    for(int i=3;;i++){
        p[i] = p[i-1] + p[i-2];
        top = i;
        if(p[i] > 1000000)break;
    }

    // fibonacci number start, lose

    int n;
    scanf("%d", &n);

    int flg = func(n, top);

    if(flg == n)flg = -1;
    printf("%d\n", flg);

}
