#include <cstdio>

using namespace std;

int main(){
    
    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);
    
    bool sameodd = false, sameeven = false, diffodd = false, diffeven = false;
    
    for(int i=0; i<k; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        
        x &= 1;
        y &= 1;
        if(x == y){
            if(x&1)sameodd = true;
            else
                sameeven = true;
        }
        else{
            if(x&1)diffodd = true;
            else
                diffeven = true;
        }
    }
    
    if((sameodd&&sameeven)&&(diffodd&&diffeven))printf("YES");
    else
        printf("NO");

}