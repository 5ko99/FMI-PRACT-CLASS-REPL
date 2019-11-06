#include <iostream>
#include <string>
#include <queue>
using namespace std;
enum Commands{create,show,del,edit,error};
queue<string> evaluateAtr(string);
Commands evaluateCommand(const string &);
void executeCommand(Commands,const queue<string> &);

void createF(queue<string> queue);

void delF(queue<string> queue);

void showF(queue<string> queue);

void editF(queue<string> queue);

int main() {
    string cmd;
    string atr;
    Commands cmdN;
    queue<string> atrQ;
    while(true){
        cin>>cmd;
        if(cmd=="exit") break;
        //cin.ignore();
        cmdN = evaluateCommand(cmd);
        getline(cin, atr);
        atrQ=evaluateAtr(atr);
        executeCommand(cmdN,atrQ);
    }
    return 0;
}
Commands evaluateCommand(const string & str){
    if(str=="create") return create;
    if(str=="show") return show;
    if(str=="delete") return del;
    if(str=="edit") return edit;
    return error;
}
queue<string> evaluateAtr(string atr){
    queue<string> q;
    int i=0;
    char c=atr[i];
    string temp;
    while(c!='\0'){
        while(c!=' ' && c!='\0'){
            temp.append(1,c);
            i++;
            c=atr[i];
        }
        temp.push_back(' ');
        q.push(temp);
        temp="";
        i++;
        c=atr[i];
    }
    return q;
}
void executeCommand(Commands cmd,const queue<string> & q){
    switch(cmd){
        case create: createF(q);
            break;
        case del: delF(q);
            break;
        case show: showF(q);
            break;
        case edit: editF(q);
            break;
        case error: cerr<<"Wrong command!"<<endl;
    }
}

void editF(queue<string> queue) {
    cout<<"Edit"<<endl;
}

void showF(queue<string> queue) {
    cout<<"ShowF"<<endl;
}

void delF(queue<string> queue) {
    cout<<"delF"<<endl;
}

void createF(queue<string> queue) {
    //TODO: This is just test CreateF
    string data;
    while(!queue.empty()){
        data+=queue.front();
        queue.pop();
    }
    cout<<"Created user:"<<data<<endl;
}
