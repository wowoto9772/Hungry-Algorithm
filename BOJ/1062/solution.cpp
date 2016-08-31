#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[18];

int wrd[53];

bool spc(int v){
	if(v == 'a' || v == 'n' || v == 't' || v == 'c' || v == 'i')return true;
	else
		return false;
}

int mp['z'+3];

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	int top;

	for(int i='a'; i<='z'; i++){
		if(spc(i))continue;
		mp[i] = top++;
	}

	for(int i=0; i<n; i++){

		scanf("%s", str);

		int s = strlen(str);

		int d = 0;

		for(int j=4; j<s-4; j++){
			if(spc(str[j]))continue;
			d |= 1<<(mp[str[j]]);
		}

		wrd[i] = d;

	}

	if(k < 5)printf("0");
	else{

		int ans = 0;

		for(int i=0; i<(1<<21); i++){

			int l = k - 5;

			for(int j=0; j<21; j++){
				if(i&(1<<j))l--;
			}

			if(l)continue;

			int tmp = 0;

			for(int j=0; j<n; j++){
				if((wrd[j] & i) == wrd[j])tmp++;
			}

			ans = max(ans, tmp);

		}

		printf("%d\n", ans);

	}


}
