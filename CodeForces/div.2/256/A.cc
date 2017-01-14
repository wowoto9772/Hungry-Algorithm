#include <cstdio>

using namespace std;

int cnt(int v, int c){
    return (v / c) + (((v%c) > 0) ? 1 : 0);
}

int a[3], b[3];

int main(){

    for(int i=0; i<3; i++)scanf("%d", &a[i]);
    for(int i=0; i<3; i++)scanf("%d", &b[i]);

    int n;
    scanf("%d", &n);

    a[0] += a[1] + a[2];
    b[0] += b[1] + b[2];

    if(cnt(a[0], 5) + cnt(b[0], 10) <= n)printf("YES\n");
    else
        printf("NO\n");

}
