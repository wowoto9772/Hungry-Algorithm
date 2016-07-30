#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

char strl[13];
string str[10003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int c = 0;

		for (int i = 0; i < n; i++){
			scanf("%s", strl);
			str[i] = (string)strl;
		}

		sort(str, str + n);

		bool flag = false;
		for (int i = 0; i < n - 1 && !flag; i++){
			string l = (string)str[i];
			string r = (string)str[i + 1];
			if (l.size() <= r.size()){
				if (r.substr(0, l.size()) == l){
					flag = true;
				}
			}
		}

		printf("%s\n", (!flag) ? "YES" : "NO");
	}
}