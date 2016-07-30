#include <stdio.h>

long long ans;

int a[500003], o[500003];

void Merge(int l, int mid, int r){
	int ind = l;

	int pl = l, pr = mid + 1;
	while (pl <= mid && pr <= r){
		if (a[pl] > a[pr]){
			ans += pr - ind;
			o[ind] = a[pr];
			pr++, ind++;
		}
		else{
			o[ind] = a[pl];
			pl++, ind++;
		}
	}

	if (pr == r + 1){
		for (int i = pl; i <= mid; i++)o[ind++] = a[i];
	}
	else{ // pl = mid
		for (int i = pr; i <= r; i++)o[ind++] = a[i];
	}


	// Conquer
	for (int i = l; i <= r; i++){
		a[i] = o[i];
	}
}

void Divide(int l, int r){
	if (l < r){
		int m = (l + r) / 2;
		Divide(l, m);
		Divide(m + 1, r);
		Merge(l, m, r);
	}
}

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		o[i] = a[i];
	}

	Divide(0, n - 1);

	printf("%lld\n", ans);
}