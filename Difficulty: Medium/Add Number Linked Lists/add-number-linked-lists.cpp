

class Solution {
  public:
    pair<Node*,int> reverse(Node *head){
        Node* curr=head,*prev=NULL;
        int len=0;
        while(curr!=NULL){
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            len++;
        }
        return {prev,len};
    }
    void add(Node* head1, Node* head2){  //add head2 into head1 where len(head1)>=len(head2)
        Node* curr1=head1,*curr2=head2;
        int carry=0;
        while(curr1!=NULL){
            int add=carry;
            if(curr2!=NULL)
                add+=curr2->data;
            curr1->data+=add;
            carry=0;
            if(curr1->data>=10){
                carry=1;
                curr1->data-=10;
            }
            if(curr1->next==NULL and carry)
                curr1->next=new Node(0);
            curr1=curr1->next;
            if(curr2!=NULL)
                curr2=curr2->next;
        }
    } 
    Node* remove0(Node *head){
        Node* curr=head;
        while(curr!=NULL and curr->data==0)
            curr=curr->next;
        return curr;
    }
    void print(Node* head){
        Node* curr=head;
        while(curr!=NULL){
            cout<<curr->data<<" -> ";
            curr=curr->next;
        }
        cout<<endl;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        auto [rhead1,len1]=reverse(head1);
        auto [rhead2,len2]=reverse(head2);
        if(len2>len1)
            swap(rhead1,rhead2);
        // print(rhead1);
        // print(rhead2);
        add(rhead1,rhead2);
        auto [ans,ans_len]=reverse(rhead1);
        return remove0(ans);
    }
};