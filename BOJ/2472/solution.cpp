////////////#include <stdio.h>
////////////#include <algorithm>
////////////
////////////using namespace std;
////////////
////////////int y[103];
////////////
////////////double intersec(int a, int b, int m, int n){
////////////	double dx = (b - a);
////////////	double dy = (y[b] - y[a]);
////////////
////////////	double dx2 = (n - m);
////////////	double dy2 = (y[n] - y[m]);
////////////
////////////	{ // 직선의 방정식
////////////		double m1 = dy / dx; // (a, y[a])
////////////		double m2 = dy2 / dx2; // (m, y[m]);
////////////		double x = (m1*a + y[m] - y[a] - m2*m) / (m1 - m2);
////////////
////////////		if (x < 0)return 100000000;
////////////		else if (x > 100)return 100000000;
////////////
////////////		int left = x;
////////////		int right = x + 1;
////////////
////////////		double bl = x - left;
////////////		double br = 1 - bl; // bl : br 내분점
////////////
////////////		double real_y = (bl*y[right] + br*y[left]) / (bl + br);
////////////
////////////		double rety = m1*(x - a) + y[a] - real_y;
////////////
////////////		if (rety < 0)return 100000000;
////////////
////////////		return rety;
////////////	}
////////////}
////////////
////////////int main(){
////////////	int t;
////////////	scanf("%d", &t);
////////////
////////////	while (t--){
////////////		int n;
////////////		scanf("%d", &n);
////////////
////////////		for (int i = 0; i <= n; i++){
////////////			scanf("%d", &I[i].y);
////////////		}
////////////
////////////		printf("%.4lf\n", intersec(0, 1, 9, 12));
////////////
////////////		double ans = 100000000;
////////////		for (int i = 0; i <= n; i++){
////////////			for (int j = i+1; j <= n; j++){
////////////				for (int a = n; a >= 0; a--){
////////////					for (int b = a-1; b >= 0; b--){
////////////						if (i == b || j == a)continue;
////////////						else if (i == a || b == j)continue;
////////////						else if (I[i].y <= I[j].y && y[b] >= y[a]){
////////////							double hi = intersec(i, j, b, a);
////////////							if (hi < ans){
////////////							}
////////////						}
////////////						else if (I[i].y >= I[j].y && y[b] <= y[a]){
////////////							double hi = intersec(i, j, b, a);
////////////							ans = min(ans, hi);
////////////						}
////////////					}
////////////				}
////////////			}
////////////		}
////////////
////////////		printf("%.3lf\n", ans);
////////////	}
////////////}
////////////
/////////////*
////////////	2
////////////	13
////////////	5 4 3 1 0 3 4 4 2 5 4 3 4 6
////////////*/
////////////
//////////
//////////#include <stdio.h>
//////////#include <algorithm>
//////////#include <vector>
//////////#include <time.h>
//////////#include <Windows.h>
//////////
//////////#define ll long long
//////////#define MOD 1000000007
//////////
//////////using namespace std;
//////////
//////////class ele{
//////////public:
//////////	int p, d;
//////////	bool operator<(const ele &A)const{
//////////		if (p == A.p)return d < A.d;
//////////		return p < A.p;
//////////	}
//////////}I[13];
//////////
//////////int tot[1000003];
//////////
//////////int main(){
//////////
//////////	int tme = 80;
//////////	while (true){
//////////		printf("%d\n", tme--);
//////////		Sleep(1000);
//////////	}
//////////
//////////	freopen("inputS094.txt", "r", stdin);
//////////	freopen("inputS094.out", "w", stdout);
//////////
//////////	ll f[13] = { 1 };
//////////	for (int i = 1; i <= 10; i++)f[i] = f[i - 1] * i;
//////////	ll c[13][13] = { 0 };
//////////	c[0][0] = 1;
//////////	for (int i = 1; i <= 10; i++){
//////////		c[i][0] = 1;
//////////		for (int j = 1; j <= i; j++){
//////////			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
//////////		}
//////////	}
//////////
//////////	int t;
//////////	scanf("%d", &t);
//////////
//////////	while (t--){
//////////		int n, m;
//////////		scanf("%d %d", &n, &m);
//////////
//////////		for (int i = 0; i < n; i++){
//////////			scanf("%d", &I[i].p);
//////////			tot[I[i].p]++;
//////////		}
//////////		
//////////		for (int i = 0; i < n; i++){
//////////			scanf("%d", &I[i].d); // small : m
//////////		}
//////////
//////////		sort(I, I + n);
//////////
//////////		ll ans = 0;
//////////
//////////		vector <int> x;
//////////		for (int i = n - 1; i >= 0; i--){
//////////			if (I[i].d <= m){
//////////				if (x.size() == m){
//////////					break;
//////////				}
//////////				x.push_back(I[i].p);
//////////			}
//////////		}
//////////
//////////		if (x.size()){
//////////			ans = f[x.size()];
//////////
//////////			for (int i = 0; i < x.size(); i++){
//////////				for (int j = i; j < x.size(); j++){
//////////					if (I[i].x != I[j].x){
//////////						ans /= f[(j - i)];
///////////*						for (int k = j - i; k >= 1; k--){
//////////							ans *= tot[I[i].x];
//////////							tot[I[i].x]--;
//////////						}*/
//////////						i = j - 1;
//////////						break;
//////////					}
//////////					else if (j == x.size() - 1){
//////////						ans /= f[(j - i + 1)];
///////////*						for (int k = j - i + 1; k >= 1; k--){
//////////							ans *= tot[I[i].x];
//////////							tot[I[i].x]--;
//////////						}				*/		
//////////						i = j;
//////////					}
//////////				}
//////////			}
//////////
//////////			if (x.size() != m){
//////////				int ad = m - x.size();
//////////				ans *= c[m][ad];
//////////			}
//////////		}
//////////
//////////		printf("%lld\n", ans % MOD);
//////////
//////////		for (int i = 0; i < n; i++)tot[I[i].p] = 0;
//////////	}
//////////}
////////////////
//////////////////#include <stdio.h>
//////////////////#include <vector>
//////////////////#include <algorithm>
//////////////////
//////////////////using namespace std;
//////////////////
//////////////////struct MaxFlowDinic // V^2 * E
//////////////////{
//////////////////	typedef long long flow_t;
//////////////////
//////////////////	struct Edge
//////////////////	{
//////////////////		int next;
//////////////////		int inv; /* inverse edge index */
//////////////////		flow_t res; /* residual */
//////////////////	};
//////////////////
//////////////////	int n;
//////////////////	vector<vector<Edge>> graph;
//////////////////
//////////////////	vector<unsigned> q, l, start;
//////////////////
//////////////////	vector <bool> vst; // *optional
//////////////////
//////////////////	void Init(int _n){
//////////////////		n = _n;
//////////////////		graph.resize(n);
//////////////////		vst.resize(n); // *optional
//////////////////		for (int i = 0; i < n; i++) graph[i].clear();
//////////////////	}
//////////////////	void AddNodes(int count) {
//////////////////		n += count;
//////////////////		graph.resize(n);
//////////////////	}
//////////////////	void AddEdge(int s, int e, flow_t cap, flow_t caprev = 0) {
//////////////////		Edge forward = { e, graph[e].size(), cap };
//////////////////		Edge reverse = { s, graph[s].size(), caprev };
//////////////////		graph[s].push_back(forward);
//////////////////		graph[e].push_back(reverse);
//////////////////	}
//////////////////
//////////////////	bool AssignLevel(int source, int sink) {
//////////////////		int t = 0;
//////////////////		memset(&l[0], 0, sizeof(l[0]) * l.size());
//////////////////		l[source] = 1;
//////////////////		q[t++] = source;
//////////////////		for (int h = 0; h < t && !l[sink]; h++) {
//////////////////			int cur = q[h];
//////////////////			for (unsigned i = 0; i < graph[cur].size(); i++) {
//////////////////				int next = graph[cur][i].next;
//////////////////				if (l[next]) continue;
//////////////////				if (graph[cur][i].res > 0) {
//////////////////					l[next] = l[cur] + 1;
//////////////////					q[t++] = next;
//////////////////				}
//////////////////			}
//////////////////		}
//////////////////		return l[sink] != 0;
//////////////////	}
//////////////////
//////////////////	flow_t BlockFlow(int cur, int sink, flow_t currentFlow) {
//////////////////		if (cur == sink) return currentFlow;
//////////////////		for (unsigned &i = start[cur]; i < graph[cur].size(); i++) {
//////////////////			int next = graph[cur][i].next;
//////////////////			if (graph[cur][i].res == 0 || l[next] != l[cur] + 1)
//////////////////				continue;
//////////////////			if (flow_t res = BlockFlow(next, sink, min(graph[cur][i].res, currentFlow))) {
//////////////////				int inv = graph[cur][i].inv;
//////////////////				graph[cur][i].res -= res;
//////////////////				graph[next][inv].res += res;
//////////////////				return res;
//////////////////			}
//////////////////		}
//////////////////		return 0;
//////////////////	}
//////////////////
//////////////////	flow_t Solve(int source, int sink)
//////////////////	{
//////////////////		q.resize(n);
//////////////////		l.resize(n);
//////////////////		start.resize(n);
//////////////////		flow_t ans = 0;
//////////////////		while (AssignLevel(source, sink)) {
//////////////////			memset(&start[0], 0, sizeof(start[0])*n);
//////////////////			while (flow_t flow = BlockFlow(source, sink, numeric_limits<flow_t>::max())) {
//////////////////				ans += flow;
//////////////////			}
//////////////////		}
//////////////////		return ans;
//////////////////	}
//////////////////};
//////////////////
//////////////////int r, c;
//////////////////int nod(int x, int y){
//////////////////	return c*(x - 1) + y;
//////////////////}
//////////////////
//////////////////int nodUp(int x, int y){
//////////////////	return r*c + nod(x, y);
//////////////////}
//////////////////
//////////////////int main(){
//////////////////	freopen("inputL082.txt", "r", stdin);
//////////////////	freopen("inputL082.out", "w", stdout);
//////////////////	
//////////////////	int t;
//////////////////	scanf("%d", &t);
//////////////////
//////////////////	while (t--){
//////////////////		int n, k;
//////////////////		scanf("%d %d %d %d", &r, &c, &n, &k);
//////////////////		r++, c++;
//////////////////
//////////////////		bool dis[205][205] = { 0 };
//////////////////
//////////////////		MaxFlowDinic mf;
//////////////////		mf.Init(2 * (r*c) + 3);
//////////////////
//////////////////		int source = 0, sink = r*c * 2 + 1;
//////////////////
//////////////////		for (int i = 0; i < n; i++){
//////////////////			int x, y;
//////////////////			scanf("%d %d", &x, &y);
//////////////////			x++, y++;
//////////////////
//////////////////			mf.AddEdge(source, nod(x, y), 1); // lnk to source
//////////////////		}
//////////////////
//////////////////		for (int i = 0; i < n; i++){
//////////////////			int x, y;
//////////////////			scanf("%d %d", &x, &y); 
//////////////////			x++, y++;
//////////////////
//////////////////			mf.AddEdge(nodUp(x, y), sink, 1); // lnk to sink
//////////////////		}
//////////////////
//////////////////		for (int i = 0; i < k; i++){
//////////////////			int x, y;
//////////////////			scanf("%d %d", &x, &y);
//////////////////			x++, y++;
//////////////////
//////////////////			dis[x][y] = true;
//////////////////		}
//////////////////
//////////////////		int di[] = { 0, 0, -1, 1 };
//////////////////		int dj[] = { -1, 1, 0, 0 };
//////////////////		for (int i = 1; i <= r; i++){
//////////////////			for (int j = 1; j <= c; j++){
//////////////////				if (dis[i][j])continue;
//////////////////				mf.AddEdge(nod(i, j), nodUp(i, j), 1); // upper
//////////////////				for (int a = 0; a < 4; a++){
//////////////////					int ni = i + di[a];
//////////////////					int nj = j + dj[a];
//////////////////					if (ni < 1 || nj < 1 || ni > r || nj > c)continue;
//////////////////					if (dis[ni][nj])continue;
//////////////////					mf.AddEdge(nodUp(i, j), nod(ni, nj), 1);
//////////////////				}
//////////////////			}
//////////////////		}
//////////////////
//////////////////		int flg = mf.Solve(source, sink);
//////////////////
//////////////////		if (flg == n){
//////////////////			printf("1\n");
//////////////////		}
//////////////////		else{
//////////////////			printf("-1\n");
//////////////////		}
//////////////////	}
//////////////////}
//////////////////
///////////////////*
//////////////////2
//////////////////1 1 1 0
//////////////////0 0
//////////////////0 1
//////////////////*/
////////////////
//////////////
//////////////#include <stdio.h>
//////////////#include <algorithm>
//////////////
//////////////using namespace std;
//////////////
//////////////class ele{
//////////////public:
//////////////	int a, b, c;
//////////////	bool operator<(const ele &A)const{
//////////////		return c < A.c;
//////////////	}
//////////////}I[300003];
//////////////
//////////////int p[100003];
//////////////
//////////////int main(){
//////////////	int t;
//////////////	scanf("%d", &t);
//////////////
//////////////	while (t--){
//////////////		int n, m;
//////////////		scanf("%d %d", &n, &m);
//////////////
//////////////		for (int i = 0; i < m; i++){
//////////////			scanf("%d %d %d", &I[i].a, &I[i].b, &I[i].c);
//////////////		}
//////////////
//////////////		for (int i = 1; i < n; i++){
//////////////			int c;
//////////////			scanf("%d", &c);
//////////////			for (int j = 1; j <= c; j++){
//////////////				int a;
//////////////				scanf("%d", &a);
//////////////			}
//////////////		}
//////////////
//////////////		sort(I, I + m);
//////////////
//////////////		int cnt = 0;
//////////////		for (int i = 0; i < m && cnt < n - 1; i++){
//////////////			int a = I[i].a, b = I[i].b;
//////////////			while (p[a])a = p[a];
//////////////			while (p[b])b = p[b];
//////////////			int pa = a, pb = b;
//////////////			a = I[i].a, b = I[i].b;
//////////////			while (p[a]){
//////////////				int k = p[a];
//////////////				p[a] = pa;
//////////////				a = k;
//////////////			}
//////////////			while (p[b]){
//////////////				int k = p[b];
//////////////				p[b] = pb;
//////////////				b = k;
//////////////			}
//////////////			if (a == b)continue;
//////////////			else{
//////////////				p[a] = b;
//////////////				cnt++;
//////////////			}
//////////////		}
//////////////
//////////////		if (cnt == n - 1)printf("1\n");
//////////////		else{
//////////////			printf("0\n");
//////////////		}
//////////////
//////////////		for (int i = 1; i <= n; i++)p[i] = 0;
//////////////	}
//////////////}
////////
////////#include <stdio.h>
////////
////////int main(){
////////	int t;
////////	scanf("%d", &t);
////////
////////	while (t--){
////////		int n;
////////		scanf("%d", &n);
////////
////////		int c[10] = { 0 };
////////
////////		while (n){
////////			c[n % 10]++;
////////			n /= 10;
////////		}
////////
////////		int a = 0;
////////		for (int i = 0; i < 10; i++)if (c[i])a++;
////////
////////		printf("%d\n", a);
////////	}
////////}
//////
//////
//////// Saitama wants Genos to add a beacon strictly 
//////// to the right of all the existing beacons
//////
//////#include <stdio.h>
//////#include <limits.h>
//////#include <algorithm>
//////
//////using namespace std;
//////
//////int dp[100003];
//////
//////class ele{
//////public:
//////	int a, b;
//////	bool operator<(const ele &A)const{
//////		return a < A.a;
//////	}
//////}I[100003];
//////
//////int dy(int h){
//////	if (!h)return 0;
//////	if (dp[h] != -1)return dp[h];
//////
//////	int l = 1, r = h - 1, m = 0;
//////	int cur = I[h].a - I[h].b;
//////
//////	while (l <= r){
//////		m = (l + r) / 2;
//////		if (I[m].a < cur)l = m + 1;
//////		else if (I[m].a >= cur)r = m - 1;
//////	}
//////
//////	if (I[m].a >= cur)m--;
//////	if (m < 0)m = 0;
//////
//////	return dp[h] = h - m - 1 + dy(m);
//////}
//////
//////int main(){
//////
//////	I[0].a = -1000000000;
//////
//////	int n;
//////	scanf("%d", &n);
//////
//////	for (int i = 1; i <= n; i++){
//////		scanf("%d %d", &I[i].a, &I[i].b);
//////		dp[i] = -1;
//////	}
//////
//////	sort(I, I + n + 1);
//////
//////	int ans = INT_MAX;
//////	for (int i = n; i >= 0; i--){
//////		ans = min(ans, n - i + dy(i));
//////	}
//////
//////	printf("%d\n", ans);
//////}
////
//////#include <stdio.h>
//////#include <algorithm>
//////
//////using namespace std;
//////
//////class dat{
//////public:
//////	int x, y;
//////	bool operator<(const dat &A)const{
//////		if (x == A.x)return y < A.y;
//////		return x < A.x;
//////	}
//////}I[2003];
//////
//////class ele{
//////public:
//////	int x, y, d;
//////	ele(){}
//////	ele(int a, int b, int c){ x = a, y = b, d = c; }
//////	bool operator<(const ele &A)const{
//////		if (d == A.d){
//////			if (x == A.x)return y < A.y;
//////			return x < A.x;
//////		}
//////		return d < A.d;
//////	}
//////}L[2000 * 2000 + 3], R[2000 * 2000 + 3];
//////
//////void swp(int *a, int *b){
//////	int t = *a;
//////	*a = *b;
//////	*b = t;
//////}
//////
//////int main(){
//////
//////	int t;
//////	scanf("%d", &t);
//////
//////	int tc = 0;
//////
//////	while (t--){
//////
//////		int n;
//////		scanf("%d", &n);
//////
//////		for (int i = 0; i < n; i++)scanf("%d %d", &I[i].x, &I[i].y);
//////
//////		sort(I, I + n);
//////
//////		int top = 0;
//////
//////		for (int i = 0; i < n; i++){
//////			for (int j = i + 1; j < n; j++){
//////				L[top].x = I[i].x, L[top].y = I[i].y, L[top].d = (I[i].x - I[j].x)*(I[i].x - I[j].x) + (I[i].y - I[j].y)*(I[i].y - I[j].y);
//////				R[top].x = I[j].x, R[top].y = I[j].y, R[top].d = (I[i].x - I[j].x)*(I[i].x - I[j].x) + (I[i].y - I[j].y)*(I[i].y - I[j].y);
//////				top++;
//////			}
//////		}
//////
//////		printf("%d\n", top);
//////
//////		sort(L, L + top);
//////		sort(R, R + top);
//////
//////		int c = 1;
//////
//////		int ans = 0;
//////
//////		for (int i = 0; i < n; i++){
//////			for (int j = 0; j < n; j++){
//////				if (i == j)continue;
//////				int d = (I[i].x - I[j].x)*(I[i].x - I[j].x) + (I[i].y - I[j].y)*(I[i].y - I[j].y);
//////
//////				int x__ = I[j].x, y__ = I[j].y;
//////
//////				ele cmp = ele(x__, y__, d);
//////
//////				int lo = lower_bound(L, L + top, cmp) - L;
//////				int hi = upper_bound(L, L + top, cmp) - L;
//////				hi--;
//////
//////				int cnt = (hi - lo + 1);
//////				if (cnt < 0)cnt = 0;
//////
//////				ans += cnt;
//////
//////				lo = lower_bound(R, R + top, cmp) - R;
//////				hi = upper_bound(R, R + top, cmp) - R;
//////				hi--;
//////
//////				cnt = (hi - lo + 1);
//////				if (cnt <= 0)cnt = 0;
//////				else
//////					cnt--;
//////
//////				ans += cnt;
//////			}
//////		}
//////
//////		printf("Case #%d: %d\n", ++tc, ans);
//////	}
//////
//////}
////
////
////#include <stdio.h>
////#include <algorithm>
////#include <vector>
////
////using namespace std;
////
////int x[2003], y[2003];
////
////int main(){
////
////	freopen("boomerang_constellations.txt", "r", stdin);
////	freopen("boomerang_constellations.out", "w", stdout);
////
////	int t;
////	scanf("%d", &t);
////
////	int tc = 0;
////
////	while (t--){
////
////		int n;
////		scanf("%d", &n);
////
////		for (int i = 0; i < n; i++)scanf("%d %d", &x[i], &y[i]);
////
////		int ans = 0;
////
////		for (int i = 0; i < n; i++){
////			
////			vector <int> tmp;
////
////			for (int j = 0; j < n; j++){
////				int d = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
////				tmp.push_back(d);
////			}
////
////			if (tmp.empty())continue;
////
////			sort(tmp.begin(), tmp.end());
////
////			int c = 1;
////			int S = tmp[0];
////			for (int j = 1; j < tmp.size(); j++){
////				if (tmp[j] == S)c++;
////				else{
////					ans += c * (c - 1) / 2;
////
////					c = 1;
////					S = tmp[j];
////				}
////			}
////
////			ans += c * (c - 1) / 2;
////		}
////
////		printf("Case #%d: %d\n", ++tc, ans);
////	}
////
////}

