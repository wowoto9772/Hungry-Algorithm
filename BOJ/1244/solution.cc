#include <cstdio>

using namespace std;

int e[103];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    int q;
    scanf("%d", &q);

    while(q--){
        int s, d;
        scanf("%d %d", &s, &d);
        if(s == 1)for(int i=d; i<=n; i+=d)e[i] ^= 1;
        else{
            e[d] ^= 1;
            for(int i=1; d+i <= n && d-i >= 1; i++){
                if(e[d+i] == e[d-i])e[d+i] ^= 1, e[d-i] ^= 1;
                else
                    break;
            }
        }
    }

    for(int i=1; i<=n; i++){
        printf("%d ", e[i]);
        if(i%20 == 0)printf("\n");
    }

}
