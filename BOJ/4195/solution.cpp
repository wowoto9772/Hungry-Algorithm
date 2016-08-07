#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

char str[23];

int s[200003];
int p[200003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= (n << 1); i++) {
			p[i] = 0;
			s[i] = 1;
		}

		int tp = 0;

		map <string, int> x;

		for (int i = 1; i <= n; i++) {

			scanf("%s", str);

			string c = string(str);

			if (!x[c])x[c] = ++tp;

			int a = x[c];

			scanf("%s", str);

			c = string(str);

			if (!x[c])x[c] = ++tp;
			
			int b = x[c];

			int pa = a, pb = b;

			while (p[pa]) {
				pa = p[pa];
			}

			while (p[pb]) {
				pb = p[pb];
			}

			if (pa == pb)printf("%d\n", s[pa]);
			else {

				while (p[a]) {		
					s[p[a]] += s[a];
					s[a] = 0;
					p[a] = pa;
					a = p[a];
				}

				while (p[b]) {
					s[p[b]] += s[b];
					s[b] = 0;
					p[b] = pb;
					b = p[b];
				}

				s[b] += s[a];
				s[a] = 0;
				p[a] = b;

				printf("%d\n", s[b]);

			}

		}

	}

}