#include <windows.h>
#include <wincrypt.h>
using namespace std;

class WinRandom {
	HCRYPTPROV handle;
public:
	WinRandom() {
		handle = 0;
        CryptAcquireContext(
        	(HCRYPTPROV*)&handle,0,0,
            PROV_RSA_FULL,0
		);
	}
	~WinRandom() {
    	if (handle != 0) CryptReleaseContext(handle, 0);
	}
    bool randBuf(void *dest, int len) {
    	if (handle == 0) return false;
        return CryptGenRandom(handle, len, (BYTE*)dest);
	}
#   define _(func, typ) \
	typ func() { \
    	typ ret = 0; \
        assert(randBuf((void *)&ret, sizeof(ret))); \
        return ret; \
    }
    _(randInt, int)
    _(randLong, long long)
    _(randUnsigned, unsigned)
    _(randUnsignedLong, unsigned long long)
    _(randShort, short)
    _(randUnsignedShort, unsigned short)
	_(randChar, char)
    _(randUnsignedChar, unsigned char)
    _(randSignedChar, signed char)
};

class OIrandServer{
public:
    class Pair{
    public:
        int l, r;
    };
private:
    mt19937 rnd;
    void print_Int(int *st, int len, char div){
        for (int i = 1; i <= len; i++){
            printf("%d%c", st[i], div);
        } if (div != '\n') putchar(10);
    }
    void print_Pair(Pair *st, int len, bool withval = 0, int minn = 0, int maxx = 0){
        // printf("*%d %d %d\n", withval, minn, maxx);
        for (int i = 1; i <= len; i++){
            printf("%d %d", st[i].l, st[i].r);
            if (withval) printf(" %d", rnd() % (maxx - minn + 1) + minn);
            printf("\n");
        }
    }
public:
    OIrandServer(){
        WinRandom seed_Cache;
        rnd.seed(seed_Cache.randInt());
    }
    int rand_range(int minn, int maxx){ return rnd() % (maxx - minn + 1) + minn; }
    int* rand_Sequence(int lenth, int minn, int maxx, char div = ' ', bool whether_Print = 1){
        int *ptr = (int*)malloc(lenth * sizeof(int) + 100);
        for (int i = 1; i <= lenth; i++){
            ptr[i] = rnd() % (maxx - minn + 1) + minn;
        }
        if (whether_Print) print_Int(ptr, lenth, div);
        int *res = ptr;
        return res;
    }
    int* rand_Permutation(int minn, int maxx, char div = ' ', bool whether_Print = 1){
        int *ptr = (int*)malloc((maxx - minn + 1) * sizeof(int) + 100);
        for (int i = minn; i <= maxx; i++){
            ptr[i] = i;
        }
        shuffle(ptr + 1, ptr + maxx - minn + 1, rnd);
        if (whether_Print) print_Int(ptr, maxx - minn + 1, div);
        int *res = ptr;
        ptr = 0;
        return res;
    }
    Pair* rand_Vector(int total_Need, int minn, int maxx, bool Reversible = 0, bool whether_Print = 1){
        Pair *ptr = (Pair*)malloc(total_Need * sizeof(Pair) + 100);
        for (int i = 1; i <= total_Need; i++){
            int l = rnd() % (maxx - minn + 1) + minn, r = rnd() % (maxx - minn + 1) + minn;
            if (l > r && !Reversible) swap(l, r);
            ptr[i] = (Pair){l, r};
        }
        if (whether_Print) print_Pair(ptr, total_Need);
        Pair *res = ptr; ptr = 0;
        return res;
    }
    Pair* rand_Tree(int n, bool withval = 0, int minn = 0, int maxx = 0, bool couldlian = 1, bool couldjuhua = 1, bool whether_Print = 1){
        int *fa = (int*)malloc(n * sizeof(int) + 100);
        for (int i = 2; i <= n; i++){
            fa[i] = rnd() % (i - 1) + 1;
        }
        int Special = rnd() % 50;
        if (Special == 0 && couldjuhua){ // juhua
            for (int i = 2; i <= n; i++){
                fa[i] = 1;
            }
        }
        if (Special == 1 && couldlian){ // lian
            int *cache = (int*)malloc(n * sizeof(int) + 100);
            for (int i = 1; i <= n; i++){ cache[i] = i; }
            shuffle(cache + 2, cache + 1 + n, rnd);
            for (int i = 2; i <= n; i++){ fa[cache[i]] = cache[i - 1]; }
        }
        Pair *result = (Pair*)malloc(n * sizeof(Pair) + 100);
        for (int i = 1; i < n; i++){
            result[i].l = fa[i + 1];
            result[i].r = i + 1;
        }
        shuffle(result + 1, result + n, rnd);
        if (whether_Print) print_Pair(result, n - 1, withval, minn, maxx);
        Pair *res = result; fa = 0; result = 0;
        return res;
    }
    Pair* rand_Map(int n, int m, bool directed = 1, bool withval = 0, int minn = 0, int maxx = 0, bool whether_Print = 1){
        Pair *tre = rand_Tree(n, 0, 0, 0, 1, 1, 0), *mapp = (Pair*)malloc(m * sizeof(Pair) + 100);
        for (int i = 1; i < n; i++){ mapp[i] = tre[i]; }
        map <int, map<int, int> > used;
        for (int i = 1; i < n; i++){ used[mapp[i].l][mapp[i].r] = 1; if (!directed) used[mapp[i].r][mapp[i].l] = 1; }
        for (int i = 1; i <= m - n + 1; i++){
            RAND_EDGE:
            int l = rnd() % n + 1, r = rnd() % n + 1;
            // cout << l << ' ' << r << ' ' << i + n - 1 << endl;
            if (l == r) goto RAND_EDGE;
            if (used[l][r]) goto RAND_EDGE;
            if (used[r][l] && !directed) goto RAND_EDGE;
            mapp[i + n - 1] = (Pair){l, r};
        }
        if (whether_Print) print_Pair(mapp, m, withval, minn, maxx);
        Pair *res = mapp; mapp = 0; tre = 0;
        return res;
    }
};