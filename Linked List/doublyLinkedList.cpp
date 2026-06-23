#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
Node *arrayToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        temp->prev = prev;
        prev = temp;
    }
    return head;
}
void traverse(Node *head)
{
    Node *temp = head;
    Node *prev = head; // for traversal from backside
    cout << "Head->Tail ";
    while (temp)
    {
        cout << temp->data << " ";
        prev = temp;
        temp = temp->next;
    }
    // cout << "\nTail->Head ";
    // while (prev)
    // {
    //     cout << prev->data << " ";
    //     prev = prev->prev;
    // }
    cout<<endl;
}

Node *deleteHead(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        return NULL;
    head = head->next;
    if (head)
        head->prev = NULL;
    delete (temp);
    return head;
}
Node *deleteTail(Node*head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    Node*prev=NULL;
    Node*cur=head;
    while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
    }
    if(prev){
        prev->next=NULL;
        delete(cur);
    }
    return head;
}

Node *deleteKthNode(Node*head,int k){
    if(head==NULL) return NULL;
    int cnt=0;
    Node *knode=head;
    while(knode!=NULL){
        cnt++;
        if(cnt==k) break;
        knode=knode->next;
    }

    Node *prev=knode->prev;
    Node *front=knode->next;
    if(prev==NULL && front==NULL) return NULL;
    else if(prev==NULL) return deleteHead(head);
    else if(front==NULL) return deleteTail(head);
    prev->next=front;
    front->prev=prev;
    knode->next=nullptr;
    knode->prev=nullptr;
    delete(knode);
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = arrayToDLL(arr);
    traverse(head);
    head=deleteHead(head);
    traverse(head);
    head=deleteTail(head);
    traverse(head);
    return 0;
}