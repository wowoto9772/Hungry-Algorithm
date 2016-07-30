#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int p[10005];

int main(){

	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < K; i++){
		scanf("%d", &p[i]);
	}

	sort(p, p + K);

	int l = 1, r = 1000000, lim;

	int ans = 0;

	while (l <= r){

		lim = (l + r) / 2;

		int gap = 0;
		int k = 1; // first

		for (int i = 1; i < K; i++){
			gap += p[i] - p[i - 1];
			if (lim <= gap){
				k++;
				gap = 0;
			}
		}

		if (k >= M){
			ans = max(ans, lim);
			l = lim + 1;
		}
		else
			r = lim - 1;
	}

	int gap = 0;

	// first
	printf("1");
	M = M - 1;

	for (int i = 1; i < K; i++){
		gap += p[i] - p[i - 1];
		if (M){
			if (gap >= ans){
				printf("1");
				gap = 0;
				M--;
			}
			else{
				printf("0");
			}
		}
		else{
			printf("0");
		}
	}

}