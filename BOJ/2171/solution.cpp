#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

int x[5003], y[5003];

int main() {

	int n;
	scanf("%d", &n);

	map < int, map<int, bool> > ext;

	for (int i = 1; i <= n; i++) {

		scanf("%d %d", &x[i], &y[i]);
		ext[x[i]][y[i]] = true;

	}

	int c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] < x[j] && y[i] < y[j]) {
				if (ext[x[i]].find(y[j]) != ext[x[i]].end() && ext[x[j]].find(y[i]) != ext[x[j]].end())c++;
			}
		}
	}

	printf("%d\n", c);



}