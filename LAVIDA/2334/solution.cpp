//#include <functional>
//#include <queue>
//#include <limits>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// precondition: there is no negative cycle.
//// usage:
////  MinCostFlow mcf(n);
////  for(each edges) mcf.addEdge(from, to, cost, capacity);
////  mcf.solve(source, sink); // min cost max flow
////  mcf.solve(source, sink, 0); // min cost flow
////  mcf.solve(source, sink, goal_flow); // min cost flow with total_flow >= goal_flow if possible
//struct MinCostFlow
//{
//	typedef int cap_t;
//	typedef int cost_t;
//
//	bool iszerocap(cap_t cap) { return cap == 0; }
//
//	struct edge {
//		int target;
//		cost_t cost;
//		cap_t residual_capacity;
//		cap_t orig_capacity;
//		size_t revid;
//	};
//
//	int n;
//	vector<vector<edge>> graph;
//	vector<cost_t> pi;
//	bool needNormalize, ranbefore;
//	int lastStart;
//
//	MinCostFlow(int n) : graph(n), n(n), pi(n, 0), needNormalize(false), ranbefore(false) {}
//	void addEdge(int s, int e, cost_t cost, cap_t cap)
//	{
//		if (s == e) return;
//		edge forward = { e, cost, cap, cap, graph[e].size() };
//		edge backward = { s, -cost, 0, 0, graph[s].size() };
//		if (cost < 0 || ranbefore) needNormalize = true;
//		graph[s].emplace_back(forward);
//		graph[e].emplace_back(backward);
//	}
//	bool normalize(int s) {
//		auto infinite_cost = numeric_limits<cost_t>::max();
//		vector<cost_t> dist(n, infinite_cost);
//		dist[s] = 0;
//		queue<int> q;
//		vector<int> v(n), relax_count(n);
//		v[s] = 1; q.push(s);
//		while (!q.empty()) {
//			int cur = q.front();
//			v[cur] = 0; q.pop();
//			if (++relax_count[cur] >= n) return false;
//			for (const auto &e : graph[cur]) {
//				if (iszerocap(e.residual_capacity)) continue;
//				auto next = e.target;
//				auto ncost = dist[cur] + e.cost;
//				if (dist[next] > ncost) {
//					dist[next] = ncost;
//					if (v[next]) continue;
//					v[next] = 1; q.push(next);
//				}
//			}
//		}
//		for (int i = 0; i < n; i++) pi[i] = dist[i];
//		return true;
//	}
//
//	pair<cost_t, cap_t> AugmentShortest(int s, int e, cap_t flow_limit) {
//		auto infinite_cost = numeric_limits<cost_t>::max();
//		auto infinite_flow = numeric_limits<cap_t>::max();
//		typedef pair<cost_t, int> pq_t;
//		priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq;
//		vector<pair<cost_t, cap_t>> dist(n, make_pair(infinite_cost, 0));
//		vector<int> from(n, -1), v(n);
//
//		if (needNormalize || (ranbefore && lastStart != s))
//			normalize(s);
//		ranbefore = true;
//		lastStart = s;
//
//		dist[s] = pair<cost_t, cap_t>(0, infinite_flow);
//		pq.emplace(dist[s].first, s);
//		while (!pq.empty()) {
//			auto cur = pq.top().second; pq.pop();
//			if (v[cur]) continue;
//			v[cur] = 1;
//			if (cur == e) continue;
//			for (const auto &e : graph[cur]) {
//				auto next = e.target;
//				if (v[next]) continue;
//				if (iszerocap(e.residual_capacity)) continue;
//				auto ncost = dist[cur].first + e.cost - pi[next] + pi[cur];
//				auto nflow = min(dist[cur].second, e.residual_capacity);
//				if (dist[next].first <= ncost) continue;
//				dist[next] = make_pair(ncost, nflow);
//				from[next] = e.revid;
//				pq.emplace(dist[next].first, next);
//			}
//		}
//		/** augment the shortest path **/
//		auto p = e;
//		auto pathcost = dist[p].first + pi[p] - pi[s];
//		auto flow = dist[p].second;
//		if (iszerocap(flow) || (flow_limit <= 0 && pathcost >= 0)) return pair<cost_t, cap_t>(0, 0);
//		if (flow_limit > 0) flow = min(flow, flow_limit);
//		/* update potential */
//		for (int i = 0; i < n; i++) {
//			if (iszerocap(dist[i].second)) continue;
//			pi[i] += dist[i].first;
//		}
//		while (from[p] != -1) {
//			auto nedge = from[p];
//			auto np = graph[p][nedge].target;
//			auto fedge = graph[p][nedge].revid;
//			graph[p][nedge].residual_capacity += flow;
//			graph[np][fedge].residual_capacity -= flow;
//			p = np;
//		}
//		return make_pair(pathcost * flow, flow);
//	}
//
//	pair<cost_t, cap_t> solve(int s, int e, cap_t flow_minimum = numeric_limits<cap_t>::max()) {
//		cost_t total_cost = 0;
//		cap_t total_flow = 0;
//		for (;;) {
//			auto res = AugmentShortest(s, e, flow_minimum - total_flow);
//			if (res.second <= 0) break;
//			total_cost += res.first;
//			total_flow += res.second;
//		}
//		return make_pair(total_cost, total_flow);
//	}
//};
//
//#define min(a, b) (a < b ? a : b)
//#define max(a, b) (a > b ? a : b)
//
//int main(){
//	freopen("test.in", "r", stdin);
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int v, e;
//		scanf("%d %d", &v, &e);
//		MinCostFlow mcmf((v + e) * 2 + 2);
//
//		int x[2][404], y[2][404], s[404];
//		for (int i = 1; i <= v + e; i++){
//			scanf("%d %d %d %d %d", &x[0][i], &y[0][i], &x[1][i], &y[1][i], &s[i]);
//			for (int j = 1; j < i; j++){
//				if (x[0][i] == x[1][i]){ // vertical
//					if (x[0][j] == x[1][j]){ // vertical
//						if (x[0][i] == x[0][j]){
//							int my = min(y[0][i], y[1][i]);
//							int My = max(y[0][i], y[1][i]);
//							if (my <= y[0][j] && y[0][j] <= My || my <= y[1][j] && y[1][j] <= My){
//								// meet i, j
//								mcmf.addEdge(v + e + j, i, -s[i] * s[j], 1);
//							}
//						}
//					}
//					else{ // horizontal
//						int mx = min(x[0][j], x[1][j]);
//						int Mx = max(x[0][j], x[1][j]);
//						if (mx <= x[0][i] && x[0][i] <= Mx){
//							int my = min(y[0][i], y[1][i]);
//							int My = max(y[0][i], y[1][i]);
//							if (my <= y[0][j] && y[0][j] <= My){
//								// meet i, j
//								mcmf.addEdge(v + e + j, i, -s[i] * s[j], 1);
//							}
//						}
//					}
//				}
//				else{ // horizontal
//					if (x[0][j] == x[1][j]){ // vertical
//						int my = min(y[0][j], y[1][j]);
//						int My = max(y[0][j], y[1][j]);
//						if (my <= y[0][i] && y[0][i] <= My){
//							int mx = min(x[0][i], x[1][i]);
//							int Mx = max(x[0][i], x[1][i]);
//							if (mx <= x[0][j] && x[0][j] <= Mx){
//								// meet i, j
//								mcmf.addEdge(v + e + j, i, -s[i] * s[j], 1);
//							}
//						}
//					}
//					else{ // horizontal
//						if (y[0][i] == y[0][j]){
//							int mx = min(x[0][i], x[1][i]);
//							int Mx = max(x[0][i], x[1][i]);
//							if (mx <= x[0][j] && x[0][j] <= Mx || mx <= x[1][j] && x[1][j] <= Mx){
//								// meet i, j
//								mcmf.addEdge(v + e + j, i, -s[i] * s[j], 1);
//							}
//						}
//					}
//				}
//			}
//		}
//
//		for (int i = 1; i <= v + e; i++){
//			mcmf.addEdge(0, v + e + i, 0, 1); // link to source
//			mcmf.addEdge(i, (v + e) * 2 + 1, 0, 1); // link to sink
//		}
//
//		pair <int, int> ans = mcmf.solve(0, (v + e) * 2 + 1);
//		printf("%d %d\n", ans.second, -ans.first);
//	}
//}

