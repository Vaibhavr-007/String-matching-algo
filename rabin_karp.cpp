#include<bits/stdc++.h>
using namespace std;

long long compute_hash(string const &s){
    const int p=31;
    const int m=1e9+7;
    long long hashvalue=0;
    long long p_pow=1;
    for(auto c:s){
        hashvalue=(hashvalue+(c-'a'+1)*p_pow)%m;
        p_pow=(p_pow*p)%m;
    }
    return hashvalue;
}
int check(string &s,string &t){
    if(s.length()<t.length()){
        return 0;
    }
    long long hashvalue=compute_hash(t);
    long long val=compute_hash(s.substr(0,t.length()));
    const int m=1e9+7;
    long long p_pow=1;
    const int p=31;
    for(int i=1;i<t.length();++i){
        p_pow=(p_pow*p)%m;
    }
    if(val==hashvalue){
        return 1;
    }
    int j=0;
    for(int i=t.length();i<s.length();++i){
        val=(((val-(s[j]-'a'+1))/31)+(s[i]-'a'+1)*p_pow)%m;
        if(val==hashvalue){
            return 1;
        }
        j++;
    }
    return 0;
}
int main(){
    string s,t;
    cin>>s>>t;
    if(check(s,t)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}