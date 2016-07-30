#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class ele {
public:
	string str;
	ele() {}
	ele(string a) { str = a; }

	bool operator<(const ele &A)const {
		if (str.size() == A.str.size())return str < A.str;
		return str.size() < A.str.size();
	}
};

char str[103];

int main() {

	int n;
	scanf("%d", &n);

	vector <ele> out;

	while (n--) {

		scanf("%s", str);

		int s = strlen(str);

		string tmp;

		for (int i = 0; i < s; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				tmp += str[i];
			}
			else {
				if (tmp != "") {
					string ttmp;
					for (int j = 0; j < tmp.size(); j++) {
						if (tmp[j] != '0') {
							ttmp = tmp.substr(j);
							break;
						}
					}
					if (ttmp == "")ttmp = "0";
					out.emplace_back(ttmp);
				}
				tmp = "";
			}
		}

		if (tmp != "") {
			string ttmp;
			for (int j = 0; j < tmp.size(); j++) {
				if (tmp[j] != '0') {
					ttmp = tmp.substr(j);
					break;
				}
			}
			if (ttmp == "")ttmp = "0";
			out.emplace_back(ttmp);
		}

	}

	sort(out.begin(), out.end());

	for (int i = 0; i < out.size(); i++) {
		printf("%s\n", out[i].str.c_str());
	}

}