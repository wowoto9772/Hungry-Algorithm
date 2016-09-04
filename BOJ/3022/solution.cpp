#include <stdio.h>

#include <string.h>

#include <map>
#include <string>

using namespace std;

char str[23];

int main(){

	map <string, int> cookie;

	int n;
	scanf("%d", &n);
	
	int ans = 0;

	for(int i=1; i<=n; i++){
		
		scanf("%s", str);

		string c = string(str);

		if(cookie[c] > (i-1) - cookie[c])ans++;

		cookie[c]++;

	}

	printf("%d\n", ans);

}
