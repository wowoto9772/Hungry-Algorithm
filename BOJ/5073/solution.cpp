#include <stdio.h>
#include <algorithm>

using namespace std;

int a[3];

int main(){

	while (scanf("%d %d %d", &a[0], &a[1], &a[2]) == 3){

		if (!a[0] && !a[1] && !a[2])break;

		sort(a, a + 3);

		if (a[2] == a[1] && a[1] == a[0])printf("Equilateral\n");
		else if (a[0] + a[1] <= a[2])printf("Invalid\n");
		else{
			if (a[0] == a[1] || a[1] == a[2])printf("Isosceles\n");
			else{
				printf("Scalene\n");
			}
		}

	}

}