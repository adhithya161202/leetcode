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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        int sum=0;
        vector<int>total;
        while(temp!=NULL){
            if(temp->val!=0){
                sum+=temp->val;
            }
            else{
                if(sum!=0){
                total.push_back(sum);
                
                sum=0;
                }
            }

            temp=temp->next;
        }
        
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;

        for(int i=0;i<total.size();i++){
            ListNode* node=new ListNode(total[i]);
            curr->next=node;
            curr=curr->next;
            
        }
        
        return dummy->next;        
    }
};