#include <iostream>
#include <math.h>
const int N = 4;    // given N for result

double result[N][N];

int main(){

    double f = 0.0; // 放缩因子
    double r = 0.0; // 倒数填充
    result[0][0] = -1;
    result[1][0] = 1;
    for(int k = 2; k < N; k++)
    {
        f = sqrt((double)k * (double)k - 1.0) / (double)k;
   
        for(int i = 0;i <= k; i++)
        {
            for(int j = 0; j <= k - 1; j++)
            {
                result[i][j] *= f;
            }
        }
        r = -1 / (double)k;
        for(int i = 0; i <= k; i++)
        {
            result[i][k-1] = r;
        }

        for(int j = 0;j <= k-1;j++)
        {
            result[k][j] = 0;
        }
        result[k][k-1] = 1.0;
    }
    for(int row = 0; row < N;row ++,std::cout<<std::endl)
        for(int col = 0;col < N-1;col++)
            printf("%.4lf\t", result[row][col]);

    printf("----------------\n");

    double dataLow = -1.0;
    double dataHigh = 1.0;
    double normalizedHigh = 1.0;
    double normalizedLow = 0.0;

    for(int row = 0; row < N;row ++)
        for(int col = 0;col < N-1;col++)
            result[row][col] = ((result[row][col] - dataLow) / (dataHigh - dataLow))*
            (normalizedHigh - normalizedLow) + normalizedLow;

    for(int row = 0; row < N;row ++,std::cout<<std::endl)
        for(int col = 0;col < N-1;col++)
            printf("%.4lf\t", result[row][col]);

}