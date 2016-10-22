#include <cstdio>

using namespace std;

int s[100003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &s[i]);
        if(i)s[i] += s[i-1];
    }

    int q;
    scanf("%d", &q);

    while(q--){
        int l, r;
        scanf("%d %d\n", &l, &r);

        int c = s[r];
        if(l)c -= s[l-1];

        printf("%d\n", c);
    }

}
