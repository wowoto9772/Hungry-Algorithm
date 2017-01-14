/*
 * automaton : swap
 * array : remove
 * need tree : s != t
 * both : swap and remove
 */

#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char s[103], t[103];

int main(){

    scanf("%s %s", s, t);

    int ans = 0;

    int l[2] = {strlen(s), strlen(t)};

    if(l[0] >= l[1]){
        int c['z'+3] = {};
        for(int i=0; i<l[0]; i++)c[s[i]]++;
        for(int i=0; i<l[1]; i++)c[t[i]]--;
        if(l[0] != l[1]){
            int j = 0;
            ans = 1;
            for(int i=0; i<l[1]; i++){
                while(t[i] != s[j] && j < l[0]){
                    j++;
                }
                if(t[i] == s[j])j++;
                else
                    ans |= 2;
            }
            for(int i='a'; i<='z'; i++){
                if(c[i] < 0){
                    ans = 0;
                    break;
                }
            }
        }else{
            ans = 2;
            for(int i='a'; i<='z'; i++)if(c[i])ans = 0;
        }
    }

    if(ans == 1)printf("automaton");
    else if(ans == 2)printf("array");
    else if(ans == 3)printf("both");
    else{
        printf("need tree");
    }

}
