#include <bits/stdc++.h>
#define float double
using namespace std;

float u_cal(float h, int n)
{
    float temp = h;
    for (int i = 1; i < n; i++)
        temp = temp * (h - i);
    return temp;
}
 
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
 
int main()
{
    int n;
    cin>>n;
    float x[n];
    for(int i = 0; i < n; i++)
    {
        cin>>x[i];
    }

    float y[n][n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>y[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }
 
    for (int i = 0; i < n; i++) {
        cout << setw(4) << x[i]  << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(4) << y[i][j]  << "\t";
        cout << endl;
    }
 
    float value = 1895;
 
    float sum = y[0][0];
    float h = (value - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(h, i) * y[0][i]) / fact(i);
    }
 
    cout << "\n Value at " << value << " is "
         << sum << endl;
    return 0;
}
/*
5
1891 1901 1911 1921 1931 
46 66 81 93 101
1895//value
*/