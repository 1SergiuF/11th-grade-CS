#include <iostream>
#include <cstring>
using namespace std;

const int N = 101;

void Prescurtat(char s[]);
int main()
{
    char s[N];
    cin.getline(s, N);

    Prescurtat(s);

    for (int i = 0; i < strlen(s); ++i)
        cout << s[i];
        
    return 0;
}

void Prescurtat(char s[])
{
    char* p = strtok(s, " ");
    char w[101];
    char w1[] = "COLEGIUL";
    char w2[] = "LICEUL";
    char w3[] = "NATIONAL";
    char w4[] = "TEORETIC";
    w[0] = '\0';

    while (p)
    {
        if (p[strlen(p) - 1] != '.')
            strcat(w, p);
        else
        {
            p[strlen(p) - 1] = '\0';

            if (strstr(w1, p)) strcat(w, w1);
            if (strstr(w2, p)) strcat(w, w2);
            if (strstr(w3, p)) strcat(w, w3);
            if (strstr(w4, p)) strcat(w, w4);
        }

        p = strtok(nullptr, " ");
        if (p)
            strcat(w, " ");
    }

    strcpy(s, w);
}