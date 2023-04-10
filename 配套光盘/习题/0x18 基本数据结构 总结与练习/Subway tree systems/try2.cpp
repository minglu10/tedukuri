#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string s1,s2;
string mn(string str){//得到树的最小表示 
    int dep=0,st=0;
    vector<string>a;
    string stemp;
    for(int i=0;i<str.size();i++){
        dep+=str[i]=='1'?-1:1;
        if(!dep){
            stemp="0"+mn(str.substr(st+1,i-st))+"1";
            a.push_back(stemp);
            st=i+1;
        }
    }
    sort(a.begin(),a.end());
    stemp=string("");
    for(int i=0;i<a.size();i++)stemp+=a[i];
    return stemp;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        cin>>s1>>s2;
        string ss1=mn(s1);
        string ss2=mn(s2);
        if(ss1==ss2)puts("same");
        else puts("different");
    }
}