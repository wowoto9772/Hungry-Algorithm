#include <stdio.h>

#include <algorithm>

using namespace std;

int p[103];

int n;

int rfind(int s, int r){

	int j = s;

	for(int i=s+1; i<=n; i++){
		if(p[i] <= p[s] + r)j = i;
	}

	return j;

}

int lfind(int s, int r){

	int j = s;

	for(int i=s-1; i>=1; i--){
		if(p[s]-r <= p[i])j = i;
	}

	return j;

}

int main(){

	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d", &p[i]);
	}

	sort(p+1, p+1+n);

	int ans = 0;

	for(int i=1; i<=n; i++){

		int tmp = 1;

		int r = 1;

		int j;

		for(j=i; j!=n;){
			int nj = rfind(j, r);
			if(nj == j)break;
			else{
				j = nj;
				r++;
			}
		}

		tmp += j - i;

		r = 1;

		for(j=i; j!=1; ){
			int nj = lfind(j, r);
			if(nj == j)break;
			else{
				j = nj;
				r++;
			}
		}

		tmp += i - j;
		
		ans = max(tmp, ans);

	}

	printf("%d\n", ans);

}
