#include <stdio.h>
#include <queue>

using namespace std;

int chk[200009];

int main(){

	int x, k;
	scanf("%d %d", &x, &k);

	for (int i = 0; i <= 200000; i++)chk[i] = -1;

	queue <int> q;
	q.push(x);

	chk[x] = 0;

	while (!q.empty() && chk[k] == -1){
		int f = q.front(); q.pop();

		if (f * 2 <= 2 * k && chk[f * 2] == -1)chk[f * 2] = chk[f] + 1, q.push(f * 2);
		if (f < 2 * k && chk[f + 1] == -1)chk[f + 1] = chk[f] + 1, q.push(f + 1);
		if (f > 0 && chk[f - 1] == -1)chk[f - 1] = chk[f] + 1, q.push(f - 1);
	}

	printf("%d\n", chk[k]);
}