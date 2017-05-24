#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[23];

int main(){
	
	int t;
	scanf("%d", &t);
	
	int tc = 0;
	
	while(t--){

		scanf("%s", str+1);
		str[0] = '0';
		int s = strlen(str);
		
		next_permutation(str, str+s);
		
		printf("Case #%d: ", ++tc);
		
		if(str[0] == '0')printf("%s\n", str+1);
		else
			printf("%s\n", str);
	}
	
}