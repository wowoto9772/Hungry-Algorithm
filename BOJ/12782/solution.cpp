#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char N[1000003], M[1000003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%s %s", N, M);

		int s = strlen(N);

		int on = 0, tw = 0;
		int con = 0, ctw = 0;
	
		for (int i = 0; i < s; i++) {
			if (N[i] == M[i])continue;
			if (N[i] == '0')on++;
			else
				tw++;

			if (M[i] == '0')con++;
			else
				ctw++;
		}

		int m1 = min(on, tw);
		int m2 = min(con, ctw);

		int k = min(m1, m2);

		int ans = k;
		tw -= k, ctw -= k, on -= k, con -= k;

		ans += abs(tw - ctw);

		printf("%d\n", ans);

	}

}