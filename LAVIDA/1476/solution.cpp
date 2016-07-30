#include <stdio.h>
int Ab(int a){
	if (a<0)return -a;
	else
		return a;
}

int input[7000];

int main()
{
	//freopen("test.in", "r", stdin);
	int n;
	while (scanf("%d", &n) == 1){
		bool check[7000] = { 0 };

		bool flag = false;
		for (int i = 1; i <= n; i++){
			scanf("%d", &input[i]);
			if (i >= 2){
				int t = Ab(input[i] - input[i - 1]);
				if (t > 0 && t < n && check[t] == false)check[t] = true;
				else
					flag = true;
			}
		}
		if (flag == true)printf("Not jolly\n");
		else
			printf("Jolly\n");
	}
}