#include <fstream>
using namespace std;

ifstream fin("biarbore1.in");
ofstream fout("biarbore1.out");

int main()
{
    int root, fs, fd;

    fin >> root >> fs;
    int cnt = 2;
    if (!fs)
        fin >> fd;
    else
    {
        while (cnt)
        {
            int x;
            fin >> x;
            (x == 0) ? --cnt : ++cnt;
        }

        fin >> fd;
    }

    fout << fs << ' ' << fd;

    return 0;
}