#include <stdio.h>
#include <limits.h>

#include <queue>
#include <vector>

#include <algorithm>

using namespace std;

class node{
public:
	int a, c;
	node(){}
	node(int a_, int c_){ a = a_, c = c_; }
	bool operator<(const node &A)const{
		return c > A.c;
	}
};

class dat{
public:
	int a, b, c;
	int p;

	dat(){}
	dat(int a_, int b_, int c_, int p_){
		a = a_, b = b_, c = c_, p = p_;
	}

	bool operator<(const dat &A)const{
		return a < A.a;
	}
};

class BIT{
public:
	vector <int> T;
	int S;

	BIT(){}

	BIT(const int n){
		S = n;
		T.resize(S + 1);
	}
	void Update(int p, int v){
		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}
	}
	long long Sum(int p){
		long long ret = 0;
		while (p > 0){
			ret += T[p];
			p -= p & (-p);
		}return ret;
	}
};

int n;

int s[3];
int d[3][100003];
bool chk[100003];

vector <int> ord[3];

int find(int key, int val){
	int l = 0, r = n - 1, md;
	while (l <= r){
		md = (l + r) / 2;
		if (ord[key][md] < d[key][val]){
			l = md + 1;
		}
		else if (ord[key][md] > d[key][val]){
			r = md - 1;
		}
		else{
			return md;
		}
	}
}

