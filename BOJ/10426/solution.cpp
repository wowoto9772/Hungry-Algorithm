#include <stdio.h>

int mm[][2] = { {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31},{30,30},{31,31} };

bool leap(int y) {
	if (!(y % 4)) {
		if (!(y % 400))return true;
		else if (!(y % 100))return false;
		else
			return true;
	}
	return false;
}

int main() {

	int y, m, d;
	scanf("%d-%d-%d", &y, &m, &d);

	int k;
	scanf("%d", &k);

	k--;

	for (int i = 1; i <= k; i++) {
		d++;
		if (mm[m][leap(y)] < d) {
			d = 1;
			m++;
		}
		if (m == 13) {
			m = 1;
			y++;
		}
	}

	printf("%d-%02d-%02d\n", y, m, d);

}