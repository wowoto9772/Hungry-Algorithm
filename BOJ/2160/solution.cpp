#include <stdio.h>

#include <string.h>

#include <string>

#include <algorithm>

using namespace std;

char str[13];
string wrd[53];

int cmpr(string a, string b){
	int ret = 0;
	for(int i=0; i<a.size(); i++){
		ret += (a[i] != b[i]);
	}
	return ret;
}

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		for(int j=0; j<5; j++){
			scanf("%s", str);
			wrd[i] += string(str);
		}
	}

	int ans = 5*7+3;

	int x, y;

	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			int tmp = cmpr(wrd[i], wrd[j]);
			if(ans > tmp){
				ans = tmp;
				x = i, y = j;
			}
		}
	}

	printf("%d %d\n", x, y);

}
