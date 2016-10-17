#include <cstdio>
 
using namespace std;
 
int dr[] = {0, 1, 1, 1};
int dc[] = {1, 0, 1, -1};
char str[7][7];
 
bool isPossible(int a){
     
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(str[i][j] == a){
                for(int k=0; k<4; k++){
                    int n = 0;
                    int r = i, c = j;
                    while(r < 5 && r >= 0 && c < 5 && c >= 0){
                        if(str[r][c] == a)n++;
                        else
                            break;
                        r += dr[k];
                        c += dc[k];
                    }
                    if(n >= 3)return true;
                }
            }
        }
    }
    return false;
     
}
 
int main(){
     
    int t;
    scanf("%d", &t);
     
    while(t--){
         
        for(int i=0; i<5; i++)scanf("%s", str[i]);
         
        bool a = isPossible('A');
        bool b = isPossible('B');
         
        if((a && b) || (!a && !b))printf("draw");
        else if(a)printf("A wins");
        else
            printf("B wins");
             
        printf("\n");
         
    }
 
}