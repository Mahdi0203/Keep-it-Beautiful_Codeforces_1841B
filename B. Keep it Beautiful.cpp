#include<bits/stdc++.h>
using namespace std;
#define Start ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

void solve()
{
    ll q;
    cin>>q;
    vector<ll> v(q);
    for(ll i=0; i<q; i++) cin>>v[i];

    vector<ll> vres;
    ll inc_min = v[0], inc_max = 0, dec_min = -1;
    ll cnt = 0;
    ll indx = 0;
    int enter = 1;
    for(ll i=0; i<q; i++)
    {
        if(v[i] <= v[i+1])
        {
            vres.push_back(1);
        }
        else if(v[i] > v[i+1])
        {
            inc_max = v[i];
            vres.push_back(1);
            indx = i+1;
            break;
        }
    }
    //cout<<v[j]<<endl;
    //cout<<dec_min<<endl;
    ll indx2 =0;
    for(ll j=indx; j<q; j++)
    {
        if(v[j] <= inc_min)
        {
            indx2 = j;
            dec_min = v[j];
            break;
        }
        else if(v[j] >= inc_max)
        {
            vres.push_back(1);
            inc_max = v[j];
        }
        else if(v[j] < inc_max && v[j] > inc_min)
        {
            vres.push_back(0);
        }

    }
    //cout<<inc_min<<"  "<<dec_min<<endl;
    for(ll k = indx2; k<q; k++)
    {
        if((v[k]< inc_min && v[k]>dec_min) || (v[k] == dec_min || v[k] == inc_min))
        {
            vres.push_back(1);
            dec_min = v[k];
        }
        else
        {
            vres.push_back(0);
        }
        //dec_min = v[k];
    }
    for(ll i=0; i<q; i++)
    {
        cout<<vres[i];
    }
    cout<<endl;
}
int main()
{
    Start

    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

