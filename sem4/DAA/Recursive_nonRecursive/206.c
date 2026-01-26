//Reversing a linked list

//iterative
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) 
{
        struct ListNode *cur = head,*pre=NULL,*next=NULL;
        while(cur!=NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre=cur;
            cur=next;
        }
        return pre;
}
//Recursive
struct ListNode* reverseList(struct ListNode* head)
{
    // base case
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

