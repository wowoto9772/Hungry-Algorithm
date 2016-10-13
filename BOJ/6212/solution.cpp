#include <cstdio>

using namespace std;

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    int c[10] = {};

    for(int i=a; i<=b; i++){
        int v = i;
        while(v){
            c[v%10]++;
            v /= 10;
        }
    }

    for(int i=0; i<10; i++)printf("%d ", c[i]);

}
