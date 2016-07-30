#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long

typedef double rData;
typedef struct Rectangle {
	rData x1, y1;
	rData x2, y2;
} Rectangle;

int rcmp(const void *p, const void *q)
{
	return *(rData *)p > *(rData *)q ? 1 : *(rData *)p < *(rData *)q ? -1 : 0;
}

rData plane_sweeping(Rectangle *rec, int len)
{
	rData x[63];
	rData y[63];

	for (int i = 0; i < len; i++)
	{
		x[i * 2] = rec[i].x1;
		x[i * 2 + 1] = rec[i].x2;
		y[i * 2] = rec[i].y1;
		y[i * 2 + 1] = rec[i].y2;
	}

	int N = len * 2;
	qsort(x, N, sizeof(rData), rcmp);
	qsort(y, N, sizeof(rData), rcmp);

	rData ret = 0;

	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			for (int k = 0; k < len; k++)
				if (rec[k].x1 <= x[i - 1] && x[i] <= rec[k].x2 && rec[k].y1 <= y[j - 1] && y[j] <= rec[k].y2)
				{
					ret += (x[i] - x[i - 1]) * (y[j] - y[j - 1]);
					break;
				}
	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);

	Rectangle rec[33];
	for (int i = 0; i < N; i++)
	{
		scanf("%lf %lf %lf %lf", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2);
		rec[i].x2 += rec[i].x1;
		rec[i].y2 += rec[i].y1;
	}

	double ret = plane_sweeping(rec, N);

	ll _ret = ret * 1000LL;
	_ret += 5;
	_ret /= 10;


	if (_ret % 100)printf("%lld.%lld\n", _ret / 100, _ret % 100);
	else
		printf("%lld\n", _ret / 100);

	return 0;
}