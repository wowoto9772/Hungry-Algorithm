#include <stdio.h>
#include <queue>

using namespace std;

int rev[8000003];
int c[8000003];

int main() {

	int n;
	scanf("%d", &n);

	queue <int> q;
	q.push(n);

	while (!q.empty() && !rev[1]) {

		int f = q.front(); q.pop();

		if (!(f % 3)) {
			if (!rev[f / 3]) {
				rev[f / 3] = f;
				c[f / 3] = c[f] + 1;
				q.push(f / 3);
			}
		}

		if (!(f % 2)) {
			if (!rev[f / 2]) {
				rev[f / 2] = f;
				c[f / 2] = c[f] + 1;
				q.push(f / 2);
			}
		}

		if (!rev[f - 1]) {
			rev[f - 1] = f;
			c[f - 1] = c[f] + 1;
			q.push(f - 1);
		}

	}

	printf("%d\n", c[1]);

	vector <int> out;

	int s = 1;
	while (rev[s]) {
		out.push_back(s);
		s = rev[s];
	}

	out.push_back(s);

	for (int i = out.size() - 1; i >= 0; i--)printf("%d ", out[i]);

}