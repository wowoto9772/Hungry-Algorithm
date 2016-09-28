#include <stdio.h>

#include <string.h>

char str[50003];
int c['Z'+3];

int main(){

    scanf("%s", str);

    int s = strlen(str);

    int k = 0, m = 0;

    bool flag = false;

    for(int i=0; i<s; i++){

        if(i >= 26){

            if(str[i-26] == '?')m--;
            else{

                c[str[i-26]]--;
                if(c[str[i-26]] == 0)k--;

            }

        }

        if(str[i] == '?')m++;
        else{
            c[str[i]]++;
            if(c[str[i]] == 1)k++;
        }

        if(i >= 25){

            if(k+m >= 26){

                for(int j=i-25; j<=i; j++){

                    if(str[j] == '?'){
                        for(int x='A'; x<='Z'; x++){
                            if(c[x] == 0){
                                str[j] = x;
                                c[x]++;
                                break;
                            }
                        }
                    }

                }

                flag = true;

                break;

            }

        }

    }

    if(!flag)printf("-1");
    else{
        for(int i=0; i<s; i++){
            if(str[i] == '?')str[i] = 'A';
        }
        printf("%s\n", str);
    }

}
