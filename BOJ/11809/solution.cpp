#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

char a[13], b[13];

int main(){
	scanf("%s %s", a, b);

	int s[] = { strlen(a), strlen(b) };

	reverse(a, a + s[0]);
	reverse(b, b + s[1]);

	vector <char> A, B;
	for (int i = 0; i < s[0] && i < s[1]; i++){
		if (a[i] < b[i])B.push_back(b[i]);
		else if (a[i] > b[i])A.push_back(a[i]);
		else{
			A.push_back(a[i]);
			B.push_back(b[i]);
		}
	}

	if (s[0] > s[1])for (int i = s[1]; i < s[0]; i++)A.push_back(a[i]);
	else if (s[0] < s[1])for (int i = s[0]; i < s[1]; i++)B.push_back(b[i]);

	int t;
	if (A.empty())printf("YODA");
	else{
		t = 0;
		reverse(A.begin(), A.end());
		for (int i = 0; i < A.size(); i++){
			t = t * 10 + A[i] - '0';
		}
		printf("%d", t);
	}
	printf("\n");
	if (B.empty())printf("YODA");
	else{
		t = 0;
		reverse(B.begin(), B.end());
		for (int i = 0; i < B.size(); i++){
			t = t * 10 + B[i] - '0';
		}
		printf("%d", t);
	}
	printf("\n");
}