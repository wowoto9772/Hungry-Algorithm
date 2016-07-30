#include <stdio.h>

void P2(int a){
	if (a == 2)printf("twenty");
	else if (a == 3)printf("thirty");
	else if (a == 4)printf("forty");
	else if (a == 5)printf("fifty");
	else if (a == 6)printf("sixty");
	else if (a == 7)printf("seventy");
	else if (a == 8)printf("eighty");
	else if (a == 9)printf("ninety");
}
void P(int a){
	if (a == 1)printf("one");
	else if (a == 2)printf("two");
	else if (a == 3)printf("three");
	else if (a == 4)printf("four");
	else if (a == 5)printf("five");
	else if (a == 6)printf("six");
	else if (a == 7)printf("seven");
	else if (a == 8)printf("eight");
	else if (a == 9)printf("nine");
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);
		if (n >= 20){
			P2(n / 10);
			if (n % 10){
				printf("-");
				P(n % 10);
			}
		}
		else if (n >= 10){
			if (n == 10)printf("ten");
			else if (n == 11)printf("eleven");
			else if (n == 12)printf("twelve");
			else if (n == 13)printf("thirteen");
			else if (n == 14)printf("fourteen");
			else if (n == 15)printf("fifteen");
			else if (n == 16)printf("sixteen");
			else if (n == 17)printf("seventeen");
			else if (n == 18)printf("eighteen");
			else if (n == 19)printf("nineteen");
		}
		else{
			P(n);
			if (!n)printf("zero");
		}
		printf("\n");
	}
}