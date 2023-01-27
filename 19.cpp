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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        int length = 0;
        ListNode* tmp_node = head;
        while(tmp_node != nullptr){
            tmp_node = tmp_node ->next;
            length += 1;
        } 
        int tar_idx = length-n-1;
        // delete head
        if(tar_idx < 0){
            tmp_node = head;
            head = head->next;
            return head;
        }
        tmp_node = head;
        for(int i=0; i<tar_idx; i++){
            tmp_node = tmp_node->next;
        }
        ListNode* next_node = tmp_node -> next;
        tmp_node->next = next_node->next;
        delete next_node;
        return head;
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
    int total = 1;
    int array[5] = {1};
    ListNode* ll = new ListNode(array[0]);
    for(int i=1;i<total;i++){
        insert(array[i],ll);
    }
    show(ll);
    ll = a.removeNthFromEnd(ll,2);
    show(ll);
    return 0;
}