#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class E{
public:
	int c;
	string n;
	bool operator<(const E &i)const{
		if(c == i.c)return n < i.n;
		return c < i.c;
	}
};

int n, m;

int R(int a, int b){
	int c = 0;
	int rem = n;
	while(rem > m){
		if(rem/2 >= m && rem/2*a > b){
			c += b;
			rem /= 2;
		}else{
			c += (rem-m)*a;
			rem = m;
		}
	}
	return c;
}

char str[203];

int main(){
	int t;
	scanf("%d", &t);
	
	for(int T=1; T<=t; T++){
		int k;		
		scanf("%d %d %d", &n, &m, &k);

		E ele[100];
		string x;
        
		int pre = 0;
        
		for(int i=0; i<k; i++){
			scanf("%s", str);
            x = string(str);
			int s = x.size();
			int a = 0, b = 0;
			for(int j=0; j<s; j++){
				if(x[j] == ':'){
					for(int k=0; k<j; k++)ele[i].n += x[k];
					pre = j+1;
				}else if(x[j] == ','){
					for(int k=pre; k<j; k++)a = a * 10 + x[k] - '0';
					for(int k=j+1; k<s; k++)b = b * 10 + x[k] - '0';
                    break;
				}
			}
			ele[i].c = R(a, b);
		}
		
		sort(ele, ele+k);
		
		printf("Case %d\n", T);
		for(int i=0; i<k; i++)printf("%s %d\n", ele[i].n.c_str(), ele[i].c);
	}
	
}