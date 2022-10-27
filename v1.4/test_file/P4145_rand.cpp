#include <bits/stdc++.h>
using namespace std;

int main()
{
    struct timeb t;
    ftime(&t);
    srand(t.time * 1000 + t.millitm);
    int n = 10;
    cout << n << endl;
    for (int i = 1; i <= n; i++){ cout << i << ' '; }
    int m = 5;
    cout << endl << m << endl;
    for (int i = 1; i <= m; i++){
        int typ = rand() % 2, l = rand() % n + 1, r = rand() % n + 1;
        cout << typ << ' ' << l << ' ' << r << endl;
    }
    return 0;
}