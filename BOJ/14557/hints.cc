#include <cstdio>
#include <algorithm>

using namespace std;

int cnt[6];
int ans = 0;

void sexy(int fin, int step){
    if(fin == 5){
        ans = max(ans, step);
    }else{
        for(int i=1; i<=5; i++){
            if(cnt[i] == 2){
                cnt[i] = -1;
                sexy(fin+1, step+1);
                cnt[i] = 2;
            }else if(cnt[i] == 0){
                cnt[i]++;
                for(int j=1; j<=5; j++){
                    if(cnt[j] == -1)continue;
                    cnt[j]++;
                    if(cnt[j] == 2){
                        cnt[j] = -1;
                        sexy(fin+1, step+1);
                        cnt[j] = 2;
                    }else{
                        sexy(fin, step+1);
                    }
                    cnt[j]--;
                }
                cnt[i]--;
            }else if(cnt[i] == 1){
                for(int j=1; j<=5; j++){
                    if(cnt[j] == -1)continue;
                    cnt[j]++;
                    if(cnt[j] == 2){
                        cnt[j] = -1;
                        sexy(fin+1, step+1);
                        cnt[j] = 2;
                    }else{
                        sexy(fin, step+1);
                    }
                    cnt[j]--;
                }
            }
        }
    }
}

int main(){

    sexy(0, 0);
    printf("%d\n", ans);

}
