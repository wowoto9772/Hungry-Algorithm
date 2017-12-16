#include <stdio.h>

const int unvisited = -1;
const int root = 0;

int max(int a, int b) {
	if (a < b) a = b;
	return a;
}

int cnt[1000003], opt[1000003];
int trie[1000003][26], f[1000003];
bool exists[1000003];

int queue[1000003];
int top;

void add(char *r) {
	int p = 0;
	for (int i = 0; r[i] != 0; i++) {
		int v = r[i] - 'a';
		int &q = trie[p][v];
		if (q == unvisited) {
			q = ++top;
			for (int j = 0; j < 26; j++)trie[q][j] = unvisited;
		}
		p = q;
	}
	cnt[p]++;
	exists[p] = true;
}

bool search(char *r) {
	int p = 0;
	for (int i = 0; r[i] != 0; i++) {
		int v = r[i] - 'a';
		while (p != root && trie[p][v] == unvisited)p = f[p];
		if (trie[p][v] != unvisited)p = trie[p][v];
		if (exists[p])return true;
	}return false;
}

// Trie + KMP >> Ahocorasick
void calculatePi() {
	// find failure link
	int front = 0, tale = 0;
	for (int i = 0; i < 26; i++) {
		int &x = trie[0][i];
		if (x == unvisited) continue;
		queue[tale++] = x;
	}

	while (front < tale) {
		int p = queue[front++]; // p
		for (int i = 0; i < 26; i++) {
			int q = trie[p][i];
			if (q == unvisited)continue;
			int pf = f[p];
			while (pf != root && trie[pf][i] == unvisited)pf = f[pf];
			if (trie[pf][i] != unvisited)pf = trie[pf][i]; // trie[pf][i] : r
			f[q] = pf;
			queue[tale++] = q;
		}
		if (exists[f[p]])exists[p] = true;
	}
}

int solve() {

	int front = 0, tale = 0;
	for (int i = 0; i < 26; i++) {
		int &x = trie[0][i];
		if (x == unvisited) continue;
		opt[x] = cnt[x];
		queue[tale++] = x;
	}

	int ans = 0;
	while (front < tale) {
		int p = queue[front++]; // p
		ans = max(ans, opt[p]);
		for (int i = 0; i < 26; i++) {
			int q = trie[p][i];
			if (q == unvisited)continue;
			if (opt[q] < opt[p] + cnt[q]) {
				opt[q] = opt[p] + cnt[q];
			}
			if (opt[q] < opt[f[q]] + cnt[q]) {
				opt[q] = opt[f[q]] + cnt[q];
			}
			queue[tale++] = q;
		}
	}

	return ans;
}

char str[1003];

int main() {

	int n;
	while (scanf("%d", &n) == 1 && n) {

		// initialize state
		for (int i = 0; i < 26; i++)trie[0][i] = unvisited;
		for (int i = 1; i <= top; i++) {
			cnt[i] = opt[i] = f[i] = 0;
			exists[i] = false;
		}

		top = 0;

		while (n--) {
			scanf("%s", str);
			add(str);
		}

		calculatePi();

		printf("%d\n", solve());

	}

}