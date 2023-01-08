#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI 3.14159265
int main()
{
    double a, b, u;
    cin >> a >> b >> u;

    double c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(u / 180 * PI));
    cout << fixed << setprecision(2) << c;

    return 0;
}