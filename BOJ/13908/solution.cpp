#include <cstdio>

using namespace std;

bool must[10];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        int e;
        scanf("%d", &e);
        must[e] = true;
    }

    int e = 1;

    for(int i=1; i<=n; i++){
        e *= 10;
    }
    
    int a = 0;

    for(int i=0; i<e; i++){
        int j = i, k = 0;
        int c = 0;
        bool used[10] = {};
        while(j){
            if(!used[j%10] && must[j%10])c++;
            used[j%10] = true;
            k++;
            j /= 10;
        }
        if(k != n && !used[0] && must[0])c++;
        if(c >= m)a++;
    }

    printf("%d\n", a);

}

