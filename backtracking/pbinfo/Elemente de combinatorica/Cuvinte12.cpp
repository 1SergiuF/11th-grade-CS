#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char cuv[15], voc[] = "aeiou";
int p, length;
int x[15];

void Subm(int k);
void ScrieSol(int k);
bool Ok(int k);

int main()
{
	cin >> (cuv + 1) >> p;
	length = strlen(cuv + 1);
	sort(cuv + 1, cuv + length + 1);
	Subm(1);
	return 0;
}

void Subm(int k)
{
	if (k > length) return;

	for (int i = x[k - 1] + 1; i <= length; ++i)
	{
		x[k] = i;
		if (Ok(k))
			ScrieSol(k);			
		Subm(k + 1);
	}
}

void ScrieSol(int k)
{
	for (int i = 1; i <= k; ++i)
		cout << cuv[x[i]];
	cout << '\n';
}

bool Ok(int k)
{
    if(k > p)
        return false;

    for(int i = 2; i <= k; ++i)
        if(!strchr(voc, cuv[x[i - 1]]) && !strchr(voc, cuv[x[i]]))
            return false;

    if(!strchr(voc, cuv[x[1]]))
        return false;

    return true;
}