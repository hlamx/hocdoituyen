#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,i,k;
typedef int bignum[105];
bignum f[105][105][5];
void cong(bignum a,bignum b, bignum c) {
    bignum t;
    memset(t,0,sizeof(t));
    ll i,nho;
    t[0] = max(a[0],b[0]);
    nho = 0;
    for(i=1;i<=t[0];i++) {
        nho = nho + a[i] + b[i];
        t[i] = nho%10;
        nho/=10;
    }
    if(nho>0) {
        t[0]++;
        t[t[0]] = nho;
    }
    c[0] = t[0];
    for(i=1;i<=t[0];i++) c[i] = t[i];
}
void tinh(ll i, ll c, bool ok)
{
   if(i>n)
   {
       f[i][c][ok][0] = 1;
       f[i][c][ok][1] = (c==0 && ok);
       return ;
   }
   if(f[i][c][ok][0] > 0) return;
    f[i][c][ok][0] = 1;
    for(int v = 0 ; v<=1;v++)
    {
        int c1 = c;
        if(v==0)
            c1++;
        else c1--;
        if(c1>=0 && c1<=k) {
            tinh(i+1,c1,ok||c1==k);
            cong( f[i][c][ok],f[i+1][c1][ok||c1==k], f[i][c][ok]);
        }
    }
}
int main()
{
    while(cin>>n>>k){
    memset(f,0,sizeof(f));
    tinh(1,0,0);
    if(f[1][0][0][0] > 10) {
        for(i = f[1][0][0][0]; i>=f[1][0][0][0]-4;i--) cout<<f[1][0][0][i];
        cout<<"...";
        for(i = 5; i>=1;i--) cout<<f[1][0][0][i];
    } else
    for(i = f[1][0][0][0]; i>=1;i--) cout<<f[1][0][0][i];
    cout<<endl;
}
}
