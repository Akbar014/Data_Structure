#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node *next;
        Node (int val){
            this->val = val;
            this->next = NULL;
        }
};

class MyQueue{
    public:
        Node* head ;
        Node * tail;
        int sz;
        MyQueue(){
            head = NULL;
            tail = NULL;
            sz = 0;
        }
        void push(int val){
            sz++;
            Node * newNode = new Node(val);
            if(head==NULL){
                head = newNode;
                tail = newNode;
                return ;
            }
            tail->next = newNode;
            tail = newNode;
        }

        void pop(){
            sz--;
            Node * deleteNode = head;
            head = head->next;
            if(head==NULL){
                tail = NULL;
                return;
            }
            delete deleteNode;


        }

        int front(){
            return head->val;
        }

        int size(){
            return sz;
        }

        bool empty(){
            if(sz==0) return true;
            else return false;
        }
};
int main(){

    MyQueue q;
    int n;
    cin >>n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}