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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 or head == nullptr){
           return head;
        }
        // find length o(n)
        int length = 0;
        ListNode* tmp_node = head;
        while(tmp_node -> next != nullptr){
            tmp_node = tmp_node -> next;
            length += 1;
        }  
        length += 1;
        k %= length;
        // make linklist as a circular list
        tmp_node ->next = head; 
        tmp_node = head;
        for(int i=0;i<length-k-1;i++){
            tmp_node = tmp_node -> next;
        }
        head = tmp_node->next;
        tmp_node -> next = nullptr;
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
    int array[3] = {0,1,2};
    ListNode* ll = new ListNode(array[0]);
    for(int i=1; i<3; i++){
        insert(array[i],ll);
    }
    show(ll);
    ll = a.rotateRight(ll,4);
    show(ll);
    return 0;
}