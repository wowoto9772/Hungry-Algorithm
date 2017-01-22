#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    int x[4], y[4];
    for(int i=0; i<2; i++)scanf("%d %d", &x[i], &y[i]);

    int d[2] = {abs(x[0] - x[1]), abs(y[0] - y[1])};

    if(d[0] && d[1]){
        if(d[0] != d[1]){
            printf("-1\n");
        }else{
            printf("%d %d %d %d\n", x[0], y[1], x[1], y[0]);
        }
        return 0;
    }

    int e = max(d[0], d[1]);

    if(x[0] == x[1]){
        x[2] = x[0]+e, y[2] = y[0];
    }else if(y[0] == y[1]){
        x[2] = x[0], y[2] = y[0]+e;
    }

    printf("%d %d ", x[2], y[2]);

    map <int, int> a, b;
    for(int i=0; i<3; i++)a[x[i]]++, b[y[i]]++;

    for(auto &i : a){
        if(i.second == 1)printf("%d ", i.first);
    }

    for(auto &i : b){
        if(i.second == 1)printf("%d ", i.first);
    }

}
