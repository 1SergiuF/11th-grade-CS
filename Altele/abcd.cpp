#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << (b / 3 - (a - 1) / 3) + (d / 3 - (c - 1) / 3);

    return 0;
}