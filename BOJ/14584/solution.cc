#include <cstdio>
#include <cstring>

using namespace std;

char str[103];
char wrd[23][23];
int len[23];

int main(){

    scanf("%s", str);
    int s = strlen(str);

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", wrd[i]);
        len[i] = strlen(wrd[i]);
    }

    for(int i=0; i<26; i++){
        char tmp[103] = {};
        for(int j=0; j<s; j++){
            tmp[j] = (str[j]-'a'+i) % 26 + 'a';
        }
        for(int j=0; j<s; j++){
            for(int k=0; k<n; k++){
                if(tmp[j] == wrd[k][0] && j + len[k]-1 < s){
                    bool flg = false;
                    for(int x=0; x<len[k] && !flg; x++){
                        if(tmp[j+x] != wrd[k][x])flg = true;
                    }
                    if(!flg){
                        printf("%s\n", tmp);
                        return 0;
                    }
                }
            }
        }
    }

}
