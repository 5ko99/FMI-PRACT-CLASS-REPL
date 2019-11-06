#include <iostream>
#include <string>
#include <queue>
using namespace std;
enum Commands{create,show,del,edit};
queue<string> evaluateAtr(string);
Commands evaluateCommand(string);
int main() {
    string cmd;
    string atr;
    Commands cmdN;
    queue<string> atrQ;
    while(true){
        if(cmd=="exit") break;
        cin>>cmd;
        cmdN = evaluateCommand(cmd);
        getline(cin, atr);
        atrQ=evaluateAtr(atr);
    }
    return 0;
}
Commands evaluateCommand(string str){
    if(str=="create") return create;
    if(str=="show") return show;
    if(str=="delete") return del;
    if(str=="edit") return edit;
}
queue<string> evaluateAtr(string atr){
    queue<string> q;
    char c=atr[0];
    int i=0;
    string temp;
    while(c!='\0'){
        while(c!=' '){
            temp.append(1,c);
            i++;
            c=atr[i];
        }
        q.push(temp);
    }
    return q;
}