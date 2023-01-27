#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         bool carry = false;
//         int tmp_val = l1->val + l2->val;
//         if(tmp_val > 9){
//                 tmp_val -= 10;
//                 carry = true;
//             }
//         ListNode* head = new ListNode(tmp_val);
//         ListNode* tmp_node = head;
//         l1 = l1 -> next;
//         l2 = l2 -> next;

//         while(l1 != nullptr and l2 != nullptr){
//             tmp_val = l1->val + l2->val;
//             if(carry == true){
//                 tmp_val += 1;
//             }
//             if(tmp_val > 9){
//                 tmp_val -= 10;
//                 carry = true;
//             }else{
//                 carry = false;
//             }
//             ListNode* new_node = new ListNode(tmp_val);
//             tmp_node->next = new_node;

//             // update parameters
//             l1 = l1 -> next;
//             l2 = l2 -> next;
//             tmp_node = new_node;
//         }

//         // len(l1) != len(l2)
//         if(l2 != nullptr){
//             l1 = l2;
//         }
//         while(l1 != nullptr){
//             tmp_val = l1->val;
//             if(carry == true){
//                 tmp_val += 1;
//             }
//             if(tmp_val > 9){
//                 tmp_val -= 10;
//                 carry = true;
//             }else{
//                 carry = false;
//             }

//             ListNode* new_node = new ListNode(tmp_val);
//             tmp_node->next = new_node;
//             // update parameters
//             l1 = l1 -> next;
//             tmp_node = new_node;
//         }

//         if(carry == true){
//             ListNode* new_node = new ListNode(1);
//             tmp_node->next = new_node;
//             }

//     return head;        
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* head = new ListNode();
        ListNode* tmp_node = head;
        int tmp_val;
        while(l1 != nullptr || l2 != nullptr){
            // check whether l1 or l2 is out of numbers
            if(l1 == nullptr){
                tmp_val = l2->val;
            }else if(l2 == nullptr){
                tmp_val = l1->val;
            }else{
                tmp_val = l1->val + l2->val;
            }
            // check whether addition generates carry
            if(carry == true){
                tmp_val += 1;
            }
            if(tmp_val > 9){
                tmp_val -= 10;
                carry = true;
            }else{
                carry = false;
            }

            ListNode* new_node = new ListNode(tmp_val);
            tmp_node->next = new_node;

            // update parameters
            if (l1 == nullptr){
                l2 = l2 -> next;
            }else if (l2 == nullptr){
                l1 = l1 -> next;
            }else{
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            tmp_node = new_node;
        }
        if(carry == true){
            ListNode* new_node = new ListNode(1);
            tmp_node->next = new_node;
            }

    return head->next;        
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
    int l1[3] = {2,4,3}; 
    int l2[3] = {5,6,4};
    ListNode* l1_ll = new ListNode(2); 
    ListNode* l2_ll = new ListNode(5);

    for(int i=1;i<3;i++){
        insert(l1[i],l1_ll);
        insert(l2[i],l2_ll);
    }
    ListNode* ret_node = a.addTwoNumbers(l1_ll,l2_ll);
    show(ret_node);
    
    return 0;
}