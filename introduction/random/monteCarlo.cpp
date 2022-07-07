#include <iostream>
#include <cmath>
#include <ctime>
const int N = 100000;
int main(){

    srand((unsigned int)time(NULL));
    double tries = 0;
    double success = 0;
    double x,y;
    for(int i = 0;i < N;i++){
        x = (rand() % (100) / (double)(100));
        y = (rand() % (100) / (double)(100));
        tries++;
        if(x*x+y*y<=1){
            success++;
        }
        double pi = 4.0 * (double)success / (double)tries;
        printf("%.10lf\n",pi);
    }


}