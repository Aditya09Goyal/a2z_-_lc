class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* LL = new ListNode(-1);
        ListNode* ans = LL;
        int carry = 0;
        while (head1 != nullptr or head2 != nullptr) {
            int a, b;
            if (head1 == nullptr) {
                a = 0;
            } else
                a = head1->val;
            if (head2 == nullptr) {
                b = 0;
            } else
                b = head2->val;
            int res = (a + b + carry);
            carry = res / 10;
            res = res%10;
            ans->next = new ListNode(res);
            ans = ans->next;
            if (head1)
                head1 = head1->next;
            if (head2)
                head2 = head2->next;
        }
        if(carry==1) ans->next= new ListNode(carry) ; 
        ListNode* dummy = LL->next;
        delete LL;
        return dummy;
    }
};