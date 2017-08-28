#include <cstdio>
#include <cstring>

using namespace std;

char str[23];
bool vwl[23];

bool isVowel(char a){
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')return true;
    return false;
}

int main(){
    
    while(scanf("%s", str) == 1){
        if(strcmp(str, "end") == 0)break;
        int s = strlen(str);
        bool vowel = false;
        bool cannot = false;
        for(int i=0; i<s; i++){
            vwl[i] = isVowel(str[i]);
            if(vwl[i])vowel = true;
            if(i >= 2){
                if(vwl[i-2] == vwl[i-1] && vwl[i-1] == vwl[i])cannot = true;
            }
            if(i >= 1){
                if(str[i] == str[i-1]){
                    if(str[i] == 'e' || str[i] == 'o')continue;
                    cannot = true;
                }
            }
        }
        
        printf("<%s> is ", str);
        if(cannot || !vowel)printf("not acceptable");
        else
            printf("acceptable");
        printf(".\n");
    }

}