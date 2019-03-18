#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int maxN = 30;
int n;//有n个木块
vector<int> pile[maxN];//vector数组,用于表示数组元素是vector

void find_block(int a, int& p, int& h){//找到木块所属的pile和height
    for(p = 0; p < n; p++){
        for(h = 0; h < pile[p].size(); h++){
            if(pile[p][h] == a) return;//二分查找不适用
        }
    }
}
//将木块p上方的所有木块移回原位
//木块高度为h，在第p堆
void clear_above(int p, int h){
    for(int i = h+1; i < pile[p].size(); i++){
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
}

//在第p堆，从高度为h开始所有上方的木块放在p2堆顶部
void pile_over(int p, int h, int p2){
    for(int i=h; i<pile[p].size();i++)
        pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);//利用resize调整数组大小
}

void print(){//输出所有位置的所有木块
    for(int i = 0; i < n; i++){
        printf("%d:", i);
        for(int j=0; j<pile[i].size(); j++) printf(" %d",pile[i][j]);
        printf("\n");
    }
}

int main(){
    int a, b;
    cin >> n;
    string s1, s2;
    for(int i=0;i<n;i++) pile[i].push_back(i);
    while(cin>>s1>>a>>s2>>b){//输入的格式
        int pa, pb, ha, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if(pa == pb) continue;
        if(s2 == "onto") clear_above(pb, hb);
        if(s1 == "move") clear_above(pa, ha);
        pile_over(pa, ha, pb); 
    }
    print();
    return 0;
}