#include <functional>
#include <queue>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

// precondition: there is no negative cycle.
// usage:
//  MinCostFlow mcf(n);
//  for(each edges) mcf.addEdge(from, to, cost, capacity);
//  mcf.solve(source, sink); // min cost max flow
//  mcf.solve(source, sink, 0); // min cost flow
//  mcf.solve(source, sink, goal_flow); // min cost flow with total_flow >= goal_flow if possible
struct MinCostFlow
{
	typedef int cap_t;
	typedef int cost_t;

	bool iszerocap(cap_t cap) { return cap == 0; }

	struct edge {
		int target;
		cost_t cost;
		cap_t residual_capacity;
		cap_t orig_capacity;
		size_t revid;
	};

	int n;
	vector<vector<edge>> graph;
	vector<cost_t> pi;
	bool needNormalize, ranbefore;
	int lastStart;

	MinCostFlow(int n) : graph(n), n(n), pi(n, 0), needNormalize(false), ranbefore(false) {}
	void addEdge(int s, int e, cost_t cost, cap_t cap)
	{
		if (s == e) return;
		edge forward = { e, cost, cap, cap, graph[e].size() };
		edge backward = { s, -cost, 0, 0, graph[s].size() };
		if (cost < 0 || ranbefore) needNormalize = true;
		graph[s].emplace_back(forward);
		graph[e].emplace_back(backward);
	}
	bool normalize(int s) {
		auto infinite_cost = numeric_limits<cost_t>::max();
		vector<cost_t> dist(n, infinite_cost);
		dist[s] = 0;
		queue<int> q;
		vector<int> v(n), relax_count(n);
		v[s] = 1; q.push(s);
		while (!q.empty()) {
			int cur = q.front();
			v[cur] = 0; q.pop();
			if (++relax_count[cur] >= n) return false;
			for (const auto &e : graph[cur]) {
				if (iszerocap(e.residual_capacity)) continue;
				auto next = e.target;
				auto ncost = dist[cur] + e.cost;
				if (dist[next] > ncost) {
					dist[next] = ncost;
					if (v[next]) continue;
					v[next] = 1; q.push(next);
				}
			}
		}
		for (int i = 0; i < n; i++) pi[i] = dist[i];
		return true;
	}

