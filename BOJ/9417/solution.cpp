#include <stdio.h>
#include <string.h>

#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	int m = 1;
	while (m){
		m = a % b;
		a = b;
		b = m;
	}return a;
}

int siz(int v){
	if (!v)return 1;

	int ret = 0;

	while (v){
		ret++;
		v /= 10;
	}

	return ret;
}

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		char str[3003] = { 0 };
		while (!strcmp(str, ""))gets(str);

		int s = strlen(str);
		
		vector <int> val;
		for (int i = 0; i < s; i++){

			if (str[i] == ' ')continue;

			int v;
			sscanf(str + i, "%d", &v);

			val.push_back(v);

			i += siz(v);

		}

		int ans = 1;
		for (int i = 0; i < val.size(); i++){
			for (int j = i + 1; j < val.size(); j++){
				ans = max(ans, gcd(val[i], val[j]));
			}
		}

		printf("%d\n", ans);

	}

}