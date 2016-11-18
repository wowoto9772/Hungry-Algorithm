#include <cstdio>

using namespace std;

int s[3][2];
int calc(int x, int y){
    return x/y + ((x%y) != 0);
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        y--;
        s[y/2][x]++;
    }

    int ans = calc(s[0][0]+s[0][1], k);

    for(int i=1; i<3; i++){
        ans += calc(s[i][0], k) + calc(s[i][1], k);
    }

    printf("%d\n", ans);

}
