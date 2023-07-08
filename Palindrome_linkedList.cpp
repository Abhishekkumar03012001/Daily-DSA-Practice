# Problem :-Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

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


//code with approach-1//
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>ans;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ans.push_back(curr->val);
            curr=curr->next;
        }
        int n=ans.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(ans[i]!=ans[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};




//code with approach-2//
class Solution {
private:
ListNode* reverse(ListNode* head)
{
    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
ListNode* getMid(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
        {
            return true;
        }
        ListNode* mid=getMid(head);
        ListNode* temp=mid->next;
        mid->next=reverse(temp);
        ListNode* head1=head;
        ListNode* head2=mid->next;
        while(head2!=NULL)
        {
            if(head1->val!=head2->val)
            {
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};