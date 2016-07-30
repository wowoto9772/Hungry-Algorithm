#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ele{
public:
	int l, r;
}tree[103];

vector <int> slice(const vector <int> &v, int a, int b){
	return vector <int>(v.begin() + a, v.begin() + b);
}

int Consist(const vector <int> &pre, const vector <int> &in){
	int S = pre.size();
	if (!S)return 0;
	int root = pre[0];
	int L = find(in.begin(), in.end(), root) - in.begin();
	int R = S - 1 - L;
	tree[root].l = Consist(slice(pre, 1, L+1), slice(in, 0, L));
	tree[root].r = Consist(slice(pre, L + 1, S), slice(in, L + 1, S));
	return root;
}

int main()
{
	int n;
	scanf("%d", &n);

	vector <int> pre, in;
	pre.resize(n), in.resize(n);
	for (int i = 0; i < n; i++)scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)scanf("%d", &in[i]);

	Consist(pre, in);

	queue <int> q;
	q.push(pre[0]);
	int c = 0;
	while (!q.empty()){
		int f = q.front();q.pop();
		c++;
		printf("%d", f);
		if (c < n)printf(",");
		if(tree[f].l)q.push(tree[f].l);
		if(tree[f].r)q.push(tree[f].r);
	}
	printf("\n");
}