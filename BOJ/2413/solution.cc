#include <cstdio>
#include <algorithm>

using namespace std;

int p[50003], e[50003];
bool u[50003] = {true,}; // used

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        p[e[i]] = i;
    }

    for(int i=1; i<=n; i++){
        if(u[e[i]] || u[e[p[e[i]-1]]])u[e[i]] = true;
        else{
            u[e[i]] = u[e[p[e[i]-1]]] = true;
            swap(e[i], e[p[e[i]-1]]);
        }

        printf("%d ", e[i]);
    }

}