	pair<cost_t, cap_t> AugmentShortest(int s, int e, cap_t flow_limit) {
		auto infinite_cost = numeric_limits<cost_t>::max();
		auto infinite_flow = numeric_limits<cap_t>::max();
		typedef pair<cost_t, int> pq_t;
		priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq;
		vector<pair<cost_t, cap_t>> dist(n, make_pair(infinite_cost, 0));
		vector<int> from(n, -1), v(n);

		if (needNormalize || (ranbefore && lastStart != s))
			normalize(s);
		ranbefore = true;
		lastStart = s;

		dist[s] = pair<cost_t, cap_t>(0, infinite_flow);
		pq.emplace(dist[s].first, s);
		while (!pq.empty()) {
			auto cur = pq.top().second; pq.pop();
			if (v[cur]) continue;
			v[cur] = 1;
			if (cur == e) continue;
			for (const auto &e : graph[cur]) {
				auto next = e.target;
				if (v[next]) continue;
				if (iszerocap(e.residual_capacity)) continue;
				auto ncost = dist[cur].first + e.cost - pi[next] + pi[cur];
				auto nflow = min(dist[cur].second, e.residual_capacity);
				if (dist[next].first <= ncost) continue;
				dist[next] = make_pair(ncost, nflow);
				from[next] = e.revid;
				pq.emplace(dist[next].first, next);
			}
		}
		/** augment the shortest path **/
		auto p = e;
		auto pathcost = dist[p].first + pi[p] - pi[s];
		auto flow = dist[p].second;
		if (iszerocap(flow) || (flow_limit <= 0 && pathcost >= 0)) return pair<cost_t, cap_t>(0, 0);
		if (flow_limit > 0) flow = min(flow, flow_limit);
		/* update potential */
		for (int i = 0; i < n; i++) {
			if (iszerocap(dist[i].second)) continue;
			pi[i] += dist[i].first;
		}
		while (from[p] != -1) {
			auto nedge = from[p];
			auto np = graph[p][nedge].target;
			auto fedge = graph[p][nedge].revid;
			graph[p][nedge].residual_capacity += flow;
			graph[np][fedge].residual_capacity -= flow;
			p = np;
		}
		return make_pair(pathcost * flow, flow);
	}

