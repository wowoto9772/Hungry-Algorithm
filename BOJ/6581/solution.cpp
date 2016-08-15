#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string t = "--------------------------------------------------------------------------------";
	string I;
	int c = 0;
	bool f = false;
	while(cin>>I){
		if(I == "<br>"){
			cout << endl;
			c = 0;
			f = true;
		}
		else if(I == "<hr>"){
			if(c == 0){
				cout << t << endl;
			}
			else{
				c = 0;
				f = true;
				cout << endl << t << endl;
			}
		}
		else{
			int s = I.size();
			if(c == 0){
				c = s;
				cout << I;
				f = true;
			}
			else if(c + s + 1 <= 80){
				if(f){
					cout << " ";
					c += 1;
				}
				c += s;
				cout << I;
				if(c == 80){
					cout << endl;
					c = 0;
					f = false;
				}
			}
			else{
				c = s;
				f = true;
				cout << endl << I;
			}
		}
	}
}