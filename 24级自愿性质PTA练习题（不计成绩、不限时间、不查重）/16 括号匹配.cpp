/*
  @pintia psid=1979022247370915840 pid=1980992086588223488 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 括号匹配
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980992086588223488
*/
// @pintia code=start
#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        stack<char> s;
        bool flag = true;
        int leftneed = 0;
        int rightneed = 0;
        
        for(char c:str){
            if(c=='('){
                s.push(c);
            }
            else if(c==')'){
                if(s.empty()){
                    flag = false;
                    leftneed++;
                }
                else{
                    s.pop();
                }
            }
        }
        if(flag && s.empty()){
            cout << "Match" << endl;
        }
        else{
            rightneed += s.size();

            cout<<leftneed+rightneed<<endl;
            for(int i = 0;i<leftneed;i++){
                str = '(' + str;
            }
            for(int i = 0;i<rightneed;i++){
                str = str + ')';
            }
            cout << str << endl;
        }
    }

    return 0;
}
// @pintia code=end