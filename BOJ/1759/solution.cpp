#include <stdio.h>
#include <algorithm>

using namespace std;

char I[16];

int k, n;
char str[18];

bool isSon(char a){
	if (a == 'a')return false;
	else if (a == 'e')return false;
	else if (a == 'i')return false;
	else if (a == 'o')return false;
	else if (a == 'u')return false;
	return true;
}

void pass(int c, int m, int sn, int mt){
	if (m == k){
		if(sn >= 2 && mt >= 1)printf("%s\n", str);
		return;
	}
	for (int i = c; i < n; i++){
		str[m] = I[i];
		pass(i + 1, m + 1, sn + (isSon(I[i]) ? 1 : 0), mt + (!isSon(I[i]) ? 1 : 0));
	}
}

int main(){
	scanf("%d %d", &k, &n);

	for (int i = 0; i < n; i++){
		scanf(" %c", &I[i]);
	}

	sort(I, I + n);

	pass(0, 0, 0, 0);
}