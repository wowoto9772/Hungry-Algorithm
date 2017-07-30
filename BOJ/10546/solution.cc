#include <stdio.h>
#include <map>
#include <string>

using namespace std;

char str[23];

int main(){
    
    int n;
    scanf("%d", &n);
    
    map <string, int> my;
    
    for(int i=1; i<=n; i++){
        scanf("%s", str);
        my[string(str)]++;
    }
    
    for(int i=1; i<n; i++){
        scanf("%s", str);
        my[string(str)]--;
    }
    
    for(auto &e : my){
        if(e.second > 0){
            printf("%s\n", e.first.c_str());
            break;
        }
    }
        
}