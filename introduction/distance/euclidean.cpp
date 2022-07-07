#include <iostream>
#include <cmath>

const int N = 3; //length or dimension
double v1[N],v2[N];
double euclidean(double pos1[], double pos2[])
{
    double sum = 0.0;
    double d = 0.0;
    for(int i = 0;i < N;i++)
    {
        d = pos1[i] - pos2[i];
        sum = sum + d * d;
    }
    return sqrt(sum);
}

int main(){
    int n = 3;
    while(--n)
    {
        v1[n] = n;
        v2[n] = n + 10;
    }
    std::cout << euclidean(v1,v2);
}