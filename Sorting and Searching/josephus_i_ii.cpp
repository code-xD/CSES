#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int dat){
            data = dat;
            next = NULL;
            prev = NULL;
        }

        Node* add(Node* tail, int data){
            if(tail == NULL)return new Node(data);
            Node* ele = new Node(data);
            tail->next = ele;
            ele->prev = tail;
            return tail->next;
        }

        Node* del(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            Node* ret = node->next;
            node->next = NULL;
            node->prev = NULL;
            free(node);
            return ret;
        }

};


int main(){
    int n;
    cin>>n;
    Node* head = NULL;
    Node* tail = NULL;
    int size = n;
    for(int i=1; i<=n; i++){
        if(i==1)head = tail = head->add(head, i);
        else
            tail = head->add(tail, i);
    }
    // Circular LinkedList Created.
    tail->next = head;
    head->prev = tail;
    int k=2;
    cin>>k;
    k++;
    Node* itr = head;
    while(size > 1){
        for (int i = 1; i < k; i++)
            itr = itr->next;
        cout<<itr->data<<" ";
        itr = head->del(itr);
        size--;
    }
    cout<<itr->data<<endl;
    return 0;
}