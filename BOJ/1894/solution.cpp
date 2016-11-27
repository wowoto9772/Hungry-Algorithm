#include <cstdio>
#include <algorithm>

using namespace std;

class point{
    public:
        double x, y;
        point(){}
        point(double _x, double _y){
            x = _x, y = _y;
        }

        point operator-(const point &A)const{
            return {x - A.x, y - A.y};
        }
        point operator+(const point &A)const{
            return {x + A.x, y + A.y};
        }
        bool operator==(const point &A)const{
            return (fabs(x - A.x) <= 1e-9) && (fabs(y - A.y) <= 1e-9);
        }
};

int main(){

    point pt[4];
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &pt[0].x, &pt[0].y, &pt[1].x, &pt[1].y, &pt[2].x, &pt[2].y, &pt[3].x, &pt[3].y) == 8){

        if(pt[0] == pt[2]){
           pt[2] = pt[3];
        }
        else if(pt[1] == pt[2]){
            swap(pt[0], pt[1]);
            pt[2] = pt[3];
        }else if(pt[1] == pt[3]){
            swap(pt[0], pt[1]);
        }

        point dt = pt[2] - pt[0];
        point ans = pt[1] + dt;

        printf("%.3lf %.3lf\n", ans.x, ans.y);

    }

}
