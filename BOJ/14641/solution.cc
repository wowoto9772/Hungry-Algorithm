#include <cstdio>
#include <cstring>

using namespace std;

char a[53], b[53];
bool d['z'+3]['z'+3];

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i='a'; i<='z'; i++){
        d[i][i] = 1;
        for(int j='a'; j<='z'; j++){
            if(i == j)d[i][i] = true;
            else{
                d[i][j] = false;
            }
        }
    }
    
    while(n--){
        char x, y;
        scanf(" %c %c", &x, &y);
        d[x][y] = true;
    }
    
    for(int k='a'; k<='z'; k++){
        for(int i='a'; i<='z'; i++){
            for(int j='a'; j<='z'; j++){
                d[i][j] |= (d[i][k] & d[k][j]);
            }
        }
    }
    
    while(m--){
        scanf("%s %s", a, b);
        int p = strlen(a), q = strlen(b);
        
        bool flag = true;
        if(p == q){
            for(int i=0; i<p && flag; i++){
                flag &= d[a[i]][b[i]];    
            }
        }else{
            flag = false;
        }
        if(!flag)printf("no");
        else
            printf("yes");
        printf("\n");
    }
    
}