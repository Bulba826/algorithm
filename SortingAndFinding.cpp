// #include<bits/stdc++.h>
// It is not a standard C++ header.
// Pay attention that not every complier support this.
// e.g. MSVC doesn't support this at all.
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

const int maxN = 10000;

int main(){
    int n, q, x, a[maxN], nums = 0;
    //以前没注意到可以在一行初始化所有东西
    while(scanf("%d%d", &n, &q)==2 && n){
        //scanf返回值是成功扫描进入参数的多少
        //printf返回值是打印了多少个字符（不含字符串的结尾等）
        printf("case #%d:\n", ++nums);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        while(q--){
            scanf("%d", &x);
            int p = lower_bound(a, a+n, x) - a;//lower_bound(T* start, T* end, T objectToBeFound)
                                                //返回第一次出现的位置
            if(a[p] == x) printf("%d found at %d", x, p+1);
            else printf("%d not found", x);
        }
    } 
    return 0;
}

