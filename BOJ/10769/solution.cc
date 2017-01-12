#include <cstdio>
#include <cstring>

using namespace std;

char str[258];

int main(){

    int h = 0, s = 0;

    fgets(str, sizeof(str), stdin); // for buffer

    int e = strlen(str);

    if(str[e-1] == '\n')e--;
    for(int i=0; i<e; i++){
        if(str[i] == ':' && i+2 < e){
            if(str[i+1] == '-'){
                if(str[i+2] == ')')h++;
                else if(str[i+2] == '(')s++;
            }
        }
    }

    if(h+s > 0){
        if(h > s)printf("happy");
        else if(h < s)printf("sad");
        else
            printf("unsure");
    }else{
        printf("none");
    }

}
