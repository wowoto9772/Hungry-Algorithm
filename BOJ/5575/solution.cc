#include <cstdio>

using namespace std;

int main(){

    for(int i=1; i<=3; i++){
        int h[2], m[2], s[2];
        for(int j=0; j<2; j++){
            scanf("%d %d %d", &h[j], &m[j], &s[j]);
            s[j] += h[j] * 3600 + m[j] * 60;
        }
        s[1] -= s[0];
        printf("%d %d %d\n", s[1] / 3600, (s[1] % 3600) / 60, s[1] % 60);
    }

}
