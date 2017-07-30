#include <cstdio>
#include <vector>

using namespace std;

char str[55];
vector <int> p[26];

int main(){

    scanf("%s", str);
    for(int i=0; i<52; i++){
        p[str[i]-'A'].push_back(i);
    }
    
    int ans = 0;
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(p[i][0] < p[j][0] && p[j][0] < p[i][1]){
                if(p[i][1] < p[j][1])ans++;
            }
        }
    }
    printf("%d\n", ans);
    
}