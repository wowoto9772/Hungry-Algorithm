#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

char str[10003];
char cmp[5003];

int pars['Z' + 3];

int main(){

	scanf("%s %s", str, cmp);

	int n = strlen(str);
	int k = strlen(cmp);

	scanf("%d %d %d %d", &pars['A'], &pars['C'], &pars['G'], &pars['T']);

	int ans = INT_MAX;

	for (int i_ = 0; i_ < n; i_++){

		int i = i_;
		int cst = 0;

		for (int j = 0; j < k; j++){
			if (str[i] == cmp[j]){
				i++;
				continue;
			}
			else{
				cst += pars[cmp[j]];
			}
		}

		ans = min(ans, cst);
	}

	printf("%d\n", ans);
}