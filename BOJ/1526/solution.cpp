#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int A[1 << 8];
int top;

int main(){
	queue <int> q;
	q.push(0);
	while (!q.empty()){
		int f = q.front(); q.pop();
		if (f){
			A[top++] = f;
		}
		if (f * 10 + 4 <= 1000000){
			q.push(f * 10 + 4);
		}
		if (f * 10 + 7 <= 1000000){
			q.push(f * 10 + 7);
		}
	}

	sort(A, A + top);

	int n;
	scanf("%d", &n);

	int l = 0, r = top - 1, m;
	while (l <= r){
		m = (l + r) / 2;
		if (A[m] <= n)l = m + 1;
		else
			r = m - 1;
	}
	if (A[m] > n)m--;

	printf("%d\n", A[m]);
}