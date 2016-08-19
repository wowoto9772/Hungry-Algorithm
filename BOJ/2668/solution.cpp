#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

bool used[103];
bool cyc[103];

int nxt[103];

int stk[103];

int ord[103];

vector <int> out;

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &nxt[i]);
	}


	for (int i = 1; i <= n; i++) {

		if (cyc[i] || used[i])continue;

		for (int j = 1; j <= n; j++)ord[j] = n + 2;

		int c = i;

		int top = 0;

		while (!used[c] && !cyc[c]) {

			ord[c] = top;
			stk[top++] = c;
			used[c] = true;
			c = nxt[c];
			
		}

		if (!cyc[c]) {

			for (int i = ord[c]; i < top; i++) {
				out.push_back(stk[i]);
				cyc[stk[i]] = true;
			}

		}

	}

	sort(out.begin(), out.end());

	printf("%d\n", out.size());

	for (int i = 0; i < out.size(); i++)printf("%d\n", out[i]);

}