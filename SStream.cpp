#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//sstream可以让字符串模拟流输入输出
//重载了 >> 和 << 类似于流操作，可以输出到任何的对象上去
//输入n个整数，输出这所有整数的和
void getInt(){
    string line;
    while(getline(cin,line)){
        int sum =0, x;
        stringstream ss(line);
        while(ss>>x) sum+=x;
        cout<<sum<<endl;
    }
}
int main(){
    getInt();
}
