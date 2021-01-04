// 参考了题解

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include <limits.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
//pair有内部的构造函数，struct没有
//自定义的INF不够大（错误样例看出来），使用limits.h，所以开ll，避免爆掉
//set的查询插入删除都是logn
set<pair<int,int>> s;
int main(){

    int n;
    cin>>n;
    s.insert({INT_MIN,0});    //加入哨兵方便判断边界 
    s.insert({INT_MAX,0});
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        if(i>1){
            auto it=s.upper_bound({v,0});//任意位置，所以可以为0（只是用v的值来查找）
            auto jt=it;
            jt--;
            ll lv=(ll)v-jt->first,rv=it->first-(ll)v;
            if(lv<=rv) cout<<lv<<" "<<jt->second<<endl;
            else cout<<rv<<" "<<it->second<<endl;
        }
        s.insert({v,i});
    }

} 
