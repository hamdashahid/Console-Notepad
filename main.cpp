#include<iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    ListNode* prev;
    char data;

    ListNode(char d = '\0' , ListNode* n = NULL , ListNode* p = NULL){
        data = d;
        next = n;
        prev = p;
    }

};

struct AVLnode{
    string data;
    AVLnode* right;
    AVLnode* left;

    AVLnode(string d = "" , AVLnode* r = NULL , AVLnode* l = NULL){
        data = d;
        right = r;
        left = l;
    }

};

struct QueueNode{
    string data;
    QueueNode* next;

    QueueNode(string d = " " , QueueNode* nxt = NULL){
        data = d;
        next = nxt;
    }
};

struct StackNode{
    string data;
    StackNode* next;

    StackNode(string d = " " , StackNode* n = NULL){
        data = d;
        next = n;
    }
};

class Queue{
    public:
        QueueNode* front;
        QueueNode* rear;

        Queue(QueueNode* f =NULL , QueueNode* r = NULL){
            front = f;
            rear = r;
        }

        void enqueue(string add){
            if(isEmpty() == true){
                front = new QueueNode(add);
                rear = front;
                return;
            }

            rear->next = new QueueNode(add);
            rear = rear->next;
        }

        void dequeue(string str){
            if(isEmpty() == true){
                cout<<"QUEUE IS EMPTY \n";
                return;
            }

            QueueNode* temp = front;
            front = front->next;
            delete temp;

        }

        bool isEmpty(){
            return front == NULL && rear == NULL;
        }

        void display(){
            QueueNode* temp = front;
            while(temp!=rear){
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<rear->data<<endl;

        }
        
};

class Stack{
    public:
        StackNode* top;

        Stack(StackNode* t =NULL){
            top = t;
        }

        void push(string add){
            if(isEmpty() == true){
                top = new StackNode(add);
                return;
            }
            StackNode* newNode = new StackNode(add , top);
           
            top = newNode;

        }

        string pop(){
            StackNode* temp = top;
            top = top->next;
            return temp->data;
        }

        bool isEmpty(){
            return top == NULL;
        }

        void display(){
            StackNode* temp = top;
            while(temp!=NULL){
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<endl;
        }
};

class List{
    public:
        ListNode* head;
        ListNode* tail;


        List(ListNode* h =NULL , ListNode* t = NULL){
            head = h;
            tail = t;
        }

        void append(char c){
            if(isEmpty() == true){
                head = new ListNode(c);
                tail = head;
                return;
            }
            ListNode* add = new ListNode(c);
            tail-> next = add;
            add->prev = tail;
            tail = tail->next;
        }

        char remove(char c){
            if (isEmpty() == true) return;

            ListNode* temp = tail;
            char d = temp->data;
            tail = tail->prev;
            delete temp;
            return d;

        }

        bool isEmpty(){
            return head == NULL;
        }

        void display(){
            ListNode* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

class AVLtree{
    public:
        AVLnode* root;

        AVLtree(AVLnode* r = NULL){
            root = r;
        }

        void insert(){

        }

        void del(){

        }

        bool isEmpty(){

        }

        void RightRotate(){

        }

        void LeftRotate(){

        }

        void LeftRightRotate(){

        }

        void RightLeftRotate(){

        }

        void BalanceFactor(){

        }

        void Height(){

        }

        void PreOrder(){

        }
};


void ReadTXT(){

}


int main(){

    cout<<"HELLO WORLD \n";
    return 0;
}