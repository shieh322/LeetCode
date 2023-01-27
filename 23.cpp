#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }
};

void insert(int val, ListNode* cur){
    ListNode* tmp_node = new ListNode(val);
    while(cur -> next != nullptr){
        cur = cur->next;
    }
    cur->next = tmp_node;
}

void show(ListNode* cur){
    while(cur != nullptr){
        cout << cur->val;
        cur = cur->next;
    }
    cout << endl;
}
