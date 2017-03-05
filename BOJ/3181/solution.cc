#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string key[10] = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};

char str[103];

int main(){

    bool fst = true;

    while(scanf("%s", str) == 1){
        string s = string(str);

        bool flg = false;
        for(int i=0; i<10; i++){
            if(s == key[i]){
                flg = true;
                break;
            }
        }

        if(fst || !flg){
            printf("%c", str[0]-('a'-'A'));
            fst = false;
        }
    }

}
