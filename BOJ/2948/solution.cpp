#include <stdio.h>

int d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char str[7][12] = { { "Thursday" }, { "Friday" }, { "Saturday" }, { "Sunday" }, { "Monday" }, { "Tuesday" }, { "Wednesday" }};

int main(){
	int gd, gm;
	scanf("%d %d", &gd, &gm);
	gm--;

	int x = 0; // Thrusday

	int cd = 1, cm = 0;
	while (true){
		if (cd == gd && cm == gm)break;
		x++;
		cd++;
		if (d[cm] < cd){
			cd = 1;
			cm++;
		}
		x %= 7;
	}

	printf("%s\n", str[x]);

}