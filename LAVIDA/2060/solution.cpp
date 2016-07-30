#include <stdio.h>

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

string str[1222], str2[1222];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		string tx;
		map <string, map<string, int> > id;
		map <int, string> fr, tl;
		int tp = 0;
		int c[441] = { 0 };

		vector <string> ans;
		int A = 0, B = 0;

		for (int i = 1; i <= n; i++){
			cin >> tx;
			int a;
			scanf("%d", &a);
			for (int j = 1; j <= a; j++){
				cin >> str[j];
			}
			int b;
			scanf("%d", &b);
			for (int j = 1; j <= b; j++){
				cin >> str2[j];
			}
			for (int j = 1; j <= a; j++){
				for (int k = 1; k <= b; k++){
					int w = id[str[j]][str2[k]];
					if (w)c[w]++;
					else{
						fr[tp] = str[j];
						tl[tp] = str2[k];
						c[tp]++;
						id[str[j]][str2[k]] = tp++;
					}
				}
			}
		}


		for (int i = 0; i < tp; i++){
			if (c[i] == n){
				cout << "(" << fr[i] << ", " << tl[i] << ")" << endl;
			}
		}
		printf("\n");
	}
}