#include <bits/stdc++.h>
#define int long long
using namespace std;

inline void re(int &x){
    char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar()){}
    for (x = 0; isdigit(ch); x *= 10, x += ch - '0', ch = getchar()){}
}

int n, m, len;
int id[114514], st[400], flag[400], sum[400];
int a[114514];

inline void init(){
    for (register int i = 1; i <= n; ++i){ id[i] = (i - 1) / len + 1; sum[id[i]] += a[i]; }
    for (register int i = 1, cnt = 1; cnt <= n; ++i, cnt += len){ st[i] = cnt; }
}

inline void print(){
    for (int i = 1; i <= n; i++){ cout << a[i] << ' '; } cout << endl; 
    for (int i = 1; i <= n; i++){ cout << sum[id[i]] << ' '; } cout << endl;
}

inline void change(int l, int r){
    int sid = id[l], eid = id[r];
    if (sid == eid){
        for (register int i = l; i <= r; ++i){ sum[sid] -= a[i]; a[i] = sqrt(a[i]); sum[sid] += a[i]; }
        flag[sid] = 1; for (register int i = st[sid]; id[i] == sid; ++i){ if (a[i] != 1) flag[sid] = 0; }
    } else {
        if (flag[sid] == 0) for (register int i = l; id[i] == sid; ++i){ sum[sid] -= a[i]; a[i] = sqrt(a[i]); sum[sid] += a[i]; }
        if (sum[sid] == len) flag[sid] = 1;
        for (register int i = sid + 1; i < eid; ++i){
            if (flag[i] == 1) continue;
            for (register int j = st[i]; id[j] == i; j++){
                sum[i] -= a[j]; a[j] = sqrt(a[j]); sum[i] += a[j];
            }
            if (sum[i] == len) flag[i] = 1;
        }
        if (flag[eid] == 0) for (register int i = st[eid]; i <= r; ++i){ sum[eid] -= a[i]; a[i] = sqrt(a[i]); sum[eid] += a[i]; }
        flag[eid] = 1; for (register int i = st[eid]; id[i] == eid; i++){ if (a[i] != 1) flag[eid] = 0; }
    }
}

inline int ask(int l, int r){
    int sid = id[l], eid = id[r], ans = 0;
    if (sid == eid){
        for (register int i = l; i <= r; ++i){ ans += a[i]; } return ans;
    } else {
        for (register int i = l; id[i] == sid; ++i){ ans += a[i]; }
        for (register int i = sid + 1; i < eid; i++){ ans += sum[i]; }
        for (register int i = st[eid]; i <= r; ++i){ ans += a[i] ;}
        return ans;
    }
}

signed main()
{
    re(n); len = (int)sqrt(n);
    for (register int i = 1; i <= n; ++i){ re(a[i]); }
    init();
    int typ, l, r;
    re(m);
    for (register int i = 1; i <= m; ++i){
        re(typ); re(l); re(r);
        if (l > r) swap(l, r);
        if (typ == 0) change(l, r);
        else { printf("%lld\n", ask(l, r)); }
    }
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10
5
0 9 4
1 4 7
0 4 6
0 7 6
1 3 7

*/