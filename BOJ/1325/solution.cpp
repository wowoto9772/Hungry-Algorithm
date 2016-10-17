#include <cstdio>
#include <cstring>

using namespace std;

char str[23];

int main(){

    scanf("%s", str);

    int s = strlen(str);

    for(int i=0; i<s/2; i++){
        if(str[i] != str[s-1-i]){
            printf("false\n");
            return 0;
        }
    }

    printf("true\n");

}
