#include <cstdio>
#include <cstring>

using namespace std;

char *oct = "/-\\(@?>&%";
char str[13];

int main(){
	
	while(scanf("%s", str) == 1){
		if(strcmp(str, "#") == 0)break;
		int s = strlen(str);
		int ans = 0, o = 1;
		for(int i=s-1; i>=0; i--){
			for(int j=0; j<=8; j++){
				if(oct[j] == str[i]){
					ans += (j-1) * o;
					break;
				}
			}
			o <<= 3;
		}
		printf("%d\n", ans);
	}
	
}