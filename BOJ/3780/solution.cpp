#include <cstdio>

using namespace std;

int c[20003], p[20003];

int findParent(int u){
    if(p[u] == u)return u;
    int t = findParent(p[u]);
    c[u] += c[p[u]];
    p[u] = t;
    return t;
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        for(int i=1; i<=n; i++)p[i] = i, c[i] = 0;

        while(true){
            char x;
            scanf(" %c", &x);

            if(x == 'E'){
                int a;
                scanf("%d", &a);
                findParent(a); // calculate from parent
                printf("%d\n", c[a]);
            }else if(x == 'I'){
                int a, b;
                scanf("%d %d", &a, &b);
                p[a] = b;
                c[a] = abs(a-b) % 1000;
            }else if(x == 'O'){
                break;
            }

        }
    }

}
