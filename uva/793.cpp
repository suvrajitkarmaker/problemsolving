#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned int ui;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define gcd3(x,y,z)                __gcd(__gcd(x,y),z)
#define INF                     LLONG_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>=0 && nx<row && ny>=0 && ny<col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define max3(x,y,z)             max(z,max(x,y));
#define min3(x,y,z)             min(z,min(x,y));
#define lccm(x,y)                (x*y)/__gcd(x,y);
#define MP(x, y) make_pair(x, y)
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
#define all(x)                  (x).begin(), (x).end()
#define sz(c)               int(c.size())
#define clr(x, y)           memset(x, y, sizeof(x))
#define ff first
#define ss                  second
#define sf                  scanf
#define si(x)               scanf("%d", &x)
#define sii(x, y)           scanf("%d %d", &x, &y)
#define siii(x, y, z)       scanf("%d %d %d", &x, &y, &z)
#define sl(x)               scanf("%lld", &x)
#define sll(x, y)           scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       scanf("%lld %lld %lld", &x, &y, &z)
#define pf                  printf
#define pi(x)               printf("%d\n", x)
#define pii(x, y)           printf("%d %d\n", x, y)
#define piii(x, y, z)       printf("%d %d %d\n", x, y, z)
#define pl(x)               printf("%lld\n", x)
#define pll(x, y)           printf("%lld %lld\n", x, y)
#define plll(x, y, z)       printf("%lld %lld %lld\n", x, y, z)
#define Pii pair< int, int >
#define psi pair< string, int >
#define case(n) printf("Case %d: ",n);
#define eps 1e-15
#define mod 100000007
#define MAX 100010
priority_queue<Pii, vector<Pii>, greater<Pii> > q;
vector<int>v;
class UnionFind
{
private:
    int n;
    int group;
    int sz[500010];
    int parent[500010];
public:
    void Initial(int n)
    {
        this->n=n;
        this->group=n;
        for(int i = 0; i < n; i++)
            parent[i] = i, sz[i] = 1;
    }
    int connectedGraph()
    {
        return this->group;
    }
    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    bool IsConnected(int x,int y)
    {
        if(x==y||find(x)==find(y))
            return true;
        return false;
    }
    int size(int p)
    {
        return sz[ find(p) ];
    }
    void union_sets(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            group--;
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
} uf;
int main()
{

   // READ("input.txt");
   //   WRITE("output.txt");
    int f=0;
    int n,t,x,y;
    scanf("%d",&t);
    string s;
    char cr;
    for(int i=0; i<t; i++)
    {
        scanf("\n%d\n",&n);
        uf.Initial(n);
        int ct=0,ct1=0;
        s="";
        while(1)
        {
            if(!getline(cin,s)||s.empty())
                break;
            sscanf(s.c_str(),"%c %d %d",&cr,&x,&y);
            if(cr=='c')
                uf.union_sets(x-1,y-1);
            else
            {
                //cout<<"sdaf"<<endl;
                if(uf.IsConnected(x-1,y-1)==true)
                    ct++;
                else
                    ct1++;
            }
            //cout<<cr<<x<<y<<endl;
        }
        if(f)
            printf("\n");
        f++;
        printf("%d,%d\n",ct,ct1);
    }
}
