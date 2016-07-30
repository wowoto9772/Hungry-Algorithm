#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

char str[42];

int main() {

	scanf("%s", str);

	int s = strlen(str);
	vector <string> out;
	bool spc[10] = { 0 };

	string tmp = "";

	for (int i = 0; i < s; i++) {
		if (str[i] == ':' || i == s - 1) {
			if (str[i] != ':' && i == s - 1)tmp += str[i];
			if (tmp == "") {
				if (i && spc[i - 1])continue;
				if(i)spc[out.size()] = true;
				out.push_back("0000");
			}else{
				int k = tmp.size();
				for (int j = 0; j < 4 - k; j++)tmp = "0" + tmp;
				out.push_back(tmp);
			}
			tmp = "";
		}
		else {
			tmp += str[i];
		}
	}

	for (int i = 0; i < out.size(); i++) {
		if (i)printf(":");
		printf("%s", out[i].c_str());
		if (spc[i]) {
			for (int j = 0; j < 8 - out.size(); j++) {
				printf(":0000");
			}
		}
	}

	printf("\n");

}