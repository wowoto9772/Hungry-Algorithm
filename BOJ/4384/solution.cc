#include <cstdio>

using namespace std;

int Abs(int a){
	if(a < 0)a = -a;
	return a;
}
int Min(int a, int b){
	if(a > b)a = b;
	return a;
}
int Max(int a, int b){
	if(a < b)a = b;
	return a;
}

bool dp[50+1][450*50+1];

int main(){

	dp[0][0] = true;

	int n;
	scanf("%d", &n);

	int e = n>>1;

	int tot = 0;

	for(int i=0; i<n; i++){
		int v;
		scanf("%d", &v);

		tot += v;

		for(int j=Min(i+1, e); j>=1; j--){
			for(int k=450*50-v; k>=0; k--){
				dp[j][k+v] |= dp[j-1][k];
			}
		}
	}

	int best = 450*50, x;
	for(int i=0; i<=tot; i++){
		if(dp[e][i]){
			int gap = Abs(Abs(tot-i) - i);
			if(best > gap){
				best = gap;
				x = i;
			}
		}
	}

	printf("%d %d\n", Min(x, tot-x), Max(x, tot-x));

}
