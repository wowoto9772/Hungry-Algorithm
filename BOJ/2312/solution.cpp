#include <stdio.h>
#include <vector>

using namespace std;

bool p[100003];
int P[40003];

int main(){

	int top = 0;
	for (int i = 2; i <= 100000; i++){
		if (!p[i]){
			P[top++] = i;
			if (i > 317)continue;
			for (int j = i*i; j <= 100000; j += i)p[j] = true;
		}
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		for (int i = 0; P[i] * P[i] <= n && i < top; i++){
			int c = 0;
			while (!(n%P[i])){
				c++;
				n /= P[i];
			}
			if (c)printf("%d %d\n", P[i], c);
		}
		if (n != 1)printf("%d 1\n", n);
	}
}