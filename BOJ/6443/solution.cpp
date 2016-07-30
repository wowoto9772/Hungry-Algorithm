#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[30];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str);

		int s = strlen(str);
		sort(str, str + s);
		printf("%s\n", str);
		while (next_permutation(str, str + s)){
			printf("%s\n", str);
		}
	}
}