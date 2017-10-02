#include <cstdio>

char str[][13] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };

int main(){

	int p = 0, q;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < 9; i++){
		int v = 0;
		for (int j = 0; j < n; j++){
			int u;
			scanf("%d", &u);
			if (v < u)v = u;
		}
		if (p < v)p = v, q = i;
	}

	printf("%s\n", str[q]);

}