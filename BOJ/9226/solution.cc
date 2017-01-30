#include <cstdio>
#include <cstring>

using namespace std;

bool isVowel(char a){
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')return true;
    else
        return false;
}

char str[23];

int main(){

    while(scanf("%s", str) == 1){
        if(strcmp(str, "#") == 0)break;
        int s = strlen(str);

        if(isVowel(str[0]))printf("%say\n", str);
        else{
            bool flag = false;
            for(int i=0; !flag && i<s; i++){
                if(isVowel(str[i])){
                    printf("%s", str+i);
                    str[i] = 0;
                    printf("%say\n", str);
                    flag = true;
                }
            }
            if(!flag)printf("%say\n", str);
        }
    }
}
