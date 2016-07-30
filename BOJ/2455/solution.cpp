#include <stdio.h>

int main(){

	int cap = 0;
	int in, out;

	int max = 0;
	for (int i = 0; i < 4; i++){
		scanf("%d %d", &out, &in);
		cap -= out;
		cap += in;

		if (cap > max)max = cap;
	}

	printf("%d\n", max);

}