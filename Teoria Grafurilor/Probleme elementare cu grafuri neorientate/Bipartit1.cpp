#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("bipartit1.in");
ofstream fout("bipartit1.out");

using VB  = vector<bool>;
using VI  = vector<int>;
using VVI = vector<VI>;

VVI G;
VB v, p;
int n, m;
