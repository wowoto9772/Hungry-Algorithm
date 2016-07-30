#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

class ele {
public:
	ele() {}
	ele(string na, int ko, int en, int ma) {
		name = na;
		kor = ko, eng = en, mat = ma;
	}

	string name;
	int kor, eng, mat;
	bool operator<(const ele &A)const {
		if (kor == A.kor) {
			if (eng == A.eng) {
				if (mat == A.mat)return name < A.name;
				return mat > A.mat;
			}
			return eng < A.eng;
		}
		return kor > A.kor;
	}
}I[100003];

char str[13];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		int k, e, m;
		scanf("%d %d %d", &k, &e, &m);

		I[i] = ele(string(str), k, e, m);
	}

	sort(I, I + n);

	for (int i = 0; i < n; i++)printf("%s\n", I[i].name.c_str());

}