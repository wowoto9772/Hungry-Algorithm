// from https://gtihub.com/kcm1700/algorithms 
// O(n log^2 n) implementation.
// first, sort points by x-coordination
// pass y-sorted vector<point> as argument in order to cut the time complexity down to O(n log n)

#include <cstdio>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

typedef pair<ll, ll> point;

point points[500003];

ll dist(const point &a, const point &b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool bySecond(const point &a, const point &b) {
	return a.second < b.second;
}

// returns the closest squared distance between two points
ll getClosest(int s, int e) {
	ll res = LLONG_MAX;
	if (e - s < 5) {
		for(int i = s; i < e; i++) {
			for(int j = i+1; j < e; j++) {
				res = min(res, dist(points[i],points[j]));
			}
		}
		return res;
	}
	int m = (s+e)/2;
	ll lres = getClosest(s, m);
	ll rres = getClosest(m, e);
	res = min(res, lres);
	res = min(res, rres);

	vector<point> strip;
	for(int i = s; i < e; i ++) {
		if ((points[m].first - points[i].first) * (points[m].first - points[i].first) < res) {
			strip.emplace_back(points[i]);
		}
	}
	sort(strip.begin(), strip.end(), bySecond);
	for(int i = 0; i < strip.size(); i++) {
		for(int j = i + 1; j < strip.size() &&
			(strip[j].second - strip[i].second)*(strip[j].second - strip[i].second) < res; j++) {
			res = min(res, dist(strip[i], strip[j]));
		}
	}
	return res;
}

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)scanf("%lld %lld", &points[i].first, &points[i].second);

    sort(points, points+n, [](const point &a, const point &b){
        return a.first < b.first;
            });

    printf("%lld\n", getClosest(0, n));

}

