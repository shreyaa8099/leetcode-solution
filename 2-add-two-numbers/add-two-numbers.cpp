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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* newNode=new ListNode(-1);
        ListNode* head=newNode;
        int carry=0;
        ListNode* h1=l1;
        ListNode* h2=l2;
        while (h1!=NULL&&h2!=NULL)
        {
            int dat=h1->val+h2->val+carry;
            if (dat>9)
            {
                carry=dat/10;
                dat=dat%10;
            }
            else
            carry=0;
            newNode->next=new ListNode(dat);
            newNode=newNode->next;
            h1=h1->next;
            h2=h2->next;
        }
        while (h1!=NULL)
        {
            int dat=h1->val+carry;
            if (dat>9)
            {
                carry=dat/10;
                dat=dat%10;
            }
            else
            carry=0;
            newNode->next=new ListNode(dat);
            newNode=newNode->next;
            h1=h1->next;
        }

        while (h2!=NULL)
        {
            int dat=h2->val+carry;
            if (dat>9)
            {
                carry=dat/10;
                dat=dat%10;
            }
            else
            carry=0;
            newNode->next=new ListNode(dat);
            newNode=newNode->next;
            h2=h2->next;
        }


        if (carry!=0)
        newNode->next=new ListNode(carry);
        return head->next;
    }
};