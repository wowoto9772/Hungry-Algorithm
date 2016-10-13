#include <cstdio>
#include <algorithm>

using namespace std;

char str[53][53];
int n;

int cnt(){
    int ret = 0;
    for(int i=0; i<n; i++){
        int p = str[i][0], c = 1;
        for(int j=1; j<n; j++){
            if(p == str[i][j]){
                c++;
            }else{
                ret = max(ret, c);
                c = 1;
                p = str[i][j];
            }
        }
        ret = max(ret, c);
    }
    for(int i=0; i<n; i++){
        int p = str[0][i], c = 1;
        for(int j=1; j<n; j++){
            if(p == str[j][i]){
                c++;
            }else{
                ret = max(ret, c);
                c = 1;
                p = str[j][i];
            }
        }
        ret = max(ret, c);
    }
    return ret;
}

int main(){

    scanf("%d", &n);

    for(int i=0; i<n; i++)scanf("%s", str[i]);

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(str[i][j] != str[i][j+1]){
                swap(str[i][j], str[i][j+1]);
                ans = max(ans, cnt()); 
                swap(str[i][j], str[i][j+1]);
            }
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            if(str[i][j] != str[i+1][j]){
                swap(str[i][j], str[i+1][j]);
                ans = max(ans, cnt());
                swap(str[i][j], str[i+1][j]);
            }
        }
    }

    printf("%d\n", ans);

}
