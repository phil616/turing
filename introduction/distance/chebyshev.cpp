#include <iostream>

#include <cmath>

const int N = 3; //length or dimension
double v1[N],v2[N];
double max(double a,double b){return a>b?a:b;}

double chebyshev(double pos1[], double pos2[])
{
    double result = 0.0;
    double d = 0.0;
    for(int i = 0;i < N;i++)
    {
        d = abs(pos1[i] - pos2[i]);
        result = max(result, d);
    }
    return result;
}

int main(){
    int n = 3;
    while(--n)
    {
        v1[n] = n;
        v2[n] = n + 10;
    }
    std::cout << chebyshev(v1,v2) <<std::endl;
}