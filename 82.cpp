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
    ListNode* deleteDuplicates(ListNode* head) {
        // create new node point to head if head has a chance to be removed
        ListNode* new_head = new ListNode(-30000,head); 
        ListNode* cur = new_head;
        ListNode* prev = nullptr;
        int del = -30000;
        while(cur->next != nullptr){
            if(cur->val == cur->next->val){
                del = cur->val;
                cur = prev;
            }
            if(cur->next->val == del){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
            
        }
        return new_head->next;
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

int main(){
    Solution a = Solution();
    int array[7] = {1,1,3,3,3,4,5};
    ListNode* ll = new ListNode(1);
    for(int i=1; i<7; i++){
        insert(array[i],ll);
    }
    ll = a.deleteDuplicates(ll);
    show(ll);
    return 0;
}