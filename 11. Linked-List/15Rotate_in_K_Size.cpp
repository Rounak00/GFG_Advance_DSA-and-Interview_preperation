//Naive:
class Solution {
public:
    ListNode* solve(ListNode* head){
        ListNode* t=head; ListNode* p=NULL;
        while(t->next!=NULL){
            p=t;
            t=t->next;
        }
        p->next=NULL;
        t->next=head;
        return t;
    }
    
    int siz(ListNode *head){
        ListNode* t=head; int c=1;
        while(t->next!=NULL){t=t->next; c++;}
        return c;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){return head;}
        int size=siz(head);
        k=k%size;
        while(k){
           head=solve(head) ;
            k--;
        }
        return head;
    }
};
//Optimize;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)return head;
        ListNode *cur=head;
        int len=1;
        while(cur->next!=NULL){
            len++;
            cur=cur->next;
        }
        cur->next=head;
        k=k%len;
        k=len-k;
        while(k--){
            cur=cur->next;
        }
        head=cur->next;
        cur->next=NULL;
    return head;
    }
    
};