/*
  @pintia psid=994805260223102976 pid=994805324509200384 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 写出这个数
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805324509200384
*/
// @pintia code=start
#include <iostream>
using namespace std;

void print(int n){
    if(n==0){
        cout<<"ling";
        return;
    }
    if(n == 1){
        cout<<"yi";
        return;
    }
    if(n == 2){
        cout<<"er";
        return;
    }
    if(n == 3){
        cout<<"san";
        return;
    }
    if(n == 4){
        cout<<"si";
        return;
    }
    if(n == 5){
        cout<<"wu";
        return;
    }
    if(n == 6){
        cout<<"liu";
        return;
    }
    if(n == 7){
        cout<<"qi";
        return;
    }
    if(n == 8){
        cout<<"ba";
        return;
    }
    if(n == 9){
        cout<<"jiu";
        return;
    }
    cout<<" ";
    print(n/10);
    cout<<" ";
    print(n%10);
}
int main(){
    string s;
    cin >> s;
    int total = 0;
    for(char &c :s){
        total += (int)(c - '0');
    }
    print(total);
    return 0;
}
// @pintia code=end