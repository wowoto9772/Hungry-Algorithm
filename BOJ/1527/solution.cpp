#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAX 1000000000
#define ll long long

using namespace std;

int A[1 << 11];
int top;

int findInd(int n){
	int l = 1, r = top - 1, m;
	while (l <= r){
		m = (l + r) / 2;
		if (A[m] <= n)l = m + 1;
		else
			r = m - 1;
	}
	if (A[m] > n)m--;
	return m;
}

int main(){
	queue <int> q;
	q.push(0);
	top = 1;
	while (!q.empty()){
		ll f = q.front(); q.pop();
		if (f){
			A[top++] = f;
		}
		if (f * 10 + 4 <= MAX){
			q.push(f * 10 + 4);
		}
		if (f * 10 + 7 <= MAX){
			q.push(f * 10 + 7);
		}
	}

	sort(A + 1, A + top);

	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", findInd(b) - findInd(a - 1));
}