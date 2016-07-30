#include <stdio.h>
#include <algorithm>

using namespace std;

int c[500003];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d", &c[i]);

	sort(c, c + n);

	int g = c[n - 1];
	for (int i = n - 2; i >= 0; i--){
		if (c[i] >= 2)g += c[i] - 1;
		else
			break;
	}
	printf("%d\n", g);
}