#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void ReadTXT(){
    // AVLtree avl;
    ifstream in;
    string ch="";
    in.open("dictionary.txt");
        while (!in.eof()){
            // AVLnode* temp;
            getline(in,ch);
            cout<<ch<<" ";
            // avl.insert(temp->data,avl.root);
        }
    in.close();
    // return avl.root;
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
            cout<<temp<<" ";
        }
        cout<<endl;

    // }
}

void letterSubs(string str){
    // char ch = 65;
    //65 - 90 && 97-122 // 50 letters
    for(int j=0 ; str[j] !='\0';j++){
        string temp = str;
        for(int i=65;i<=122;i++){
            temp[j] = i;
            // string ss = dict.search(temp);
            // if(ss !=""){
            //     stk.push(ss);
            // }
            if(i==90){
                i=96;
            }
            cout<<temp<<" ";
        }
        cout<<endl;
    }
}

void letterinsert(string str){
    for(int i=65;i<=122;i++){
        for(int k=0; str[k] !='\0';k++){
            string temp = "";
            for(int j =0 ; str[j]!='\0';j++){
                if(k==j){
                    temp+=i;
 
                }
                    temp+=str[j];
            }
            cout<<temp<<" ";
        }

        if(i==90){
            i=96;
        }
    cout<<endl;
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
                cout<<temp<<" ";
            }
            cout<<endl;
        }

int main() {
    // cout << "Hello, World!" << endl;
    // ReadTXT();
    letteromit("catt");
    // letterinsert("plce");
    // letterinsert("12345");
    // letterReversal("paernt");
    return 0;
}