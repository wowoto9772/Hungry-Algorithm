#include <cstdio>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int v[53], o[53] = {};

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    } 

    int cnt = 0, frm = 0, val;

    while(cnt < n){
        while(o[frm] != 0)frm = (frm+1)%n;
        o[frm] = v[cnt++];
        frm = (o[frm]+frm)%n;
    }

    printf("%d\n", n);
    for(int i=0; i<n; i++)printf("%d ", o[i]);


}
