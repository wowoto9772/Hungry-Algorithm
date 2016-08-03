#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string w[44];

int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){

		for (int i = 1; i <= n; i++){
			cin >> w[i];
		}

		int x[5] = { 5, 7, 5, 7, 7 };
		bool end = false;
		for (int i = 1; !end && i <= n; i++){
			int c = 0, f = 0;
			for (int j = i; !end && j <= n; j++){
				c += w[j].size();
				if (c > x[f])break;
				else if (c == x[f]){
					f++;
					c = 0;
					if (f == 5){
						printf("%d\n", i);
						end = true;
					}
				}
			}
		}

	}
}