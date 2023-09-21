#include <fstream>
#include <vector>
using namespace std;

class InParser {
    vector<char> str;
    int ptr;
    ifstream fin;

    char getChar() {
        if (ptr == int(str.size())) {
            fin.read(str.data(), str.size());
            ptr = 0;
        }
        return str[ptr++];
    }

    template<class T>
    T getInt() {
        char chr = getChar();
        while (!isdigit(chr) && chr != '-')
            chr = getChar();
        int sgn = +1;
        if (chr == '-') {
            sgn = -1;
            chr = getChar();
        }
        T num = 0;
        while (isdigit(chr)) {
            num = num * 10 + chr - '0';
            chr = getChar();
        }
        return sgn * num;
    }

public:
    InParser(const char* name) : str(1e5), ptr(str.size()), fin(name) { }
    ~InParser() { fin.close(); }

    template<class T>
    friend InParser& operator>>(InParser& in, T& num) {
        num = in.getInt<T>();
        return in;
    }
};

class OutParser {
    vector<char> str;
    int ptr;
    ofstream fout;

    void putChar(char chr) {
        if (ptr == int(str.size())) {
            fout.write(str.data(), str.size());
            ptr = 0;
        }
        str[ptr++] = chr;
    }

    template<class T>
    void putInt(T num) {
        if (num < 0) {
            putChar('-');
            num *= -1;
        }
        if (num > 9)
            putInt(num / 10);
        putChar(num % 10 + '0');
    }

public:
    OutParser(const char* name) : str(1e5), ptr(0), fout(name) { }
    ~OutParser() { fout.write(str.data(), ptr); fout.close(); }

    template<class T>
    friend OutParser& operator<<(OutParser& out, const T num) {
        out.putInt(num);
        return out;
    }

    friend OutParser& operator<<(OutParser& out, const char chr) {
        out.putChar(chr);
        return out;
    }

    friend OutParser& operator<<(OutParser& out, const char* str) {
        for (int i = 0; str[i]; i++)
            out.putChar(str[i]);
        return out;
    }
};

InParser fin("bogdan.in");
OutParser fout("bogdan.out");

#define Dim 100001

int A[4 * Dim];
int B[Dim];
int n, m, t, x, y;
int sum = 0;

void Update(int nod, int st, int dr, int poz, int val);
void Query(int nod, int st, int dr, int a, int b);

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> B[i];
        if (B[i] < B[i - 1])
            Update(1, 1, n, i, 1);
        else
            Update(1, 1, n, i, 0);
    }

    fin >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> t >> x >> y;
        if (t == 1)
        {
            B[x] = y;
            if (B[x] < B[x - 1])
                Update(1, 1, n, x, 1);
            else
                Update(1, 1, n, x, 0);

            if (B[x + 1] < B[x])
                Update(1, 1, n, x + 1, 1);
            else
                Update(1, 1, n, x + 1, 0);
        }

        else
        {
            sum = 0;
            Query(1, 1, n, x + 1, y);
            if (!sum) fout << "DA\n";
            else fout << "NU\n";
        }
    }

    return 0;
}

void Update(int nod, int st, int dr, int poz, int val)
{
    if (st == dr)
    {
        A[nod] = val;
        return;
    }

    int mid = (st + dr) / 2;
    if (poz <= mid)
        Update(2 * nod, st, mid, poz, val);
    if (poz > mid)
        Update(2 * nod + 1, mid + 1, dr, poz, val);

    A[nod] = A[2 * nod] + A[2 * nod + 1];
}

void Query(int nod, int st, int dr, int a, int b)
{
    if (a <= st && dr <= b)
    {
        sum += A[nod];
        return;
    }

    int mid = (st + dr) / 2;

    if (a <= mid)
        Query(2 * nod, st, mid, a, b);
    if (b > mid)
        Query(2 * nod + 1, mid + 1, dr, a, b);
}