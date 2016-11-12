#include <cstdio>
#include <cstring>

using namespace std;

char str[103];
double what(char c){
    if(c == 'O')return 15.9994;
    else if(c == 'C')return 12.011;
    else if(c == 'H')return 1.00794;
    else if(c == 'S')return 32.066;
    else if(c == 'N')return 14.00674;
    else if(c >= 'A' && c <= 'Z')return -10.0; // invalid
    else
        return -0.5;
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%s", str);
        int s = strlen(str);

        bool flag= false;

        for(int i=0; i<s; i++){
            if(what(str[i]) < -9.0){
                flag = true;
                break;
            }
        }

        double ans = 0.0;

        if(flag)printf("Invalid formula");
        else{

            for(int i=0; i<s; i++){
                if(what(str[i]) > 0.0){
                    ans += what(str[i]);
                    int ni = i;
                    int v = 0;
                    for(int j=i+1; j<s; j++){
                        if(what(str[j]) < 0 && what(str[j]) >= -1.0){
                            ni = j;
                            v = v * 10 + str[j] - '0';
                        }else{
                            break;
                        }
                    }
                    if(v>0)ans += what(str[i]) * (double)(v-1);
                    i = ni;
                }
            }

            printf("%.4lf", ans);
        }

        printf("\n");
    }

}
