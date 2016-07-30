#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <map>

using namespace std;

string I[103];

int main()
{
	//FILE *input = fopen("test10.in", "w");
	//fprintf(input, "%d\n", 100);
	//srand(time(NULL));
	//for (int i = 1; i <= 100; i++){
	//	for (int j = 1; j <= 100; j++){
	//		int a = rand() % 2;
	//		fprintf(input, "%d", a);
	//	}fprintf(input, "\n");
	//}
	//fclose(input);


	//freopen("test10.in", "r", stdin);
	//freopen("test10.out", "w", stdout);
	int n;
	scanf("%d", &n);

	map <string, int> c;

	for (int i = 1; i <= n; i++){
		cin >> I[i];
		if (c[I[i]] == NULL)c[I[i]] = 1;
		else
			c[I[i]]++;
	}

	int ans = 1;

	for (int i = 1; i <= n; i++){
		ans = ans < c[I[i]] ? c[I[i]] : ans;
	}

	printf("%d\n", ans);

}

/*
n*n grid
dirty -> clean
clean -> dirty
*/