	pair<cost_t, cap_t> solve(int s, int e, cap_t flow_minimum = numeric_limits<cap_t>::max()) {
		cost_t total_cost = 0;
		cap_t total_flow = 0;
		for (;;) {
			auto res = AugmentShortest(s, e, flow_minimum - total_flow);
			if (res.second <= 0) break;
			total_cost += res.first;
			total_flow += res.second;
		}
		return make_pair(total_cost, total_flow);
	}
};

class point{
public:
	int x, y;
	bool operator<(const point &A)const{
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
};

#define ll long long
int ccw(point &a, point &b, point &c) {
	ll dx1, dx2, dy1, dy2;
	dx1 = b.x - a.x;
	dy1 = b.y - a.y;
	dx2 = c.x - b.x;
	dy2 = c.y - b.y;

	ll ret = dx1*dy2 - dx2*dy1;
	if (ret < 0)return -1;
	else if (ret > 0)return 1;
	else
		return 0;
}

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int v, e;
		scanf("%d %d", &v, &e);
		MinCostFlow mcmf((v + e) * 2 + 2);

		point px[404], py[404];
		int s[404];
		for (int i = 1; i <= v + e; i++){
			scanf("%d %d %d %d %d", &px[i].x, &px[i].y, &py[i].x, &py[i].y, &s[i]);
			for (int j = 1; j < i; j++){
				if (ccw(px[i], py[i], px[j]) * ccw(px[i], py[i], py[j]) < 0 && ccw(px[j], py[j], px[i]) * ccw(px[j], py[j], py[i]) < 0){
					mcmf.addEdge(v + e + j, i, -s[i] * s[j], 1);
				}
				else if (ccw(px[i], py[i], px[j]) * ccw(px[i], py[i], py[j]) < 0 && ccw(px[j], py[j], px[i]) * ccw(px[j], py[j], py[i]) <= 0){
					mcmf.addEdge(v + e + j, i, -s[i] * s[j], 1);
				}
				else if (ccw(px[i], py[i], px[j]) * ccw(px[i], py[i], py[j]) <= 0 && ccw(px[j], py[j], px[i]) * ccw(px[j], py[j], py[i]) < 0){
					mcmf.addEdge(v + e + j, i, -s[i] * s[j], 1);
				}
				else{
					// never an endpoint of the line segments.
				}
			}
		}

		for (int i = 1; i <= v + e; i++){
			mcmf.addEdge(0, v + e + i, 0, 1); // link to source
			mcmf.addEdge(i, (v + e) * 2 + 1, 0, 1); // link to sink
		}

		pair <int, int> ans = mcmf.solve(0, (v + e) * 2 + 1);
		printf("%d %d\n", ans.second, -ans.first);
	}
}