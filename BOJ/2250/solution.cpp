#include <stdio.h>
#include <limits.h>

class Tree {
public:
	int l, r, lv;
}v[10001];

int top, lvc;
int in[10001], c[10001];
int lvle[10001], lvri[10001];


void Search(int cur) {
	v[cur].lv = ++lvc;
	if (v[cur].l != -1)Search(v[cur].l);
	c[cur] = ++top;
	if (v[cur].r != -1)Search(v[cur].r);

	lvc--;
	if (lvle[v[cur].lv] > c[cur])lvle[v[cur].lv] = c[cur];
	if (lvri[v[cur].lv] < c[cur])lvri[v[cur].lv] = c[cur];
}

int main()
{
	int n;
	scanf("%d", &n);

	int a, b, c;

	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (b != -1)in[b]++;
		if (c != -1)in[c]++;
		v[a].l = b, v[a].r = c;
		lvle[i] = INT_MAX;
	}

	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			Search(i);
			break;
		}
	}

	int ans = -1, k;

	for (int i = 1; i <= n; i++) {
		int x = lvri[i] - lvle[i];

		if (ans < x) {
			ans = x;
			k = i;
		}
	}

	printf("%d %d\n", k, ans + 1);
}