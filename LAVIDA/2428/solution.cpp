#include <stdio.h>
#include <limits.h>
#include <time.h>

#include <algorithm>
#include <vector>
#define ll long long

#define min(a,b) a < b ? a : b

using namespace std;

class ele{
public:
	int l, d;
	bool operator<(const ele &A)const{
		if (l == A.l)return d < A.d;
		return l > A.l;
	}
}I[100003];

int c[100003]; // count with the length
int d[203]; // count with the cost
ll s[100003]; // sum cost

vector < int > grp[100003];

int main()
{/*
	FILE *input = fopen("test13.in", "w");
	srand(time(NULL));

	fprintf(input, "80000\n");
	int a;
	for (int i = 1; i <= 79999; i++){
		a = rand() % 8000 + 1;
		fprintf(input, "%d ", a);
	}fprintf(input, "%d\n", a);
	for (int i = 1; i <= 79999; i++){
		a = rand() % 200 + 1;
		fprintf(input, "%d ", a);
	}fprintf(input, "%d\n", a);
	fclose(input);

	freopen("test13.in", "r", stdin);
	freopen("test13.out", "w", stdout);*/

	int n;
	scanf("%d", &n);


	for (int i = 1; i <= n; i++){
		scanf("%d", &I[i].l);
		c[I[i].l]++;
	}

	for (int i = 1; i <= n; i++){
		scanf("%d", &I[i].d);
		d[I[i].d]++;
		grp[I[i].l].push_back(I[i].d);
	}

	sort(I + 1, I + 1 + n);

	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + I[i].d;

	int remv[202] = { 0 };
	ll ans = 200 * n;

	int cur = -1;
	for (int i = 1; i <= n; i++){
		if (cur != I[i].l){
			cur = I[i].l;

			int theother = n - (i + c[cur] - 1);
			int mustdel = theother - c[cur] + 1;

			if (mustdel <= 0){
				if (s[i - 1] < ans)ans = s[i - 1];
				break;
			}
			else{

				for (int j = 0; j < grp[I[i].l].size(); j++){
					remv[grp[I[i].l][j]]++;
				}

				// remove some
				ll rcst = 0;
				int rcnt = 0;
				for (int j = 0; j <= 200 && mustdel; j++){
					int x = d[j] - remv[j];
					if (x > 0){ // del : possible
						int dodel = min(mustdel, x);
						rcnt += dodel;
						rcst += j * (dodel);
						mustdel -= dodel;
					}
				}

				if (s[i - 1] + rcst < ans){
					ans = s[i - 1] + rcst;
				}
			}

		}
	}

	printf("%lld\n", ans);
}