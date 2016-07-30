#include <stdio.h>
#include <string>
#include <iostream>
#define IDENTICAL " is identical to "
#define ANAGRAM " is an anagram of "
#define ALANAGRAM " is almost an anagram of "
#define NOTHINGLIKE " is nothing like "

using namespace std;

int main(){
	string a, b;
	cin >> a >> b;

	if (a == b){
		cout << a << IDENTICAL << b << endl;
	}
	else{
		if (a.size() > b.size() || a.size() == b.size() && a > b){
			string t = a;
			a = b;
			b = t;
		}

		int c['z' + 5] = { 0 };
		for (int i = 0; i < a.size(); i++){
			c[a[i]]++;
		}
		for (int i = 0; i < b.size(); i++){
			c[b[i]]--;
		}

		int p = 0, m = 0;
		for (int i = 'a'; i <= 'z'; i++){
			if (c[i] > 0)p += c[i];
			else if (c[i] < 0)m -= c[i];
		}

		if (!p && !m)cout << a << ANAGRAM << b << endl;
		else{
			if (!p && m == 1)cout << a << ALANAGRAM << b << endl;
			else{
				if (a.size() == b.size()){
					int c = 0;
					for (int i = 0; i < a.size(); i++){
						if (a[i] != b[i])c++;
					}
					if (c == 1)cout << a << ALANAGRAM << b << endl;
					else{
						cout << a << NOTHINGLIKE << b << endl;
					}
				}
				else{
					cout << a << NOTHINGLIKE << b << endl;
				}
			}
		}
	}
}