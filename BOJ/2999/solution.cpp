#include <cstdio>
#include <cstring>

using namespace std;

char str[103];
char out[103][103];

int main(){
    
    scanf("%s", str);

    int s = strlen(str);
    int r = 0;
    for(int i=1; i*i <= s; i++){
        if(s%i)continue;
        r = i;
    }

    int c = s/r;
    int top = 0;
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            out[j][i] = str[top++];
        }
    }

    for(int i=0; i<r; i++)printf("%s", out[i]);

}
