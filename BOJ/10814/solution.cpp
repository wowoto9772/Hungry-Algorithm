#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

class ele {
public:

	int age;
	int ord;
	string name;

	bool operator<(const ele &A)const {
		if (age == A.age)return ord < A.ord;
		return age < A.age;
	}
}I[100003];

char str[103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %s", &I[i].age, str);
		I[i].ord = i;
		I[i].name = string(str);
	}

	sort(I, I + n);

	for (int i = 0; i < n; i++)printf("%d %s\n", I[i].age, I[i].name.c_str());

}