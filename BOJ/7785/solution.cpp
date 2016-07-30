#include <stdio.h>
#include <string.h>

#include <map>
#include <string>
#include <vector>

#include <algorithm>

using namespace std;

char str[23];

bool in[1000003];

int main() {

	int t;
	scanf("%d", &t);

	map <string, int> mp;
	map <int, string> dmp;

	int top = 0;

	for (int i = 1; i <= t; i++) {

		scanf("%s", str);

		string men = (string)str;

		if (mp.find(men) == mp.end()) {
			mp[men] = ++top;
			dmp[top] = men;
		}

		int key = mp[men];

		scanf("%s", str);
		
		if (!strcmp(str, "enter")) {
			in[key] = true;
		}
		else if (!strcmp(str, "leave")) {
			in[key] = false;
		}

	}

	vector <string> out;
	for (int i = 1; i <= t; i++) {
		if (in[i]) {
			out.push_back(dmp[i]);
		}
	}

	sort(out.begin(), out.end());

	for (int i = out.size() - 1; i >= 0; i--)printf("%s\n", out[i].c_str());

}