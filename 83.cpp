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
        ListNode* cur = head;
        if(cur == nullptr) return cur;
        while(cur->next != nullptr){
            if(cur->val == cur->next->val){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }
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
    int array[7] = {1,1,3,3,3,4,5};
    ListNode* ll = new ListNode(1);
    for(int i=1; i<7; i++){
        insert(array[i],ll);
    }
    ll = a.deleteDuplicates(ll);
    show(ll);
    return 0;
}