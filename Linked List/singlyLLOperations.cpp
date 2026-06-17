#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertArrayToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverseLL(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "No Elements" << endl;
    }
    cout << "LL elements are : ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *insertAtHead(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *insertAtTail(Node *head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    Node *prev = NULL;
    Node *cur = head;
    while (cur)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = temp;
    return head;
}
Node *deleteAtTail(Node *head)
{

    // if(head==NULL || head->next==NULL){
    //     return NULL;
    // }
    // Node* prev2=NULL;
    // Node *prev=NULL;
    // Node *cur=head;
    // while(cur){
    //     prev2=prev;
    //     prev=cur;
    //     cur=cur->next;
    // }
    // prev2->next=nullptr;
    // delete prev;
    // return head;
 
    //just reach the second last elements
    if (head == NULL || head->next == NULL) return NULL;
    Node *temp=head;
    while(temp->next->next!=NULL) temp=temp->next;
    delete(temp->next);
    temp->next=nullptr;
    return head;
    
}

Node *deleteKthNode(Node *head,int k){
    if(head==NULL) return NULL;
    int cnt=0;
    Node *temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    if(k>cnt || k<=0){
        cout<<"Deletion not possible\n";
        return head;
    }
    if(k==1){
        temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node *prev=NULL;
    temp=head;
    int i=1;
    while(i<k){
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    delete temp;
    return head;
}
Node *deleteKthNodeII(Node *head,int k){
    if(head==NULL) return NULL;

    if(k==1){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node *temp=head;
    Node *prev=NULL;
    int cnt=1;

    while(temp && cnt<k){
        prev=temp;
        temp=temp->next;
        cnt++;
    }

    if(temp==NULL){
        cout<<"Deletion not possible\n";
        return head;
    }

    prev->next=temp->next;
    delete temp;

    return head;
}
Node *insertAtKth(Node *head,int k,int val){
    if(head==NULL) return head;
    if(k <= 0) return head;
    if(k==1){
        Node *temp=new Node(val);
        temp->next=head;
        head=temp;
        return head;
    }
    int i=1;
    Node *cur=head;
    Node *prev=NULL;
    while(cur!=NULL  && i<k){
       i++;
       prev=cur;
       cur=cur->next;
    }
    if(cur==NULL){
        cout<<"Insertion not possible"<<endl;
        return head;

    }
    Node *temp=new Node(val);
    temp->next=cur;
    prev->next=temp;
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    // convert arr to linked list
    Node *head = convertArrayToLL(arr);
    traverseLL(head);
    head = insertAtHead(head, 0);
    traverseLL(head);
    head = deleteHead(head);
    traverseLL(head);
    head = insertAtTail(head, 8);
    traverseLL(head);
    head = deleteKthNode(head,8);
    traverseLL(head);
    head=insertAtKth(head,7,3333);
    traverseLL(head);


    return 0;
}