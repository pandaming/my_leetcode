#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

int str2int(string a){
    int result=0;
    bool neg = false;
    for(int i=0; i<a.size(); i++){
        if(i==0 && a[i] == '-'){
            neg = true;
            continue;
        }
        result = result *10 + (a[i]-'0');
    }
    return neg? -result : result;
}

int evalRPN(vector<string> &tokens) {
    vector<int> stack;
    for(int i=0; i<tokens.size(); i++){
        if(tokens[i] == "+" || tokens[i] == "-" ||
           tokens[i] == "*" || tokens[i] == "/"){
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();
            int c;
            if(tokens[i] == "+"){
                c = a+b;
            }else if(tokens[i] == "-"){
                c = a-b;
            }else if(tokens[i] == "*"){
                c = a*b;
            }else{
                c = a/b;
            }
            stack.push_back(c);
        }else{
            int num = str2int(tokens[i]);
            stack.push_back(num);
        }
    }
    return stack.back();
}

int main(){
    vector<string> vec = {"4", "-2","/","2","-3","-","-"};
    cout << evalRPN(vec) << endl;
//    string a = "-123";
//    cout << str2int(a);
}