#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[20][2][11][2];
ll solve(string &s,ll idx,bool tight,ll prev,bool lz){
    if(s.size()==idx) return 1;
    if(dp[idx][tight][prev][lz]!=-1) return dp[idx][tight][prev][lz];
    ll lb=0;
    ll up=(tight==true)?s[idx]-'0':9;
    ll res=0;
    for(ll dig=lb; dig<=up; dig++){

        //invalid case(conseculative digts after non zero digit)
        if(prev==dig && !lz) continue;

        //valid cases
        res+=solve(s,idx+1,(tight && dig==up)?1:0,dig,(dig==0 && lz)?1:0);
    }
    return dp[idx][tight][prev][lz]=res;


}
int main(){
    ll a,b; cin>>a>>b;
    string l=to_string(a-1);
    string r=to_string(b);
    memset(dp,-1,sizeof(dp));
    ll ans_l=solve(l,0,1,10,1);
    memset(dp,-1,sizeof(dp));
    ll ans_r=solve(r,0,1,10,1);

   cout<<ans_r-ans_l<<endl;
    return 0;
}