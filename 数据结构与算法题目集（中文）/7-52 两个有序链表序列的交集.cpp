/*
  @pintia psid=15 pid=2999 compiler=GXX
  ProblemSet: 数据结构与算法题目集（中文）
  Title: 两个有序链表序列的交集
  https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=2999
*/
// @pintia code=start

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
    vector<int> seq1, seq2;
    int num;
    while (cin >> num && num != -1) {
        seq1.push_back(num);
    }
    while (cin >> num && num != -1) {
        seq2.push_back(num);
    }
    ListNode* head = new ListNode(0); // Dummy head
    ListNode* tail = head;
    size_t i = 0, j = 0;
    while (i < seq1.size() && j < seq2.size()) {
        if (seq1[i] < seq2[j]) {
            i++;
        } else if (seq1[i] > seq2[j]) {
            j++;
        } else {
            tail->next = new ListNode(seq1[i]);
            tail = tail->next;
            i++;
            j++;
        }
    }
    if (head->next == NULL) {
        cout << "NULL" << endl;
    } else {
        ListNode* curr = head->next;
        while (curr) {
            cout << curr->val;
            if (curr->next) cout << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    return 0;
}
// @pintia code=end