#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

class ele{
public:
	char x;
	int p, q;
	bool operator<(const ele &A)const{
		if (p == A.p)return q < A.q;
		return p < A.p;
	}
}I[17];

char str[15];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str);

		int s = strlen(str);

		for (int i = 0; i < s; i++){
			if (str[i] <= 'Z'){
				I[i].x = str[i];
				I[i].p = str[i] - 'A';
				I[i].q = 0;
			}
			else{
				I[i].x = str[i];
				I[i].p = str[i] - 'a';
				I[i].q = 1;
			}
		}

		sort(I, I + s);

		for (int i = 0; i < s; i++)str[i] = I[i].x;

		printf("%s\n", str);
		while (next_permutation(str, str + s)){
			printf("%s\n", str);
		}
	}
}