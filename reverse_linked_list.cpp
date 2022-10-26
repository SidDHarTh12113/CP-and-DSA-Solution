#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* curr=head;
    ListNode* prev= nullptr;
    while(curr!= nullptr){
        swap(curr->next,prev);
        swap(prev!= nullptr?prev->next:prev,curr);
    }
    return prev;
}
