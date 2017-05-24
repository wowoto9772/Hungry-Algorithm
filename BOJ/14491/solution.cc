#include <cstdio>

using namespace std;

int main(){

	int v;
	scanf("%d", &v);

	int a[24] = {};
	int t = 0;

	while (v){
		a[t++] = v % 9;
		v /= 9;
	}

	for (int i = t - 1; i >= 0; i--)printf("%d", a[i]);

}