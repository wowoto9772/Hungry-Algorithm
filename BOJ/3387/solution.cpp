#include <cstdio>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int k;
    scanf("%d", &k);

    int x = INT_MAX, y = 0;

    for(int i=1; i<=9; i++){
        vector <bool> r(k);
        int c = 0;
        bool flag = false;
        for(int j=1; !flag; j++){
            c = c * 10 + i;
            c %= k;
            if(r[c]){
                flag = true;
            }else{
                r[c] = true;
                if(c == 0){
                    if(x > j){
                        x = j, y = i;
                    }
                    break;
                }
            }
        }
    }

    if(x == INT_MAX)printf("Impossible\n");
    else
        printf("%d %d\n", y, x);

}
