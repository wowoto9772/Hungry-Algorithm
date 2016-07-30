#include <stdio.h>
#include <algorithm>

using namespace std;

int c[1003];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d", &c[i]);

	sort(c, c + n);

	int ans = 0;

	bool flag = false;
	for (int i = 0; i < n; i++){
		if (ans + 1 < c[i]){
			flag = true;
			printf("%d\n", ans + 1);
			break;
		}
		else
			ans += c[i];
	}
	/*
		I made 1 ~ ans
		then, use W(i)
		I made 1 ~ ans + W(i)
	*/

	if (!flag)printf("%d\n", ans + 1);
}