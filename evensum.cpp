#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define el cout<<'\n'
#define pii pair <int,int>
#define ll long long
#define prob "evensum"

using namespace std;

const int N=1e5+1001;
const int mod=1e9+7;

struct it{
    int sl_0_l,sl_0_r,sl_odd;
    int sum_odd_l,sum_odd_r,sum_even_l,sum_even_r;
    ll res;
};
it st[4*N+1];

int n,q;

void cre(int id,int v){
    if (v==1){
        st[id].sl_0_l=st[id].sl_0_r=0;
        st[id].sl_odd=1;
        st[id].sum_odd_l=st[id].sum_odd_r=1;
        st[id].sum_even_l=st[id].sum_even_r=0;
        st[id].res=1;
    }
    else {
        st[id].sl_0_l=st[id].sl_0_r=1;
        st[id].sl_odd=0;
        st[id].sum_even_l=st[id].sum_odd_r=0;
        st[id].sum_even_r=st[id].sum_odd_l=0;
        st[id].res=0;
    }

}

it mer(it st1,it st2){
    it st3;
    st3.sl_odd=st1.sl_odd+st2.sl_odd;
    if (st1.sl_odd==0){
        st3.sl_0_l = st2.sl_0_l + st1.sl_0_l;
    }
    else {
        st3.sl_0_l = st1.sl_0_l;
    }
    if (st2.sl_odd==0){
        st3.sl_0_r = st1.sl_0_r + st2.sl_0_r;
    }
    else{
        st3.sl_0_r = st2.sl_0_r;
    }
    if (st1.sl_odd % 2 == 0){
//        cout<<124;el;
        st3.sum_even_l = st1.sum_even_l + st2.sum_even_l ;
        st3.sum_even_r = st2.sum_even_r +st1.sum_even_r +  ((st1.sum_even_r!=0) ? st2.sl_0_l : 0);
        st3.sum_odd_l = st1.sum_odd_l + st2.sum_odd_l + ((st2.sum_odd_l!=0) ? st1.sl_0_r : 0);
        st3.sum_odd_r = st1.sum_odd_r + st2.sum_odd_r ;
    }
    else {
//        cout<<123;el;
        st3.sum_even_l = st1.sum_even_l + st2.sum_odd_l + ((st2.sum_odd_l !=0 ) ?st1.sl_0_r:0);
        st3.sum_even_r = st1.sum_even_r + st2.sum_odd_r ;
        st3.sum_odd_l = st1.sum_odd_l + st2.sum_even_l ;
        st3.sum_odd_r = st1.sum_odd_r + st2.sum_even_r + ((st1.sum_odd_r !=0 ) ? st2.sl_0_l:0);
    }
    st3.res=st1.res+ st2.res;
    st3.res+= 1LL*st1.sum_odd_l*st2.sum_even_r + 1LL*st1.sum_even_l*st2.sum_odd_r;
    st3.res+= 1LL*st1.sum_odd_l*st2.sl_0_l + 1LL*st2.sum_odd_r*st1.sl_0_r;
    return st3;
}

void upd(int id,int l,int r,int i,int v){
    if (i>r || i<l) return;
    if (l==r){
        cre(id,v);
        return;
    }
    int mid=(l+r)/2;
    if (i<=mid) upd(2*id,l,mid,i,v);
    else upd(2*id+1,mid+1,r,i,v);
    st[id]=mer(st[2*id],st[2*id+1]);
}

it gget(int id,int l,int r,int u,int v){
    if (u>r || v<l ) return (it){0,0,0,0,0,0,0,0};
    if (u<=l && v>=r) return st[id];
    int mid=(l+r)/2;
    it st1= gget(2*id,l,mid,u,v);
    it st2= gget(2*id+1,mid+1,r,u,v);
    return mer(st1,st2);
}

void input()
{
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        upd(1,1,n,i,x%2);
    }
    while (q--){
        int t,l,r;
        cin>>t>>l>>r;
        if (t==1){
            upd(1,1,n,l,r%2);
        }
        else {
            ll ans= 1LL*(r-l+1)*(r-l+2)/2 - gget(1,1,n,l,r).res;
            cout<<ans;el;
        }
    }
//    el;
//    int cnt=0;
//    for (int i=1;i<=n;i++){
//        int sum=0;
//        for (int j=i;j<=n;j++){
//            sum+=a[j];
//            if (sum%2==0) cnt++;
//        }
//    }
//    cout<<cnt;
//    it st1={0,0,0,0,0,0,0,0};
//    it st2={0,0,1,1,1,0,0,1};
//
//    it st=mer(st1,st2);
//    cout<<st.sl_0_l;el;
//    cout<<st.sl_0_r;el;
//    cout<<st.sum_odd_l;el;
//    cout<<st.sum_odd_r;el;
//    cout<<st.sum_even_l;el;
//    cout<<st.sum_even_r;el;
//    cout<<st.sl_odd;el;
//    cout<<st.res;el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen(prob".inp","a+",stdin);
//    freopen(prob".out","w+",stdout);
//    int t;
//    cin>>t;
//    while (t--)

    input();
    return 0;
}


