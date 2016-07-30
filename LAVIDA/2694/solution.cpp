#include <stdio.h>
#include <string.h>
#include <math.h>

#include <vector>

using namespace std;

#define ll long long

char str[4][1010];

ll value(int lev, int l, int r){
	ll ret = 0;
	ll tmp = 0;

	vector <ll> val;
	vector <char> ty;

	bool flag = false;

	for (int i = l; i <= r; i++){
		if (str[lev][i] == '+'){
			ty.push_back(str[lev][i]);
		}
		else if (str[lev][i] == '-'){
			ty.push_back(str[lev][i]);
		}
		else if (str[lev][i] == '*'){
			ty.push_back(str[lev][i]);
		}
		else{
			if (str[lev][i] == ' '){
				if (flag){
					val.push_back(tmp);
				}
				tmp = 0;
				flag = false;
			}
			else{
				flag = true;
				tmp = tmp * 10 + str[lev][i] - '0';
				if (i == r){
					val.push_back(tmp);
				}
			}
		}
	}

	for (int i = 0; i < ty.size(); i++){
		if (ty[i] == '*'){
			ll nval = val[i] * val[i + 1];
			ty.erase(ty.begin() + i);
			val.erase(val.begin() + i);
			val.erase(val.begin() + i);
			val.insert(val.begin() + i, nval);
			i--;
		}
	}

	ret = val[0];
	for (int i = 0; i < ty.size(); i++){
		if (ty[i] == '+'){
			ret += val[i + 1];
		}
		else if (ty[i] == '-'){
			ret -= val[i + 1];
		}
	}

	return ret;
}

int pf[1004]; // share position
int pr[1004]; // root position

int main(){
	int r, c;
	while (scanf("%d %d", &r, &c) == 2 && r && c){

		int flg = r;
		if (flg == 3)flg = 2;

		for (int i = 0; i < c; i++)pf[i] = pr[i] = -1;

		for (int i = 1; i <= r; i++){
			while (strcmp(str[i], "") == 0){
				gets(str[i]);
			}
		}

		int s;
		for (int i = 0; i < c; i++){ // root scan
			if (str[1][i] == '_'){
				for (int j = i; j < c; j++){
					if (str[1][j] == '_'){
						s = j;
					}
					else{
						break;
					}
				}
				pr[i - 2] = s;
				i = s;
			}
		}

		for (int i = 0; i < c; i++){ // fraction
			if (str[2][i] == '='){
				for (int j = i; j < c; j++){
					if (str[2][j] == '='){
						s = j;
					}
					else{
						break;
					}
				}
				pf[i] = s;
				i = s;
			}
		}

		vector <ll> val;
		vector <char> ty;

		bool flag = false;
		ll tmp = 0;
		for (int i = 0; i < c; i++){
			if (pr[i] >= 0){ // root
				val.push_back(sqrt((double)value(2, i + 2, pr[i])));
				i = pr[i];
			}
			else if (pf[i] >= 0){ // fraction
				val.push_back(value(1, i, pf[i]) / value(3, i, pf[i]));
				i = pf[i];
			}
			else{
				if (str[flg][i] == '+'){
					ty.push_back(str[flg][i]);
				}
				else if (str[flg][i] == '-'){
					ty.push_back(str[flg][i]);
				}
				else if (str[flg][i] == '*'){
					ty.push_back(str[flg][i]);
				}
				else{
					if (str[flg][i] == ' '){
						if (flag){
							val.push_back(tmp);
						}
						tmp = 0;
						flag = false;
					}
					else{
						flag = true;
						tmp = tmp * 10 + str[flg][i] - '0';
						if (i == c - 1){
							val.push_back(tmp);
						}
					}
				}
			}
		}

		for (int i = 0; i < ty.size(); i++){
			if (ty[i] == '*'){
				ll nval = val[i] * val[i + 1];
				ty.erase(ty.begin() + i);
				val.erase(val.begin() + i);
				val.erase(val.begin() + i);
				val.insert(val.begin() + i, nval);
				i--;
			}
		}

		ll ans = val[0];
		for (int i = 0; i < ty.size(); i++){
			if (ty[i] == '+'){
				ans += val[i + 1];
			}
			else if (ty[i] == '-'){
				ans -= val[i + 1];
			}
		}

		printf("%lld\n", ans);

		for (int i = 0; i < c; i++)str[1][i] = str[2][i] = str[3][i] = 0;

	}

}