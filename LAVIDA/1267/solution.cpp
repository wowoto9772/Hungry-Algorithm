#include <stdio.h>

bool p[1000000];
int top, P[100000];

int ab(int a){ return a < -a ? -a : a; }

int main()
{
	int nxt;
	for (int i = 2; i*i < 1000000; i++){
		nxt = i;
		if (!p[i]){
			for (int j = i + i; j < 1000000; j += i)p[j] = true;
			P[top++] = i;
		}
	}for (int i = nxt + 1; i < 1000000; i++)if (!p[i])P[top++] = i;


	int a, b, T = 1;
	while (scanf("%d %d", &a, &b) == 2 && a && b){

		int S = 0, K = 0;

		int M = a < b ? b : a;

		for (int i = 0; i<top && P[i] <= M && i <= M; i++){
			if (!(a%P[i]) || !(b%P[i])){
				S++;
				int a_ = 0, b_ = 0;
				while (!(a%P[i])){
					a /= P[i];
					a_++;
				}
				while (!(b%P[i])){
					b /= P[i];
					b_++;
				}
				K += ab(a_ - b_);
			}
			if (a == 1 && b == 1)break;
		}

		printf("%d. %d:%d\n", T++, S, K);
	}
}