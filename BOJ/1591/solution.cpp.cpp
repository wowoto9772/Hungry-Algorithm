#include <stdio.h>

#include <vector>

#include <map>

#include <algorithm>
using namespace std;

int adj[2003][2003];

int indegree[2003], outdegree[2003];
int top;

// 유향 그래프의 인접 행렬 adj 가 주어질 때 오일러 서킷을 계산한다. 

void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 1; there <= top; ++there)
		while (adj[here][there] > 0) {
			adj[here][there]--; // 양쪽 간선을 모두 지운다
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}

// 현재 그래프의 오일러 트레일이나 서킷을 반환한다
vector<int> getEulerTrailOrCircuit() {

	vector<int> circuit;
	// 우선 트레일을 찾아본다: 시작점이 존재하는 경우
	for (int i = 1; i <= top; i++)
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}

	// 아니면 서킷이니, 간선에 인접한 아무 정점에서나 시작한다
	for (int i = 1; i <= top; i++)
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}

	// 모두 실패한 경우 빈 배열을 반환한다
	return circuit;
}


vector <int> solve() {

	vector<int> circuit = getEulerTrailOrCircuit();

	// 아닌 경우 방문 순서를 뒤집은 뒤 간선들을 모아 정답을 출력
	reverse(circuit.begin(), circuit.end());

	return circuit;
}

map < int, vector <int> > dmp;
map < vector <int>, int > mp;

int n, m;

void make_graph() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n - m + 1; i++) {

		vector <int> p;

		for (int i = 1; i < m; i++) {

			int a;
			scanf("%d", &a);

			p.push_back(a);

		}

		if (!mp[p]) {
			mp[p] = ++top;
			dmp[top] = p;
		}

		int x = mp[p];

		int k;
		scanf("%d", &k);

		vector <int> q = p;
		q.erase(q.begin());
		q.push_back(k);

		if (!mp[q]) {
			mp[q] = ++top;
			dmp[top] = q;
		}

		int y = mp[q];

		adj[x][y]++;

		outdegree[x]++;
		indegree[y]++;

	}

}

int main() {

	make_graph();

	vector <int> ans = solve();

	for (int i = 0; i < dmp[ans[0]].size() - 1; i++) {
		printf("%d ", dmp[ans[0]][i]);
	}

	for (int i = 0; i < ans.size(); i++) {
		int c = ans[i];
		printf("%d ", dmp[c].back());
	}

}