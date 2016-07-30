#include <stdio.h>
#include <queue>

using namespace std;

int d[11];

int main()
{
	queue <int> Q, C;
	Q.push(1), C.push(1);
	Q.push(2), C.push(1);
	Q.push(3), C.push(1);
	d[1] = d[2] = d[3] = 1;

	while (!Q.empty()){
		int f = Q.front(), c = C.front();
		Q.pop(), C.pop();
		for (int i = 1; i <= 3; i++){
			if (f + i <= 11){
				Q.push(f + i);
				d[f + i]++;
				C.push(c + 1);
			}
		}
	}

	int t;
	while (scanf("%d", &t) == 1){
		while (t--){
			int n;
			scanf("%d", &n);
			printf("%d\n", d[n]);
		}
	}
}