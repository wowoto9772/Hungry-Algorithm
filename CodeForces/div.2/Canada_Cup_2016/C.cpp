#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[30];

char ans[2][30];

int main(){

    scanf("%s", str);

    int x, y;

    for(int i=0; i<27; i++){
        for(int j=i+1; j<27; j++){
            if(str[i] == str[j]){
                if(j-i == 1){
                    printf("Impossible\n");
                    return 0;
                }
                x = i, y = j;
            }
        }
    }

    int e = x;
    int f = y;

    int d = (y-x-1)/2;

    int c = x;

    for(int i=12-d; i<=12; i++){
        ans[0][i] = str[c++];
    }

    int a = ((f-e)&1) == 0;

    for(int i=12; i>=13-d-a; i--){
        ans[1][i] = str[c++];
    }

    x = 0;
    y++;

    for(int i=11-d; i>=0; i--){
        if(y >= 27){
            if(x == e)break;
            ans[0][i] = str[x++];
        }
        else
            ans[0][i] = str[y++];
    }

    for(int i=0; i<13-d; i++){
        if(y >= 27){
            if(x == e)break;
            ans[1][i] = str[x++];
        }
        else{
            ans[1][i] = str[y++];
        }
    }

    printf("%s\n%s\n", ans[0], ans[1]);


}
