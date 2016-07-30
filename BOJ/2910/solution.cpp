#include <stdio.h>
#include <algorithm>

using namespace std;

class ele{
public:
	int f, v, c;
	bool operator<(const ele &A)const{
		if (c == A.c)return f < A.f;
		return c > A.c;
	}
}I[1003];

int main(){
	int n, c;
	scanf("%d %d", &n, &c);

	int top = 0;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);

		bool exi = false;
		for (int j = 0; j < top; j++){
			if (I[j].v == a){
				I[j].c++;
				exi = true;
				break;
			}
		}

		if (!exi){
			I[top].f = i, I[top].v = a, I[top].c = 1;
			top++;
		}
	}

	sort(I, I + top);

	for (int i = 0; i < top; i++){
		while (I[i].c){
			printf("%d ", I[i].v);
			I[i].c--;
		}
	}
}