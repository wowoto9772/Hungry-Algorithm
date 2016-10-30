#include <cstdio>
#include <algorithm>

using namespace std;

char a[100003], b[100003];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        scanf("%s", a);
        scanf("%s", b);

        int x = 0, y = 0;

        for(int i=0; i<n; i++){
            if(a[i] != b[i]){
                if(a[i] == 'W')x++;
                else
                    y++;
            }
        }

        printf("%d\n", x+y-min(x,y));

    }

}
