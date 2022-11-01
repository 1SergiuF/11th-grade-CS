#include <iostream>
using namespace std;

int n, S;
int x[20], v[20], c[20];

void CitesteDate();
void Back(int k, int s);
bool Ok(int k);
void ScrieSol(int k);

int main()
{
    CitesteDate();
    Back(1, 0);
    return 0;
}

void CitesteDate()
{
    cin >> n >> S;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    for (int i = 1; i <= n; ++i)
        cin >> c[i];
}

void Back(int k, int s)
{
    if (k > n)
    {
        if (s == S)
        {
            ScrieSol(k);
            exit(0);
        }
        
        return;
    }

    for (int i = 0; s + i * v[k] <= S; ++i)
    {
        x[k] = i;
        if (Ok(k))
            Back(k + 1, s + i * v[k]);
    }
}

bool Ok(int k)
{
    if (x[k] > c[k]) return false;

    return true;
}

void ScrieSol(int k)
{
    for (int i = 1; i < k; ++i)
        cout << x[i] << ' ';
    cout << '\n';
}