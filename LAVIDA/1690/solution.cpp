#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

char str[83];
vector <string> dir[500*83];
map <string, int> id;

void DiskTree(int c, int h, string cdir){
	for (int i = 0; i < dir[c].size(); i++){
		for (int j = 1; j <= h; j++)printf(" ");
		printf("%s\n", dir[c][i].c_str());

		string nxt = cdir;
		if (h)nxt += "_";
		nxt += dir[c][i];

		DiskTree(id[nxt], h + 1, nxt);
	}
}

int main(){
	int n;
	scanf("%d", &n);

	int top = 0;

	for (int i = 0; i < n; i++){
		scanf("%s", str);
		int s = strlen(str);

		string par;
		string prepar;
		int pre = -1, cur;

		for (int j = 0; j < s; j++){
			if (str[j] == '\\' || j == s-1){
				if (j == s - 1)par += str[j];
				if (pre == -1){
					prepar += par;
					if (!id[prepar]){
						id[prepar] = ++top;
						pre = id[prepar];
						dir[0].push_back(par);
					}
					else{
						pre = id[prepar];
					}
				}
				else{
					prepar += "_";
					prepar += par;
					if (!id[prepar]){
						id[prepar] = ++top;
						cur = id[prepar];
						dir[pre].push_back(par);
					}
					else
						cur = id[prepar];

					pre = cur;
				}
				par = "";
			}
			else
				par += str[j];
		}
	}

	for (int i = 0; i <= top; i++)sort(dir[i].begin(), dir[i].end());

	DiskTree(0, 0, "");
}