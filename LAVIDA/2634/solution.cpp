#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

class ele{
public:
	int p;
	double t;
};

double x[103], y[103];
vector <ele> lnk[103];
const double r = 50.0;
double d[103] = { 0.0 };

int main(){
	for (int i = 0; i <= 1; i++)scanf("%lf %lf", &x[i], &y[i]);
	int n;
	scanf("%d", &n);
	x[1 + n] = x[1], y[1 + n] = y[1];

	for (int i = 1; i <= n; i++)scanf("%lf %lf", &x[i], &y[i]);

	ele psh, pop;
	for (int i = 0; i <= n; i++){
		for (int j = 1; j <= n + 1; j++){
			if (i == j)continue;

			psh.p = j;

			double dist = (x[i] - x[j])*(x[i] - x[j]), cst;
			dist += (y[i] - y[j])*(y[i] - y[j]);

			if (i != 0){
				if (dist <= r*r + 0.005 * 0.005){
					dist = sqrt(dist);
					cst = 2.0 + (r - dist) / 5.0;
					psh.t = cst;
				}
				else{
					dist = sqrt(dist);
					cst = 2.0 + (dist - r) / 5.0;
					psh.t = cst;
				}
			}
			else{
				dist = sqrt(dist);
				cst = dist;
				psh.t = cst / 5.0;
			}
			lnk[i].push_back(psh);
		}

	}
	for (int i = 1; i <= n + 1; i++)d[i] = 10000000000000000LL;

	queue <ele> q;
	psh.p = 0, psh.t = 0.0;
	q.push(psh);

	while (!q.empty()){
		pop = q.front(); q.pop();

		for (int i = 0; i < lnk[pop.p].size(); i++){
			psh = lnk[pop.p][i];
			double ncst = pop.t + psh.t;
			if (d[psh.p] > ncst){
				d[psh.p] = ncst;
				psh.t = d[psh.p];
				q.push(psh);
			}
		}
	}

	//printf("%lf\n", d[n + 1]);
	printf("%.6lf\n", d[n + 1]);
}

/*
	answer must be accurate to within 0.001 seconds
	can run 5 metes per sec
	climbing into a cannon, launching yourself and landing takes a total of 2 seconds
	cannons are not obstacles;
*/