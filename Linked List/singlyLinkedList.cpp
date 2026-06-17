#include <bits/stdc++.h>
using namespace std;
struct Node
{
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
Node* convertArrayToLL(vector<int>&arr){
    Node *head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1; i<arr.size(); i++){
        Node *temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void traverseLL(Node *head){
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int lengthOfLL(Node * head){
    int cnt=0;
    Node *temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
int searchElement(Node *head,int val){
    Node *temp=head;
    while(temp){
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return -1;
}
int main()
{
    vector<int> arr = {99, 2, 3, 4, 5, 6, 7};
    Node *y = new Node(arr[0], nullptr); // give addess
    cout << y << " " << y->data << endl;
    Node x = Node(arr[1], nullptr); // just an object
    cout << x.data << " " << x.next << endl;

    //convert arr to linked list
    Node *head=convertArrayToLL(arr);
    cout<<"Traverse LL : " <<endl;
    traverseLL(head); cout<<endl;
    cout<<"Length: "<<lengthOfLL(head)<<endl;
    cout<<"Search Element 5 (1-Present/-1-Present: "<<searchElement(head,5)<<endl;
    cout<<"Search Element 100 (1-Present/-1-Present: "<<searchElement(head,100)<<endl;
    return 0;
}