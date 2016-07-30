#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char str[2003];

int main() {

	int t;
	scanf("%d", &t);

	fgets(str, 2000, stdin); // for buffer

	while (t--) {
		
		fgets(str, 2000, stdin);

		int s = strlen(str);

		string tmp;

		vector <string> out;

		for (int i = 0; i < s; i++) {
			if (str[i] == ' ' || str[i] == '\n') {
				reverse(tmp.begin(), tmp.end());
				out.push_back(tmp);
				tmp = "";
			}
			else {
				tmp += str[i];
			}
		}

		for (int i = 0; i < out.size(); i++) {
			printf("%s ", out[i].c_str());
		}

		printf("\n");
	}

}