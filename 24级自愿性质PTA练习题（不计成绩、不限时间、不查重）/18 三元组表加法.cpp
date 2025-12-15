/*
  @pintia psid=1979022247370915840 pid=1980992290930475008 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 三元组表加法
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980992290930475008
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

struct elm{
    int row;
    int col;
    int val;
};

int main(){
    int m,n;
    cin >> m >> n;
    vector<elm> toBeSort;

    for(int i = 0;i<m;i++){
        elm tmp; 
        cin>>tmp.row>>tmp.col>>tmp.val;
        toBeSort.push_back(tmp);
    }
    for(int i = 0;i<n;i++){
        elm tmp; 
        cin>>tmp.row>>tmp.col>>tmp.val;
        toBeSort.push_back(tmp);
    }

    sort(toBeSort.begin(),toBeSort.end(),[](elm a,elm b){
        if(a.row==b.row)
            return a.col<b.col;
        else
            return a.row<b.row;
    });

    vector<elm> final;
    int i=0,j=0;
    while(i<toBeSort.size()){
        elm current=toBeSort[i];
        int sum=current.val;
        j=i+1;//从下一个开始找
        while(j<toBeSort.size()&&toBeSort[j].row==current.row&&toBeSort[j].col==current.col){
            sum+=toBeSort[j].val;
            j++;
        }
        if(sum!=0){
            elm newElm;
            newElm.row=current.row;
            newElm.col=current.col;
            newElm.val=sum;
            final.push_back(newElm);
        }
        i=j;//跳到下一个不同的元素
    }

    for(int i = 0;i<final.size();i++){
        cout<<final[i].row<<" "<<final[i].col<<" "<<final[i].val<<endl;
    }
    return 0;
}
// @pintia code=end