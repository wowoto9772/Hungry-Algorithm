#include <stdio.h>
#include <vector>

using namespace std;

const char str[] = "abcdefghijklmnopqrstuvwxyz";

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n; 
		scanf("%d", &n);

		vector <char> xtr;
		for (int i = 0; i < 26; i++)xtr.push_back(str[i]);
		for (int i = 1; i <= n; i++){
			int a;
			scanf("%d", &a);
			printf("%c", xtr[a]);
			char ins = xtr[a];
			xtr.erase(xtr.begin() + a);
			xtr.insert(xtr.begin(), ins);
		}printf("\n");
	}
}