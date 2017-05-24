#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

char str[203];

int main(){
	int t;
    scanf("%d", &t);
    
    for(int T=1; T<=t; T++){
    	
		int n, m;
        scanf("%d %d", &n, &m);
        
        vector <string> dir[50];
        
        for(int i=1; i<=n; i++){
            scanf("%s", str);
            string a = string(str);
            
            int s = a.size();
            
            string c;
            int cn = 0;
            
            for(int j=0; j<s; j++){
                if(a[j] == '/'){
                   for(int k=j+1; k<s; k++){
                       if(a[k] == '/')break;
                       else
                           c += a[k];
                   }
                   bool f = false;
                   for(int l=0; !f && l<dir[cn].size(); l++){
				       if(dir[cn][l] == c)f = true;
                   }
                   if(!f)dir[cn].push_back(c);
                   cn++;
                }
            }
        }
        
        int ans = 0;
        for(int i=1; i<=m; i++){
			scanf("%s", str);
			string b = string(str);

            int s = b.size();
            
            string c;
            int cn = 0;
            
            for(int j=0; j<s; j++){
                if(b[j] == '/'){
                   for(int k=j+1; k<s; k++){
                       if(b[k] == '/')break;
                       else
                           c += b[k];
                   }
                   bool f = false;
                   for(int l=0; !f && l<dir[cn].size(); l++){
				       if(dir[cn][l] == c)f = true;
                   }
                   if(!f){
                       dir[cn].push_back(c);
                       ans++;
                   }
                   cn++;
                }
            }            
        }
        
        printf("Case #%d: %d\n", T, ans);
    }
}