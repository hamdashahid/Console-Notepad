#include<iostream>
#include <ncurses.h>
#include <fstream>
#include<string>
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
            // front = front->next;
            if(front->next == NULL){
                front=NULL;
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
};

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
            delete temp;

            if(tail == NULL) {
                head = NULL;  
            }
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

        string search(string str){
            if(isEmpty() == true) return "";
            AVLnode* temp = root;

            while(temp!=NULL){
                if(str<temp->data){
                    temp=temp->left;
                }else if(str>temp->data){
                    temp = temp->right;
                }else{
                    return temp->data;
                }
            }
            return "";
        }

};

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

class NotePad{
    public:
        AVLtree dict;
        List li;
        Stack stk;
        Queue Q1;   
        int x ;
        int y;
        int prevx;
        int prevy;
        Stack xpos;

        NotePad(AVLtree d){
            dict = d;
            li = List();
            Q1 = Queue();
            stk = Stack();
            x=15;
            y=10;
            prevx=x;
            prevy=y;
            xpos = Stack();
        }

        void display(){
            system("stty -ixon");
            initscr();
            noecho();
            cbreak();
            NotepadScreen();


            getch();
            endwin();
        }

        void NotepadScreen(){
            // clearScreen();
            clear();
            refresh();
            start_color();
            init_pair(1,COLOR_MAGENTA,COLOR_BLACK);

            attron(COLOR_PAIR(1)); //color on
            mvprintw(1,23,"  ===================================================================  ");
            mvprintw(2,23,"  ||                                                               ||  ");
            mvprintw(3,23,"  ||                          :) NOTEPAD :)                        ||  ");
            mvprintw(4,23,"  ||                                         BY HAMDA SHAHID       ||  ");
            mvprintw(5,23,"  ===================================================================  ");
            // attroff(COLOR_PAIR(1)); // color off
            bkgd(COLOR_PAIR(1));
            border(0,0,0,0,0,0,0,0);
            takeinputs();
            refresh();
        }

        void takeinputs(){
            keypad(stdscr, TRUE);
            cbreak();
            noecho();
            nodelay(stdscr, TRUE);  
            for(int i=0 ; true ; i++){
                char ch = getch();
                switch(ch){
                    case 12 :               //CTRL+L
                        load();
                        break;
                    case 19 :               //CTRL+S
                        save();
                        break;   
                    case 8:                 //BACKSPACE
                        backspace();
                        break;    
                    case 32:                //SPACE
                        xpos.push(to_string(x));
                        li.append(ch);
                        x++;
                        // word check
                        break;
                    case 10:        //ENTER
                        li.append('\n');
                        xpos.push(to_string(x));
                        x=15;
                        y++;
                        //word check
                        break;    
                    case 9:                 //TAB
                        li.append(ch);
                        xpos.push(to_string(x));
                        x+=4;
                        // /word check
                        break;    
                    case 27:                //ESC
                        return;     
                    default:
                       
                        if((ch >=32 && ch<127) || ch==9 || ch==10 ){
                            printText(ch);
                        }
                        // return;
                }

            }
        }

