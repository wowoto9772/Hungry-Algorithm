#include <cstdio>

#include <cstring>

#include <string>

#include <algorithm>

using namespace std;

char str[53];

int main(){

    scanf("%s", str);

    int s = strlen(str);

    sort(str, str+s);

    int c['z'+3] = {0};

    for(int i=0; i<s; i++){
        c[str[i]]++;
    }

    int no = s / 2;

    int x = -1;

    for(int i='a'; i<='z'; i++){
        if(c[i] > no + (s&1)){
            printf("-1\n");
            return 0;
        }else{
            if(c[i] == no + (s&1)){
                x = i;
            }
        }
    }

    int cur = 0;

    string out;
    
    for(int i='a'; i<='z'; i++){
        while(c[i]){
            c[i]--;
            out += char(i);
            cur++;
            if(cur == no + (s&1)){
                for(int j=no-1; j>=0; j--){
                    for(int k='a'; k<='z'; k++){
                        if(c[k]){
                            if(str[j] == k)continue;
                            c[k]--;
                            out += char(k);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

    printf("%s\n", out.c_str());

}
