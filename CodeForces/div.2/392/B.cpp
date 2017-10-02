#include <cstdio>
#include <cstring>

using namespace std;

char *bulb = "RBYG";
char str[103];

int main(){
    
    scanf("%s", str);
    int s = strlen(str);
    int c['Z'+3] = {};
    for(int i=0; i<s; i++){
        if(str[i] == '!'){
            for(int j=i+4; j<s && str[i] == '!'; j+=4){
                if(str[j] != '!')str[i] = str[j];
            }
            for(int j=i-4; j>=0 && str[i] == '!'; j-=4){
                if(str[j] != '!')str[i] = str[j];
            }
            c[str[i]]++;
        }
    }
    
    for(int i=0; i<4; i++)printf("%d ", c[bulb[i]]);

}