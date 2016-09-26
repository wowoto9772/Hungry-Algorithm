#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

char str[1000003];
int a[1000003], b[1000003];

int main(){

    int n;
    scanf("%d", &n);

    scanf("%s", str+1);

    for(int i=1; i<=n; i++){
        if(str[i] == 'A'){
            a[i] = a[i-1];
            b[i] = 1 + min(a[i-1], b[i-1]);
        }else{
            b[i] = b[i-1];
            a[i] = 1 + min(a[i-1], b[i-1]);
        }
    }

    printf("%d\n", a[n]);

}
