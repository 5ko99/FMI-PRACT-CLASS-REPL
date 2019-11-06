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
    int i=1;
    char c=atr[i];
    string temp;
    while(c!='\0'){
        while(c!=' ' && c!='\0'){
            temp.append(1,c);
            i++;
            c=atr[i];
        }
        q.push(temp);
        temp="";
        i++;
        c=atr[i];
    }
    return q;
}