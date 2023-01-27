#include <iostream>
#include <vector>

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy_head = new ListNode(-1,head);
        ListNode* new_ll = new ListNode(-1);
        ListNode* cur = dummy_head;
        int cnt = 0;
        // find most left change ll
        while(cnt+1 != left){
            cur = cur->next;
            cnt += 1;
        }
        // move reversing node intp new ll
        ListNode* new_ll_end = nullptr;
        while(cnt!= right){
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = new_ll->next;
            if(tmp->next == nullptr){
                new_ll_end = tmp;
            }
            new_ll->next = tmp;
            cnt += 1;
        }

        // moved reverse ll back to original
        new_ll_end->next = cur->next;
        cur->next = new_ll->next;
        delete new_ll;
        return dummy_head->next;
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
    vector <int> v = {5};
    ListNode* ll = new ListNode(0);
    for(auto i :v){
        insert(i,ll);
    }
    show(ll->next);
    ll = a.reverseBetween(ll->next,1,1);
    show(ll);
    return 0;
}