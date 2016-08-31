#include <stdio.h>

bool F[12], R[12];

int n, ans;

void P(int i){

	if(i == n+1){
		int k = 0;
		for(int i=1; i<=n; i++)if(F[i])k++;
		ans = ans > k ? k : ans;
		return ;
	}

	if(F[i] && R[i]){
		F[i] = false;
		R[i] = false;
		P(i+1);
		F[i] = true;
		R[i] = true;
	}

	if(R[i+1] && F[i]){
		R[i+1] = false;
		F[i] = false;
		P(i+1);
		R[i+1] = true;
		F[i] = true;
	}

	if(R[i] && F[i+1]){
		R[i] = false;
		F[i+1] = false;
		P(i+1);
		R[i] = true;
		F[i+1] = true;
	}

	P(i+1);

	return ;
}
int main(){

	ans = 13;

	int a, b, x;
	scanf("%d %d %d", &n, &a, &b);

	for(int i=1; i<=a; i++){
		scanf("%d", &x);
		F[x] = true;
	}

	for(int i=1; i<=b; i++){
		scanf("%d", &x);
		R[x] = true;
	}

	P(1);

	printf("%d\n", ans);
}

