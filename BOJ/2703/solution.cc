#include <cstdio>
#include <cstring>

using namespace std;

char str[100003], mp['Z'+3], a[29];

int main(){

    int t;
    scanf("%d", &t);

    mp[' '] = ' ';

    fgets(str, sizeof(str), stdin); // for buffer

    while(t--){

        fgets(str, sizeof(str), stdin);
        fgets(a, sizeof(a), stdin);

        for(int i=0; i<26; i++){
            mp['A'+i] = a[i];
        }

        int s = strlen(str);
        if(str[s-1] == '\n')s--;
        for(int i=0; i<s; i++)printf("%c", mp[str[i]]);
        printf("\n");

    }

}
