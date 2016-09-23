#include <cstdio>

#include <string.h>

using namespace std;

char str[200003];

int main(){

    int n, t;
    scanf("%d %d", &n, &t);

    scanf("%s", str+1);

    int st = -1;

    str[0] = '0';

    for(int i=1; i<=n; i++){
        if(str[i] == '.'){
            st = i;
        }
    }

    if(st == -1)printf("%s\n", str+1);
    else{
        int ed = -1;
        for(int i=st+1; t && i<=n; i++){
            if(str[i] >= '5'){

                ed = i;
                break;

            }
        }

        if(ed == -1)printf("%s\n", str+1);
        else{
            n = ed;
            for(int i=ed; t && i>st; i--){
                if(str[i] > '9' || str[i] >= '5'){

                    if(i-1 == st){
                        str[i-2]++;
                        if(str[i] > '9'){
                            str[i] = '0';
                            continue;
                        }
                        ed = i-1;
                    }else{
                        str[i-1]++;
                        if(str[i] > '9'){
                            str[i] = '0';
                            continue;
                        }
                        ed = i-1;
                    }

                    t--;

                }
            }

            for(int i=st-1; i>=0; i--){

                if(str[i] > '9'){
                    str[i] = '0';
                    str[i-1]++;
                }

            }


            bool ff = false;

            for(int i=0; i<st; i++){
                if(str[i] != '0'){
                    for(int j=i; j<st; j++){
                        printf("%c", str[j]);
                    }
                    ff = true;
                    break;
                }
            }

            if(!ff)printf("0");

            if(st < ed)printf(".");

            for(int i=st+1; i<=ed; i++)printf("%c", str[i]);


        }

    }

}
