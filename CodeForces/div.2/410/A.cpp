#include <cstdio>
#include <cstring>

using namespace std;

char str[17];

int main(){
    
    scanf("%s", str);
    int s = strlen(str);
    int c = 0;
    
    for(int i=0; i<s/2; i++){
        if(str[i] != str[s-1-i]){
            c++;
        }
    }
    
    if(c == 1 || c == 0 && (s&1 == 1))printf("YES");
    else
        printf("NO");

}