#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char str[29];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        scanf("%s", str);

        string o[2];
        bool c[2]['Z'+3] = {};

        string a = string(str);
        a += a;

        int x = 0;

        for(int i=0; i<a.size(); i++){
            if(c[i&1][a[i]]){
                x++;
                if(x == 2)break;
            }else{
                o[i&1] += a[i];
                c[i&1][a[i]] = true;
            }
        }

        for(int i=0; i<2; i++)printf("%s\n", o[i].c_str());

    }

}
