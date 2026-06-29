/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        vector<int> v;
        ListNode* temp = list1;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        temp = list2 ;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end()); 
        ListNode* dummy = new ListNode(-1)  ; 
        ListNode* head = dummy; 
        for(int i : v ) {
            head->next = new ListNode(i) ; 
            head = head->next ; 
        }
        ListNode* ans = dummy->next ;
        delete dummy ; 
        return ans ; 
    }
};