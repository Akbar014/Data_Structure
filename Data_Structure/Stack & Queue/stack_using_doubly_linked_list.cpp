#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node *prev;
        Node (int val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
}; 

class myStack{
    public: 
        Node * head = NULL;
        Node * tail = NULL;
        int sz=0;

    void push(int val){
        Node * newNode = new Node (val);
        sz++;
        if(head==NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pop(){
        sz--;
        if(head==tail){
            head = NULL;
            tail = NULL;
            return;
        }
        Node * deleteNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete deleteNode;
    }

    int top(){
        return tail->val;
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

    myStack s;
    s.push(10);
    s.push(20);
    s.pop();
    s.pop();
    s.push(30);
    s.push(40);

    cout << s.size() << endl;

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    
    return 0;
}