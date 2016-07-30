#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

char str[17];
string I[103];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%s", str);
		I[i] = string(str);
	}

	for (int i = 1; i <= n; i++){
		string J = I[i];
		reverse(J.begin(), J.end());
		for (int j = i; j <= n; j++){
			if (J == I[j]){
				printf("%d %c\n", J.size(), J[J.size() / 2]);
				return 0;
			}
		}
	}
}