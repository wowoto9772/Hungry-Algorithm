#include <stdio.h>
#include <time.h>
#include <vector>
#define N 80000

using namespace std;

int I[100003];
bool chk[100003];

int main()
{
	//srand(time(NULL));

	//FILE *input = fopen("test11.in", "w");

	//int a, C = 0;

	//fprintf(input, "80000 200\n");

	//for (int i = 0; i < 199; i++){
	//	fprintf(input, "100 ");
	//	while (true){
	//		a = rand() % 79900 + 1;
	//		if (chk[a] || chk[a+99])continue;
	//		break;
	//	}

	//	for (int j = a; j <= a + 99; j++){
	//		fprintf(input, "%d ", j);
	//		chk[j] = true;
	//		C++;
	//	}
	//	fprintf(input, "\n");
	//}

	//fprintf(input, "%d ", N - C);
	//for (int j = 1; j <= N; j++)if (!chk[j])fprintf(input, "%d ", j);
	//fprintf(input, "\n");

	//fclose(input);

	//freopen("test11.in", "r", stdin);
	//freopen("test11.out", "w", stdout);

	int n, k, ans = 1, c = 0;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= k; i++){
		int a;
		scanf("%d", &a);

		c += a - 1;
		bool f = false;

		for (int j = 1; j <= a; j++){
			scanf("%d", &I[j]);
		}

		if (I[1] == 1){
			f = true;
			int s = 1;
			for (int k = 2; k <= a; k++){
				if (I[k] == I[s] + 1){
					s = k;
					ans++; // 1 2 3 ... sequence
				}
				else
					break;
			}
		}

		if (f){
			c -= a - 1;
			c += a - ans;
			c += a - ans;
		}
		else{
			c += a;
		}

	}

	printf("%d\n", c);
}

/*
무조건 1을 찾아라.
123
456
이면 123뒤에 456을 넣을수가 없고
56 뺴고 4 넣고 5 뺴고 6넣기.
*/