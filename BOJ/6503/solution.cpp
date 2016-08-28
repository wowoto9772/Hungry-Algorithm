#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[1000007];

int main(){

	int m;
	
	while(scanf("%d", &m) == 1 && m > 0){

		fgets(str, sizeof(str), stdin); // for buffer

		fgets(str, sizeof(str), stdin);

		int s = strlen(str);

		if(str[s-1] == '\n')s--;

		int ans = 0;

		int l = 0;

		int x = 0;

		int c[128] = {0};

		for(int r=0; r<s; r++){

			if(++c[str[r]] == 1){
				if(++x > m){
					while(l < r && --c[str[l++]] > 0);
					x--;
				}
			}

			ans = max(ans, r-l+1);

		}

		printf("%d\n", ans);

	}

}
