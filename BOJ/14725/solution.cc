#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char str[18];
string pre[17];

int main(){

	int n;
	scanf("%d", &n);

	vector < vector <string> > my(n);

	for (int i = 0; i < n; i++){

		int k;
		scanf("%d", &k);

		for (int j = 0; j < k; j++){
			scanf("%s", str);
			my[i].push_back(string(str));
		}

	}

	sort(my.begin(), my.end());
	for (int i = 0; i < my.size(); i++){
		int k = 0;
		for (auto &e : my[i]){
			if (pre[k / 2] != e){
				for (int j = k / 2 + 1; j < 15; j++)pre[j] = "";
				for (int j = 0; j < k; j++)printf("-");
				printf("%s\n", e.c_str());
				pre[k / 2] = e;
			}
			k += 2;
		}
	}

}