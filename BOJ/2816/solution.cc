#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char str[103][13];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)scanf("%s", str[i]);

    int c = 0;
    bool k1 = false, k2 = false;
    for(int i=0; i<n; i++){
        if(strcmp(str[i], "KBS1") == 0){
            while(i > 0){
                swap(str[i], str[i-1]);
                printf("4");
                i--;
            }
            break;
        }else{
            printf("1");
        }
    }

    for(int i=0; i<n; i++){
        if(strcmp(str[i], "KBS2") == 0){
            while(i > 1){
                swap(str[i], str[i-1]);
                printf("4");
                i--;
            }
            break;
        }else{
            printf("1");
        }

    }

}
