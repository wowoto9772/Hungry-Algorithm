#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

string out, rmv, cmp;
char str[1003], rem[1003];

int main() {

	scanf("%s %s", str, rem);

	string st = string(str);
	string rmv = string(rem);

	int s = strlen(rem), r;

	s = st.size(), r = rmv.size();

	for (int i = 0; i + r < s; i++) {
		if (st.compare(i, r, rmv) == 0) {
			cmp = st.substr(0, i);

			if (i + r < s)cmp += st.substr(i + r);

			if (out == "" || out < cmp)out = cmp;
		}
	}

	printf("%s\n", out.c_str());


}