#include <cstdio>
#include <cstring>

using namespace std;

bool chk[100];
char str[103];

int main() {

	scanf("%s", str);
	int s = strlen(str);

	int v = (str[0] - '0') * s;

	while (!chk[v]) {
		chk[v] = true;
		int nv = v;
		int c = 0;
		while (nv >= 10) {
			c++;
			nv /= 10;
		}
		nv *= (c+1);
		v = nv;
	}

	if (chk[v])printf("FA");
	else
		printf("NFA");

}