#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

char str[1003], tmp[1003];

int main(){
    
    int t;
    scanf("%d", &t);
    fgets(str, sizeof(str), stdin); // for buffer
    
    int tc = 0;
    
    while(t--){
    
        fgets(str, sizeof(str), stdin);
        int s = strlen(str);
        if(str[s-1] == '\n')str[s-1] = 0;
        s--;
        
        vector <string> ans;
        for(int i=0; i<s; i++){
            sscanf(str+i, "%s", tmp);
            int k = strlen(tmp);
            i += k;
            ans.emplace_back(string(tmp));
        }
        
        printf("Case #%d: ", ++tc);
        while(!ans.empty()){
            printf("%s ", ans.back().c_str());
            ans.pop_back();
        }
        printf("\n");
    }

}