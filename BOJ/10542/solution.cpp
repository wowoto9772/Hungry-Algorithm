#include <stdio.h>

int in[500003];
int nxt[500003];
bool vst[500003];
int cnt;

void GoTo(int cur, bool mafia) {
	if (vst[cur])return;
	vst[cur] = true;

	cnt += (mafia) ? 1 : 0;
	int ncur = nxt[cur];

	--in[ncur];

	if (!in[ncur] || mafia) {
		GoTo(ncur, !mafia);
	}
}

int main() {

	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nxt[i]);
		in[nxt[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (!in[i]) { // src
			GoTo(i, true);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (vst[i])continue;
		GoTo(i, false);
	}

	printf("%d\n", cnt);

}