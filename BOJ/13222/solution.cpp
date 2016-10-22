#include <cstdio>

using namespace std;

int main(){

    int n, w, h;
    scanf("%d %d %d", &n, &w, &h);

    int c = w*w+h*h;

    while(n--){
        int v;
        scanf("%d", &v);
        v*=v;
        if(v <= c)printf("YES\n");
        else
            printf("NO\n");
    }

}
