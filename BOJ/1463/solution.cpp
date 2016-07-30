#include <stdio.h>
#include <queue>

using namespace std;

bool chk[1000003];

int main(){
	int n;
	scanf("%d", &n);

	queue <int> q, c;

	q.push(n), c.push(0);

	while (!q.empty()){
		int f = q.front(), f2 = c.front(); q.pop(), c.pop();

		if (f == 1){
			printf("%d\n", f2);
			break;
		}

		f2++;
		for (int i = 2; i <= 3; i++){
			if (!(f % i)){
				if (!chk[f / i]){
					chk[f / i] = true;
					q.push(f / i);
					c.push(f2);
				}
			}
		}

		if (f > 1 && !chk[f - 1]){
			chk[f - 1] = true;
			q.push(f - 1);
			c.push(f2);
		}
	}
}