#include <stdio.h>
#include <set>

using namespace std;

const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void swp(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

class Node {
public:
	int x, y;
	bool operator<(const Node &A)const{
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
};

class Edge {
public:
	Node a, b;
	Edge(Node x, Node y){
		a = x, b = y;
		if (a.x > b.x){
			swp(a.x, b.x);
			swp(a.y, b.y);
		}
		else if (a.x == b.x && a.y > b.y){
			swp(a.y, b.y);
		}
	}
	bool operator<(const Edge &A)const{
		if (a.x == A.a.x){
			if (a.y == A.a.y){
				if (b.x == A.b.x)return b.y < A.b.y;
				return b.x < A.b.x;
			}
			return a.y < A.a.y;
		}
		return a.x < A.a.x;
	}
};

char str[100003];

int main() {
	int n;
	char c;
	scanf("%d", &n);

	set<Node> V;
	set<Edge> E;

	Node a{ 0, 0 };

	scanf("%s", str);
	V.insert(a);

	for (int i = 0; i < n; i++) {
		for (int x = 0; x < 8; x++){
			int k = str[i] - '0';
			Node b{ a.x + dx[k], a.y + dy[k] };
			V.insert(b);
			Edge ab(a, b);
			E.insert(ab);
			a = b;
		}
	}

	printf("%d\n", E.size() - V.size() + 1);

}

/*
위상수학에서는 구외 위상적으로 같은 입체도형에 대해
면의 수 f, 변의 수 e, 꼭지점의 수 v에 대하여
v-e+f=2 라는 오일러의 공식이 있다.
*/
