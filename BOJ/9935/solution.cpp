#include <stdio.h>
#include <string.h>

#include <vector>
#include <stack>

using namespace std;

char str[1000003];
char cmp[39];

bool used['z' + 3];
stack < pair<char, int> > stk;
bool FRULA;

void Remain(){
	vector <char> tmp;
	while (!stk.empty()){
		tmp.push_back(stk.top().first);
		stk.pop();
	}
	while (!tmp.empty()){
		FRULA = false;
		printf("%c", tmp.back());
		tmp.pop_back();
	}
}

int main(){

	scanf("%s %s", str, cmp);

	int s = strlen(str);

	int l = strlen(cmp);

	for (int i = 0; i < l; i++)used[cmp[i]] = true;

	FRULA = true;

	int c = 0;
	for (int i = 0; i < s; i++){
		char ch = str[i];
		if (used[ch]){
			if (stk.empty()){
				if (ch == cmp[0]){
					stk.push(make_pair(ch, 1));
					if (stk.top().second == l){
						for (int j = 1; j <= l; j++)stk.pop();
					}
				}
				else{
					FRULA = false;
					printf("%c", ch);
				}
			}
			else{
				if (ch == cmp[stk.top().second]){
					stk.push(make_pair(ch, stk.top().second + 1));
					if (stk.top().second == l){
						for (int j = 1; j <= l; j++)stk.pop();
					}
				}
				else if (ch == cmp[0]){
					stk.push(make_pair(ch, 1));
					if (stk.top().second == l){
						for (int j = 1; j <= l; j++)stk.pop();
					}
				}
				else{
					Remain();
					FRULA = false;
					printf("%c", ch);
				}
			}
		}
		else{
			Remain();
			FRULA = false;
			printf("%c", ch);
		}
	}

	Remain();

	if (FRULA)printf("FRULA");

}