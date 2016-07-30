#include <stdio.h>
#include <list>

#define ll long long

using namespace std;

char v[13];
ll Max, Min;
int n;

int digit(ll a){
	int ret = 0;
	while (a / 10){
		a /= 10;
		ret++;
	}
	return ++ret;
}

void func(ll cur, list <ll> &my){
	int c = 10 - my.size();
	if (n + 1 == c){
		if (cur > Max)Max = cur;
		if (cur < Min)Min = cur;
		return;
	}
	else{
		ll lst = cur % 10;
		for (int i = 0; i < my.size(); i++){
			ll id = my.front();
			my.pop_front();
			if (c == 0 ||
				v[c - 1] == '<' && lst <= id ||
				v[c - 1] == '>' && lst >= id){
				ll ncur = cur * 10LL + id;
				func(ncur, my);
			}
			my.push_back(id);
		}
	}
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf(" %c", &v[i]);
	}

	list <ll> a;

	for (int i = 0; i <= 9; i++)a.push_back(i);

	Min = 9876543210LL;

	func(0, a);


	for (int i = 1; i <= n + 1 - digit(Max); i++)printf("0");
	printf("%lld\n", Max);

	for (int i = 1; i <= n + 1 - digit(Min); i++)printf("0");
	printf("%lld\n", Min);
}