#include <cstdio>

using namespace std;

bool isLeaf(int y){
    if(y%400 == 0)return true;
    else if(y%100 == 0)return false;
    else{
        if(y%4 == 0)return true;
        return false;
    }
}

int day[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31}};

int main(){
    
    int d, m, y;
    while(scanf("%d %d %d", &d, &m, &y) == 3){
        
        if((d|m|y) == 0)break;
        
        bool leaf = isLeaf(y);
        int c = 0;
        while(true){
            if(d == 1 && m == 1)break;
            d--;
            if(d == 0){
                d = day[leaf][m-1];
                m--;
            }
            c++;
        }
            
        printf("%d\n", ++c);        
    }

}