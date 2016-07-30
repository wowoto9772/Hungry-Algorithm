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

// ��� �������� ������ ¦�� (���� �Ѻױ׸���)
// ���� �Ѻ� �׸��⸦ ���� �׷���(Euler Graph)
// �Ѻ� �׸��⸦ ������ �׷����� �������� ������ Ȧ���� ���� ������ 0 �Ǵ� 2