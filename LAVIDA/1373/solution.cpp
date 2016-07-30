// Euler Trail

#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int v, e;
		scanf("%d %d", &v, &e);

		int d[103] = { 0 }; // degree

		for (int i = 1; i <= e; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			d[a]++, d[b]++;
		}

		int c = 0;

		for (int i = 0; i < v; i++){
			if (d[i] % 2)c++;
		}

		if (c == 2 || c == 0)printf("0\n");
		else{
			printf("%d\n", (c - 2) / 2);
		}
	}
}

// 모든 꼭짓점의 차수는 짝수 (닫힌 한붓그리기)
// 닫힌 한붓 그리기를 갖는 그래프(Euler Graph)
// 한붓 그리기를 가지는 그래프의 꼭짓점의 차수가 홀수인 것의 개수는 0 또는 2