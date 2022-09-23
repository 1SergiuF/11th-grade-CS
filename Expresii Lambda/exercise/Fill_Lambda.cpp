#include <fstream>
#include <algorithm>

std::basic_ifstream<char> fin("fill.in");
std::basic_ofstream<char> fout("fill.out");

int main()
{
    const int Dim = 101;
    int foto[Dim][Dim];
    int n, m;
    int c[Dim][Dim];
    int ob = 0;

    auto CitesteDate = [&n, &m, &foto]()
    {
        fin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                fin >> foto[i][j];
    };

    auto Ok = [n, m, c, foto](int i, int j) -> bool
    {
        if (i < 1 or i > n or j < 1 or j > m)
            return false;

        if (c[i][j]) return false;
        if (foto[i][j] == 0) return false;

        return true;
    };

    auto Fill = [&c, &ob, &Ok](int i, int j, auto&& Fill)
    {
        if (!Ok(i, j)) return;
        c[i][j] = ob;

        Fill(i - 1, j, Fill);
        Fill(i, j + 1, Fill);
        Fill(i + 1, j, Fill);
        Fill(i, j - 1, Fill);
    };

    auto NumaraObiecte = [&]()
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (foto[i][j] == 1 and !c[i][j])
                {
                    ++ob;
                    Fill(i, j, Fill);
                }
    };

    CitesteDate();
    NumaraObiecte();

    fout << ob;
}