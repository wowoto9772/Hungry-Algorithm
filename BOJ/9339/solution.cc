#include <cstdio>
#include <map>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        map <int, bool> p;

        for(int i=1; i<=n; i++){
            int e;
            scanf("%d", &e);
            p[e] = true;
        }

        scanf("%d", &n);

        int c = 0;
        int a = 60*6+1, b = -1;

        for(int i=1; i<=n; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);

            if(y == -1)continue;

            if(p[x]){
                int d = y*60+z;
                if(d <= 360){
                    c++;
                    if(d < a)b = x, a = d;
                }
            }
        }

        printf("%d %d\n", b, c);

    }

}
