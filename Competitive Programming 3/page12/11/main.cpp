#include <bits/stdc++.h>

#define maxLength 1000008

using namespace std;

stack<double>operands[maxLength];
stack<char>operators[maxLength];
map<char,int>priority={make_pair('+',1),make_pair('-',1),make_pair('*',2),make_pair('/',2)};
int st;

int getPriority(char x){
    return priority[x];
}

template<class T>
T getAndPop(stack<T> & refSt){
    T x = refSt.top();
    refSt.pop();
    return x ; 
}

double evaluate(double a, double b, char op){
    if(op=='+')
        return a + b;
    if(op=='-')
        return a - b;
    if(op=='*')
        return a * b;
    return a / b;
}

void evaluateNecessary(int priority){
    while(!operators[st].empty()&&getPriority(operators[st].top())>=priority){
        //evaluate
        double second = getAndPop(operands[st]);
        double first = getAndPop(operands[st]);
        first = evaluate(first,second,operators[st].top());
        //cout << "first: " << first << "\n";
        operators[st].pop();
        operands[st].push(first);
    }
}

int main(){
    string expr;
    getline(cin,expr);
    double currentOperand = 0;
    bool isPreviousOperand = false,decimalPoint=false;
    int dividend=10;
    for(char x : expr){
        if(x=='.'){
            decimalPoint=true;
        }else if(isdigit(x)){
            if(decimalPoint){
                currentOperand += (double) (x-'0') / dividend , dividend *=10; 
            }else{
                currentOperand *= dividend, currentOperand += x - '0';
            }
            //cout << "currentOperand: " << currentOperand << "\n";
            isPreviousOperand = true; 
        }else{
            if(isPreviousOperand){
                operands[st].push(currentOperand);
                currentOperand=0;
                dividend=10;
                isPreviousOperand=decimalPoint=false;
            }
            if(x!=' '){
                if(x=='('){
                    st++;
                }else if(x==')'){
                    evaluateNecessary(0); //0 is the one evaluated at last
                    operands[st-1].push(operands[st].top());
                    operands[st--].pop();
                }else{
                    //it is an operator
                    int priority = getPriority(x);
                    evaluateNecessary(priority);
                    operators[st].push(x);
                }
            }
        }
    }
    if(isPreviousOperand)
        operands[st].push(currentOperand);
    evaluateNecessary(0);// it is like the last parenthesis ')'
    cout << operands[st].top() << "\n" ; 
    return 0;
}