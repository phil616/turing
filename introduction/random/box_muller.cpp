#include <iostream>
#include <cmath>
#include <ctime>
const int N = 100;
bool useLast = false;
double i_y1,i_y2;
double x1,x2;
double w;

double box_muller()
{
    if(useLast)
    {
        i_y1 = i_y2;
        useLast = false;
    }else
    {
        do{
            x1 = 2.0 * (rand() % (1000) / (double)(1000)) - 1.0;
            x2 = 2.0 * (rand() % (1000) / (double)(1000)) - 1.0;
            w = x1 * x1 + x2 * x2;
        }while(w >= 1.0);
        w = sqrt( (-2.0 * log(w)) / w);
        i_y1 = x1 * w;
        i_y2 = x2 * w;
        useLast = true;
    }
    return i_y1;
}

int main(){

//  srand((unsigned int)time(NULL));
    double X_U_arr[N];
    double X_N_arr[N];
    for(int i = 0;i < N;i++)
    {
        X_N_arr[i] = box_muller();
        X_U_arr[i] = rand() % (1000) / (double)(1000);
    }
    printf("Uniform distribution\n");
    for(int i = 0;i < N;i++)
        printf("%.3lf,",X_U_arr[i]);
    printf("\n\nNormal distribution\n");
    for(int i = 0;i < N;i++)
        printf("%.3lf,",X_N_arr[i]);
        


}