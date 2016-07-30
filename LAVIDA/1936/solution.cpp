#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <char> slice(const vector <char> &v, int a, int b){
	return vector <char>(v.begin() + a, v.begin() + b);
}

void Consist(const vector <char> &pre, const vector <char> &in){
	int S = pre.size();
	if (!S)return;
	char root = pre[0];

	int L = find(in.begin(), in.end(), root) - in.begin();
	int R = S - 1 - L;
	Consist(slice(pre, 1, L + 1), slice(in, 0, L));
	Consist(slice(pre, L + 1, S), slice(in, L + 1, S));
	printf("%c", root);
}

int main()
{
	char str[28] = { 0 }, str2[28] = { 0 };
	while (scanf("%s %s", str, str2) == 2){

		vector <char> pre, in;
		int n = strlen(str);
		pre.resize(n), in.resize(n);
		for (int i = 0; i < n; i++)pre[i] = str[i], in[i] = str2[i];
		Consist(pre, in);
		printf("\n");
	}
}