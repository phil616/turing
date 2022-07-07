#include <iostream>
#include <cmath>

const int N = 3; //length or dimension
double v1[N],v2[N];
double manhattan(double pos1[], double pos2[])
{
    double sum = 0.0;
    double d = 0.0;
    for(int i = 0;i < N;i++)
    {
        d = abs(pos1[i] - pos2[i]);
        sum = sum + d;
    }
    return sum;
}

int main(){
    int n = 3;
    while(--n)
    {
        v1[n] = n;
        v2[n] = n + 10;
    }
    std::cout << manhattan(v1,v2);
}