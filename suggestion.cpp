#include <iostream>
#include <string>
#include<fstream>
// #include <stack>
// #include <queue>
// #include "dictionary.h" // Assuming you have a dictionary class for searching words

using namespace std;

// queue<char> Q1;
// stack<string> stk;
// // Dictionary dict; // Assuming you have a Dictionary class instance

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
    char data;
    QueueNode* next;

    QueueNode(char d ='\0' , QueueNode* nxt = NULL){
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

        void enqueue(char add){
            if(isEmpty() == true){
                front = new QueueNode(add);
                rear = front;
                return;
            }

            rear->next = new QueueNode(add);
            rear = rear->next;
        }

        char dequeue(){
            if(isEmpty() == true){
                cout<<"QUEUE IS EMPTY \n";
                return '\0';
            }

            QueueNode* temp = front;
            front = front->next;
            if(front == NULL){
                rear = NULL;
            }
            char ch = temp->data;
            delete temp;
            return ch;
        }

        bool isEmpty(){
            return front == NULL && rear == NULL;
        }

        void display(){
            if (isEmpty()) {
                cout << "QUEUE IS EMPTY" << endl;
                return;
            }
            QueueNode* temp = front;
            while(temp != rear){
                cout << temp->data;
                temp = temp->next;
            }
            cout << rear->data << endl;
        }
        
        void makeEmpty(){
            while(!isEmpty()){
                dequeue();
            }
        }
}Q1;


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
            if(isEmpty()) return "";
            StackNode* temp = top;
            top = top->next;
            string data = temp->data;
            delete temp;  
            return data;
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
}stk;

class List{
    public:
        ListNode* head;
        ListNode* tail;

        List(ListNode* h =NULL , ListNode* t = NULL){
            head = h;
            tail = t;
        }

        void append(char c) {
            if (isEmpty()) {
                head = new ListNode(c);  
                tail = head;            
                return;
            }
            
            ListNode* add = new ListNode(c);  
            tail->next = add;                 
            add->prev = tail;                 
            tail = add;                      
        }

        void remove(){
            if(isEmpty()) return;

            ListNode* temp = tail;
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }
            delete temp;

            if(tail == NULL) {
                head = NULL;  
            }
        }


        bool isEmpty(){
            return head == NULL;
        }

        void display(){
            if(isEmpty() == true){
                cout<<"LIST IS EMPTY\n";
                return;
            }
            ListNode* temp = head;
            while(temp!=NULL){
                cout<<temp->data;
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
            if(p == NULL){
                AVLnode* add = new AVLnode(data);
                p = add;
                return p;
            }

            // AVLnode* temp = root;

            if(p->data>data){
                p->left = insert(data,p->left);
            }else if(p->data<data){
                p->right = insert(data,p->right);
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
                p->left = del(data,p->left);
            }else if(data>p->data){
                p->right = del(data,p->right);
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
            // AVLnode* temp = p;
            if(p==NULL) return NULL;
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

        bool search(string str){
            if(isEmpty() == true) return false;
            AVLnode* temp = root;

            while(temp!=NULL){
                if(str<temp->data){
                    temp=temp->left;
                }else if(str>temp->data){
                    temp = temp->right;
                }else{
                    return true;
                }
            }
            return false;
        }

} dict;

AVLnode* ReadTXT(){
    AVLtree avl;
    ifstream in;
    in.open("dictionary.txt");
        while (!in.eof()){
            AVLnode* temp = new AVLnode();
            getline(in,temp->data);
            // cout<<"yes\n";
            avl.root = avl.insert(temp->data,avl.root);
            // cout<<temp->data<<" ";
            // cout<<"INSERTED\t";
            // 
        }
    in.close();
    // avl.PreOrder(avl.root);
    // cout<<avl.root<<endl;
    return avl.root;
}

class check{
    public:
        void Wordcheck(string str){
            // string str = "";
            // while(Q1.isEmpty() == false){
            //     str+=Q1.dequeue();
            // }
            
            bool str2 = dict.search(str);

            if(str2==false){
                suggestions(str);
            }

        }

        bool modifyWord(string str){
            letterSubs(str);
            letteromit(str);
            letterinsert(str);
            letterReversal(str);
            if( stk.isEmpty() == false){
                return true;
            }
            return false;
        }

        void letterSubs(string str){
            // char ch = 65;
            //65 - 90 && 97-122 // 50 letters
            for(int j=0 ; str[j] !='\0';j++){
                string temp = str;
                for(int i=65;i<=122;i++){
                    temp[j] = i;
                    bool ss = dict.search(temp);
                    if(ss ==true){
                        stk.push(temp);
                    }
                    if(i==90){
                        i=96;
                    }
                }
            }
        }

        void letteromit(string str){
        // for(int i=0 ; str[i] !='\0' ; i++){
            for(int j=0 ;str[j]!='\0';j++){
                string temp ="";
                for(int k=0 ; str[k]!='\0';k++){
                    if(k==j ){
                        //skip
                    }else{
                        temp+=str[k];
                    }
                }
                bool ss = dict.search(temp);
                if(ss ==true){
                    stk.push(temp);
                }

                // cout<<temp<<" ";
            }
            // cout<<endl;

    // }
        }

        void letterinsert(string str){
            for(int i=65;i<=122;i++){
                for(int k=0; str[k] !='\0';k++){
                    string temp = "";
                    for(int j =0 ; str[j]!='\0';j++){
                        if(k==j){
                            temp+=i;
                        }else{
                            temp+=str[j];
                        }
                    }
                    bool ss = dict.search(temp);
                    if(ss ==true){
                        stk.push(temp);
                    }
                    // cout<<temp<<" ";
                }
                if(i==90){
                    i=96;
                }
            // cout<<endl;
            }
        }

        void letterReversal(string str){
            for(int i=0;str[i]!='\0';i++){
                string temp = "";
                for(int j=0;str[j]!='\0';j++){
                    if(i==j && str[j+1] !='\0'){
                        char te = temp[j];
                       temp+=str[j+1];
                        temp+=str[j];
                        j++;

                    }else{
                        temp+=str[j];
                    }
                }
                bool ss = dict.search(temp);
                if(ss ==true){
                    stk.push(temp);
                }
                // cout<<temp<<" ";
            }
            // cout<<endl;
        }

        void suggestions(string str){
            // cout<<"SPACE \n";
            // stk.display();
            bool modify = modifyWord(str);
            int xcor = 70;
            int ycor = 20;
            if(modify==true){
                // while(stk.isEmpty()==false){
                //     mvprintw(ycor,xcor,"%s","                 ");
                //     mvprintw(ycor,xcor,"%s",((stk.pop()).c_str()));
                //     ycor++;
                // }
            }
        }

};

int main(){
        // AVLtree DictTree;
    cout<<"\n<================ READING DICTIONARY ==========================>\n";
    dict.root = ReadTXT();
    cout<<"\n<===================DICTIONARY READ SUCCESSFULLY ===============>\n\n";
    // NotePad N(DictTree);
    // N.display();
            // cout<<"yes\n";
            check c;
    c.Wordcheck("plce");
    // DictTree.PreOrder(DictTree.root);
    // cout<<"list\n";
    // N.li.display();
    // cout<<"\n QUEUE\n";
    // N.Q1.display();
    // cout<<"\nSTACK\n";
    stk.display();

    // cout<<"HELLO WORLD \n";
    return 0;
}