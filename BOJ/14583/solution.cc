#include <cstdio>
#include <cmath>

using namespace std;
using ll = long long;

int main(){

    double H, V;
    scanf("%lf %lf", &H, &V);

    double D = sqrt(H*H+V*V);
    double a = sqrt((D*D-H*H) / ((H+D)*(H+D)) * H*H);
    double b = V-a;
    double M = sqrt(H*H+a*a);
    double k = b*H / M;

    printf("%.2lf %.2lf\n", M*0.5, k);

}