int main(){

	scanf("%d", &n);

	for (int i = 0; i < 3; i++)scanf("%d", &s[i]);

	int m;
	scanf("%d", &m);

	vector < vector <node> > lnk;
	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		lnk[a].emplace_back(b, c);
		lnk[b].emplace_back(a, c);
	}

	for (int i = 0; i < 3; i++){

		for (int j = 1; j <= n; j++)chk[j] = false, d[i][j] = INT_MAX;

		priority_queue <node> q;
		q.emplace(s[i], 0);

		d[i][s[i]] = 0;

		while (!q.empty()){

			node f = q.top(); q.pop();

			if (chk[f.a])continue;
			chk[f.a] = true;

			for (int j = 0; j < lnk[f.a].size(); j++){

				node g = lnk[f.a][j];

				if (!chk[g.a] && d[i][g.a] > f.c + g.c){

					g.c += f.c;

					d[i][g.a] = g.c;

					q.emplace(g);

				}

			}

		}

	}

	vector <dat> my;
	my.emplace_back(INT_MIN, INT_MIN, INT_MIN, 0);

	for (int i = 1; i <= n; i++){
		my.emplace_back(d[0][i], d[1][i], d[2][i], i);
		for (int j = 0; j < 3; j++)ord[j].push_back(d[j][i]);
	}

	sort(my.begin(), my.end());

	for (int i = 0; i < 3; i++){
		ord[i].push_back(INT_MIN);
		sort(ord[i].begin(), ord[i].end());
		ord[i].resize(distance(ord[i].begin(), unique(ord[i].begin(), ord[i].end())));
	}

	vector <int> mapping(n + 1);
	for (int i = 1; i <= n; i++){
		mapping[my[i].p] = i;
	}

	int q;
	scanf("%d", &q);

	for (int i = 1; i <= q; i++){

		// U = A + B + C - AB - BC - CA + ABC
		// X = U - A - B - C + AB + BC + CA
		// A : small A
		// B : small B
		// C : small C

		int w;
		scanf("%d", &w);

		int pa = find(0, d[0][w]);
		int pb = find(1, d[1][w]);
		int pc = find(2, d[2][w]);

		int A = S[0].Sum(pa - 1); // small A
		int B = S[1].Sum(pb - 1); // small B
		int C = S[2].Sum(pc - 1); // small C

		int AUB = lower_bound(U[0].begin(), U[0].end(), make_pair(d[0][w], d[1][w])) - U[0].begin() + 1;
		int BUC = lower_bound(U[1].begin(), U[1].end(), make_pair(d[0][w], d[2][w])) - U[1].begin() + 1;
		int AUC = lower_bound(U[2].begin(), U[2].end(), make_pair(d[1][w], d[2][w])) - U[2].begin() + 1;

		int AB = (A + B) - (AUB);
		int AC = (A + C) - (AUC);
		int BC = (B + C) - (BUC);

		int X = n - (A + B + C) + (AB + BC + AC);

		if (X)printf("NO\n");
		else
			printf("YES\n");

	}

}