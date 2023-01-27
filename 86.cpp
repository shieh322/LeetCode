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
    ListNode* partition(ListNode* head, int x) {
        // dummy head
        ListNode* new_head = new ListNode(-1,head);
        ListNode* cur = new_head;
        // store nodes that greater than x in original order
        // dummy head
        ListNode* greater_node = new ListNode(-1);
        ListNode* greater_node_cur = greater_node;

        while(cur->next != nullptr){
            if(cur->next->val >= x){
                greater_node_cur->next = cur->next;
                cur->next = cur->next->next;
                greater_node_cur = greater_node_cur->next;
                greater_node_cur->next = nullptr;
            }
            else{
                cur = cur->next;
            }
        }
        // combine linkedlist that nodes < x and linkedlist that nodes >= x
        cur->next = greater_node->next;
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
    int array[6] = {1,4,3,2,5,2};
    ListNode* ll = new ListNode(1);
    for(int i=1; i<6; i++){
        insert(array[i],ll);
    }
    ll = a.partition(ll,3);
    show(ll);
    return 0;
}