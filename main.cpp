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
    int height;
    AVLnode* right;
    AVLnode* left;

    AVLnode(string d = "" ,int h = 0, AVLnode* r = NULL , AVLnode* l = NULL){
        data = d;
        height = h;
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

        AVLnode* insert(string data , AVLnode* p){
            AVLnode* add = new AVLnode(data);
            if(p == NULL){
                p = add;
                return p;
            }

            // AVLnode* temp = root;

            if(p->data>data){
                p = insert(data,p->left);
            }else if(p->data<data){
                p = insert(data,p->right);
            }else if(p->data == data){
                cout<<"DUPLICATE DATA \n";
                return p;
            }

            p->height = Height(p);
            if(BalanceFactor(p) ==2){
                if(BalanceFactor(p->left) >=0){
                    //right rotation
                    p = RightRotate(p);
                }else{
                    //left right rotation
                    p = LeftRightRotate(p);
                }
            }else if(BalanceFactor(p) == -2){
                if(BalanceFactor(p->right) >=0 ){
                    //Right left
                    p = RightLeftRotate(p);
                }else{
                    //left rotation
                    p = LeftRotate(p);
                }
            }
            return p;
        }

        AVLnode* del(string data , AVLnode* p){
            if(p==NULL) return p;
            if(data<p->data){
                p = del(data,p->left);
            }else if(data>p->data){
                p = del(data,p->right);
            }else{
                //no child
                if(p->left == NULL && p->right == NULL){
                    delete p;
                    return NULL;
                }

                //one child
                else if (p->left !=NULL && p->right == NULL){
                    AVLnode* temp = p->left;
                    delete p;
                    p = temp;
                    return p;

                }else if(p->right !=NULL && p->left == NULL){
                    AVLnode* temp = p->right;
                    delete p;
                    p = temp;
                    return p;

                }
                 // two children
                else if(p->left !=NULL && p->right !=NULL){
                    //inorder successor will replace
                    AVLnode* inorderSuccessor = findmin(p->right);
                    p->data = inorderSuccessor->data;
                    p = del(inorderSuccessor->data,p->right);
                } 
            }

            p->height = Height(p);
            if(BalanceFactor(p) ==2){
                if(BalanceFactor(p->left) >=0){
                    //right rotation
                    p = RightRotate(p);
                }else{
                    //left right rotation
                    p = LeftRightRotate(p);
                }
            }else if(BalanceFactor(p) == -2){
                if(BalanceFactor(p->right) >=0 ){
                    //Right left
                    p = RightLeftRotate(p);
                }else{
                    //left rotation
                    p = LeftRotate(p);
                }
            }
            return p;
        }

        AVLnode* findmin(AVLnode* p){
            AVLnode* temp = p;
            while(p->left!= NULL){
                p = p->left;
            }
            return p;
        }

        bool isEmpty(){
            return root == NULL;
        }

        //        k1
        //      /   \
        //    k2    ...
        //  /   \
        // k3   ....

        AVLnode* RightRotate(AVLnode* p){    
            AVLnode* temp = p->left;
            p->left = temp->right;
            temp->right = p;
            p->height = Height(p);
            temp->height = Height(temp);
            return temp;
        }

        //      k1
        //    /    \
        //  ...     k2
        //         /  \
        //       ...    k3

        AVLnode* LeftRotate(AVLnode* p){
            AVLnode* temp = p->right;
            p->right = temp->left;
            temp->left = p;
            p->height = Height(p);
            temp->height = Height(temp);
            return temp;
        }

        //          k1
        //         /  \
        //       k2   ....
        //      /  \
        //    ...   k3
        //

        AVLnode* LeftRightRotate(AVLnode* p){
            p->left = LeftRotate(p->left);
            p->left->height = Height(p->left);
            p = RightRotate(p);
            p->height = Height(p);

            return p;
        }

        //          k1
        //         /  \
        //       ....  k2
        //            /  \
        //           k3  ....
        //

        AVLnode* RightLeftRotate(AVLnode* p){
            p->right = RightRotate(p->right);
            p->right->height = Height(p->right);
            p = LeftRotate(p);
            p->height = Height(p);
            return p;
        }

        int BalanceFactor(AVLnode* p){
            return (Height(p->left) - Height(p->right));
        }

        int Height(AVLnode* p){
            if(p==NULL) return -1;
            int leftTree = Height(p->left);
            int rightTree = Height(p->right);

            return 1+max(leftTree,rightTree);
        }

        void PreOrder(AVLnode* p){
            if(p==NULL) return;
            cout<<p->data<<"\t";
            PreOrder(p->left);
            PreOrder(p->right);
        }
};


void ReadTXT(){

}


int main(){

    cout<<"HELLO WORLD \n";
    return 0;
}