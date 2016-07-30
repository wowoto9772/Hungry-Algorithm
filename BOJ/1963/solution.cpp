#include <stdio.h>
#include <queue>

using namespace std;

class ele{
public:
	int n, c;
	ele(){}
	ele(int a, int b){ n = a, c = b; }
};

bool p[10003] = { true, true };

bool valid(int a, int b){
	int c = 0;
	while (a && b){
		if (a % 10 != b % 10)c++;
		a /= 10, b /= 10;
	}
	if (a || b)c++;

	return c == 1;
}
bool chk[10003];

int main(){

	for (int i = 2; i*i < 10000; i++){
		if (p[i])continue;
		for (int j = i*i; j < 10000; j += i)p[j] = true;
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int a, b;
		scanf("%d %d", &a, &b);

		for (int i = 1000; i < 10000; i++)chk[i] = false;

		queue <ele> q;

		q.emplace(a, 0);
		chk[a] = true;

		while (!q.empty()){

			ele pp = q.front(); q.pop();

			if (pp.n == b){
				printf("%d\n", pp.c);
				break;
			}

			for (int i = 1; i <= 1000; i *= 10){
				for (int j = 1; j <= 9; j++){
					ele psh = ele(pp.n + j * i, pp.c + 1);
					if (psh.n < 10000 && !chk[psh.n]){
						if (valid(pp.n, psh.n) && !p[psh.n]){
							chk[psh.n] = true;
							q.emplace(psh);
						}
					}

					psh = ele(pp.n - j*i, pp.c + 1);
					if (psh.n > 1000 && !chk[psh.n]){
						if (valid(pp.n, psh.n) && !p[psh.n]){
							chk[psh.n] = true;
							q.emplace(psh);
						}
					}

				}
			}
		}

		if (!chk[b])printf("Impossible\n");
	}
}