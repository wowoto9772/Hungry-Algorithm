#include <cstdio>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	int ans = 0;

	int c = 0;

	for (int i = 1; i <= n; i++){
		int v;
		scanf("%d", &v);
		if (c < v)c = v;
		ans += v;
	}

	printf("%d\n", ans - c);

}