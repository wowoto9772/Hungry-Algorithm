#include <cstdio>
#include <cstring>

using namespace std;

char str[23], ans[23];

int main(){

    int n;
    scanf("%d", &n);

    int t = 0;
    int m = -1;

    for(int i=1; i<=n; i++){
        scanf("%s", &str);
        int a, b;
        scanf("%d %d", &a, &b);
        int c = 0;
        while(a <= b){
            b -= a;
            b += 2;
            c++;
            t++;
        }
        if(m < c){
            m = c;
            strcpy(ans, str);
        }
    }

    printf("%d %s\n", t, ans);

}
