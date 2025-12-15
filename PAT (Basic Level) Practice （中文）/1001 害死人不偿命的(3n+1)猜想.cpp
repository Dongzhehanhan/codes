/*
  @pintia psid=994805260223102976 pid=994805325918486528 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 害死人不偿命的(3n+1)猜想
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805325918486528
*/
// @pintia code=start
#include <iostream>
using namespace std;

int calculate(int n){
    int count=0;
    while(n!=1){
        if(n%2==0){
            n/=2;
        }else{
            n=(3*n+1) / 2;
        }
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<calculate(n);
    return 0;
}
// @pintia code=end