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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* tmp_node = head;
        int tmp_val;
        while(list1 != nullptr or list2 != nullptr){
            if(list1 == nullptr or (list2 != nullptr and list2->val<list1->val)){
                tmp_node -> next = list2;
                list2 = list2->next;
            }
            // list2 == nullptr or (list1 != nullptr and list1->val<=list2->val)
            else{ 
                tmp_node -> next = list1;
                list1 = list1->next;
            }
            tmp_node = tmp_node->next;
        }
        return head -> next;
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
    int n1 = 4;
    int n2 = 3;
    int array1[4] = {1,2,4,5};
    int array2[3] = {1,3,4};
    ListNode* l1 = new ListNode(array1[0]);
    ListNode* l2 = new ListNode(array2[0]);
    for(int i=1;i<n1;i++){
        insert(array1[i],l1);
    }
    for(int i=1;i<n2;i++){
        insert(array2[i],l2);
    }
    show(l1);
    show(l2);
    ListNode* ll = a.mergeTwoLists(l1,l2);
    show(ll);
    return 0;
}