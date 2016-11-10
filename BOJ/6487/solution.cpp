#include <cstdio>

using namespace std;

int main()
{
	int t;
    scanf("%d", &t);

	while(t--){
		double x[5], y[5];
        for(int i=1; i<=4; i++)scanf("%lf %lf", &x[i], &y[i]);		
		if((x[2] != x[1]) && (x[4] != x[3])){
			double m1 = (y[2] - y[1]) / (x[2] - x[1]);
			double m2 = (y[4] - y[3]) / (x[4] - x[3]);
			if(m1 != m2){
				double sol_x = (-m2 * x[3] + y[3] + m1 * x[1] - y[1]) / (m1 - m2);
				double sol_y = m2 * (sol_x - x[3]) + y[3];
				printf("POINT %.2lf %.2lf", sol_x, sol_y);
			}
			else if(m1 == m2){
				if(-m1 * x[1] + y[1] == -m2 * x[3] + y[3])printf("LINE");
				else
					printf("NONE");
			}
		}
		else{
			if((x[2] == x[1]) && (x[4] == x[3])){
				if(x[1] == x[3])printf("LINE");
				else
					printf("NONE");
			}
			else{
				if(x[2] == x[1]){
					double sol_x = x[1];
					double m2 = (y[4] - y[3]) / (x[4] - x[3]);
					double sol_y = m2 * (sol_x - x[3]) + y[3];
					printf("POINT %.2lf %.2lf", sol_x, sol_y);
				}
				else if(x[4] == x[3]){
					double sol_x = x[3];
					double m1 = (y[2] - y[1]) / (x[2] - x[1]);
					double sol_y = m1 * (sol_x - x[3]) + y[3];
					printf("POINT %.2lf %.2lf", sol_x, sol_y);
				}
			}
		}
        printf("\n");
	}
}
