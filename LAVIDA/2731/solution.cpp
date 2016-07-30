#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

char a[2503][18], b[2503][18];
int mb[2503];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%s", a[i]);
	for (int i = 1; i <= n; i++)scanf("%s", b[i]);

	map <string, int> X;
	for (int i = 1; i <= n; i++){
		X[string(a[i])] = i;
	}


	for (int i = 1; i <= n; i++){
		mb[i] = X[b[i]];
	}

	int ans = 0;
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j <= n; j++){
			if (mb[i] < mb[j])ans++;
		}
	}

	printf("%d/%d\n", ans, (n - 1)*n / 2);

}

