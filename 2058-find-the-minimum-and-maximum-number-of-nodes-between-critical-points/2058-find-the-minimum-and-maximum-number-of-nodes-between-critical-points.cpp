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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prevval=0;
        int currval=0;
        int nextval=0;

        int mindis=INT_MAX;
        int firstcriticalpos=0;
        int prevcriticalpos=0;
        int i=0;
        vector<int>result={-1,-1};

        ListNode* temp=head;
        while(temp!=NULL){
            prevval=currval;
            currval=nextval;
            nextval=temp->val;
            cout<<nextval<<" ";

            if(prevval!=0 && currval!=0 && nextval!=0) {
                if((prevval > currval && nextval> currval) || (prevval< currval && nextval< currval)){
                if(firstcriticalpos==0){
                    firstcriticalpos=i;

                }
                else{
                    mindis=min(mindis,i-prevcriticalpos);
                    result={mindis,i-firstcriticalpos};
                }
                prevcriticalpos=i;
                }
            }
                i++;
            temp=temp->next; 
            }
           
        
        return result;
    }
};