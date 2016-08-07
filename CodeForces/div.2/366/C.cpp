#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int lst[300003];
int app[300003];

int main() {

	int n, q;
	scanf("%d %d", &n, &q);

	for (int i = 1; i <= n; i++) {
		lst[i] = 0;
	}

	int lim = 0;

	queue < pair<int, int> > dat;

	int tot = 0;
	int read = 0;

	while(q--){

		int t, k;
		scanf("%d %d", &t, &k);

		if (t == 1) {

			dat.emplace(++tot, k);
			app[k]++;

		}
		else if (t == 2) {

			read += app[k];
			app[k] = 0;
			lst[k] = tot;

		}
		else {

			lim = max(lim, k);

			while (!dat.empty() && dat.front().first <= lim) {
				
				int x = dat.front().second;

				if(lst[x] < dat.front().first){

					if (app[x] > 0) {	
						read++;
						app[x]--;
					}

				}

				dat.pop();
			}
		}

		printf("%d\n", tot - read);

	}


}