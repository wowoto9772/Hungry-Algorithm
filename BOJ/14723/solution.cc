#include <cstdio>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	int j;
	for (int i = 1;; i++){
		if (i*(i + 1) / 2 <= n){
			j = i;
		}
		else
			break;
	}

	if (j*(j + 1) / 2 == n)printf("%d %d\n", 1, j);
	else{
		n -= (j + 1)*j / 2;
		int p = j + 2, q = 0;
		p -= n, q += n;
		printf("%d %d\n", p, q);
	}

}