        void Wordcheck(){
            string str = "";
            while(Q1.isEmpty() == false){
                str+=Q1.dequeue();
            }
            
            string str2 = dict.search(str);

            if(str2==""){

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
            char ch = 65;
            //65 - 90 && 97-122 // 50 letters
            for(int j=0 ; str[j] !='\0';j++){
                string temp = str;
                for(int i=65;i<=122;i++){
                    temp[j] = i;
                    string ss = dict.search(temp);
                    if(ss !=""){
                        stk.push(ss);
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
                string ss = dict.search(temp);
                if(ss !=""){
                    stk.push(ss);
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
                    string ss = dict.search(temp);
                    if(ss !=""){
                        stk.push(ss);
                    }
                    // cout<<temp<<" ";
                }
                if(i==90){
                    i=96;
                }
            // cout<<endl;
            }
        }

        string letterReversal(string str){
            for(int i=0;str[i]!='\0';i++){
                string temp = "";
                for(int j=0;str[j]!='\0';j++){
                    if(i==j){
                        // char te = str[i];
                        temp[j] = str[j+1];
                        temp[j+1] = str[j];

                    }else{
                        temp+=str[j];
                    }
                }
            }
        }

        void suggestions(string str){

        }

        void printText(char a){
           
            if(y<=27 && x<=100){
                if((a >=32 && a<127) || a==9 || a==10 ){
                    li.append(a);
                    Q1.enqueue(a);
                    // printText(a);
                }
                if(a >= 32 && a < 127){
                    move(y,x);
                    addch(a);
                    xpos.push(to_string(x));
                    x++;
                }
                if(a==10){
                    // prevx=x;
                    xpos.push(to_string(x));
                    x=15;
                    y++;

                }
                if(a==9){
                    xpos.push(to_string(x));
                    x+=4;
                }
            }else{
                refresh();
                start_color();
                init_pair(2,COLOR_BLACK,COLOR_MAGENTA);

                attron(COLOR_PAIR(2)); //color on
                move(28,40);
                mvprintw(28,40,"  ================================  ");
                move(29,40);
                mvprintw(29,40,"  ||    :( NO MORE SPACE :()    ||  ");
                move(30,40);
                mvprintw(30,40,"  ================================  ");

                // sleep(2000000);
                refresh();
                napms(100);
                attroff(COLOR_PAIR(2)); // color off
                // delay_output(2000);
                refresh();
                move(28,40);
                mvprintw(28,40,"                                    ");
                move(29,40);
                mvprintw(29,40,"                                    ");
                move(30,40);
                mvprintw(30,40,"                                    ");
                refresh();
            }

            // if(a==8){
            //     cout<<"backspace";
            //     x--;
            // }
            
            refresh();
        }

        void load(){
            ifstream in("save.txt");
            if(!in){
                start_color();
                init_pair(2,COLOR_BLACK,COLOR_MAGENTA);

                attron(COLOR_PAIR(2)); //color on
                move(28,40);
                mvprintw(28,40,"  ===============================  ");
                move(29,40);
                mvprintw(29,40,"  ||    :( NO FILE FOUND :(    ||  ");
                move(30,40);
                mvprintw(30,40,"  ===============================  ");

                // sleep(2000000);
                refresh();
                napms(1500);
                attroff(COLOR_PAIR(2)); // color off
                // delay_output(2000);
                refresh();
                move(28,40);
                mvprintw(28,40,"                                   ");
                move(29,40);
                mvprintw(29,40,"                                   ");
                move(30,40);
                mvprintw(30,40,"                                   ");
                refresh();
                // usleep(2000000);
                // mvprintw(28,40,"                                   ");
                // mvprintw(29,40,"                                   ");
                // mvprintw(30,40,"                                   ");
            }else{
                printText(10);
                while(!in.eof()){
                    string str ="";
                    getline(in,str);
                    for(int i=0 ; str[i]!='\0' ;i++){
                        // li.append(str[i]);
                        printText(str[i]);

                    }
                    printText(10);
                }
            }

        }

        void save(){
            // cout<<"hello\n";
            ofstream out;
            if(li.isEmpty() == true) return;
            out.open("save.txt" );
                ListNode* temp = li.head;
                // StackNode* temp = stk.top;
                while(temp!=NULL){
                    out<<temp->data;
                    temp=temp->next;
                }
            out.close();
            refresh();
            start_color();
            init_pair(2,COLOR_BLACK,COLOR_MAGENTA);

            attron(COLOR_PAIR(2)); //color on
            move(28,40);
            mvprintw(28,40,"  ========================================  ");
            move(29,40);
            mvprintw(29,40,"  ||    :) FILE SAVED TO save.txt :)    ||  ");
            move(30,40);
            mvprintw(30,40,"  ========================================  ");

            // sleep(2000000);
            refresh();
            napms(1500);
            attroff(COLOR_PAIR(2)); // color off
            // delay_output(2000);
            refresh();
            move(28,40);
            mvprintw(28,40,"                                             ");
            move(29,40);
            mvprintw(29,40,"                                             ");
            move(30,40);
            mvprintw(30,40,"                                             ");
            refresh();
        }
        
        void backspace(){
            // cout<<x<<" ";
            if (y>10 && x == 15){
                y--;
                // x=prevx;
                x = stoi(xpos.pop());
                move(y,x);
                addch(' ');
                // move(y,x);
                li.remove();
                Q1.dequeue();
            }
            
           if(x<=15){
           }else{
                x = stoi(xpos.pop());
                move(y,x);
                addch(' ');
                // move(y,x);
                li.remove();
           }
           
           
        }

};

int main(){
    AVLtree DictTree;
    cout<<"\n<================ READING DICTIONARY ==========================>\n";
    DictTree.root = ReadTXT();
    cout<<"\n<===================DICTIONARY READ SUCCESSFULLY ===============>\n\n";
    NotePad N(DictTree);
    N.display();
            // cout<<"yes\n";

    // DictTree.PreOrder(DictTree.root);
    cout<<"list\n";
    N.li.display();
    // cout<<"\n STACK\n";
    // N.stk.display();

    // cout<<"HELLO WORLD \n";
    return 0;
}