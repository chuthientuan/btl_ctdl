#include<bits/stdc++.h>
using namespace std;
class Stack{
	private:
		stack<char> st;
	public:
		void push(char c){
			st.push(c);
		}
		char pop(){
			char c= st.top();
			st.pop();
			return c;
		}
		bool empty() {
        		return st.empty();
    		}
		char top(){
			return st.top();
		}
};
class ExpressionEvaluator{
	private:
		Stack Opr;
		Stack BLExp;
		string s;
		string p;
	public:
		//Thuc hien cac phep tinh
		int f(char op, int a, int b){
			if(op=='+') return a+b;
			if(op=='-') return a-b;
			if(op=='*') return a*b;
			if(op=='/'){
				if(b!=0) return a/b;
			}
		}
		//Kiem tra toan tu
		bool isOperator(char c){
			return (c=='+'|| c=='-'|| c=='*'|| c=='/');
		}
		//Kiem tra muc do uu tien
		bool priority(char op1, char op2){
			if((op1=='*'|| op1=='/')&&(op2=='+' ||op2=='-')){
				return true;
			}
			return false;
		}
		ExpressionEvaluator(string s){
			this->s=s;
		}
		ExpressionEvaluator(){
		}
		void input(){
			cout<<"Nhap bieu thuc dang trung to: ";
			getline(cin,s);
		}
		//Chuyen bieu thuc sang dang hau to
		string infix(){
			for(int i=0;i<s.size();i++){
				if('0'<=s[i] && s[i]<='9'){
					p+=s[i];
					p+=' ';
				}
				else if(s[i]==' '){
					continue;
				}
				else if(s[i]=='('){
					Opr.push(s[i]);
				}
				else if(s[i]==')'){
					while(!Opr.empty() && Opr.top()!='('){
						p+=Opr.top();
						p+=' ';
						Opr.pop();
					}
					if(!Opr.empty() && Opr.top()=='('){
						Opr.pop();
					}
				}
				else if(isOperator(s[i])){
					while(!Opr.empty() && priority(Opr.top(),s[i])){
						p+=Opr.top();
						p+=' ';
						Opr.pop();
					}
					Opr.push(s[i]);
				}
			}
			while(!Opr.empty()){
				p+=Opr.top();
				p+=' ';
				Opr.pop();
			}
			return p;
		}
		//Tinh gia tri bieu thuc
		int Evaluator(){
			for(int i=0;i<p.size();i++){
				if('0'<=p[i] && p[i]<='9'){
					int num=0;
					while (i<p.size() && '0'<=p[i] && p[i]<='9') {
                			num=num*10 +(p[i]-'0');
                			i++;
            			}
            			BLExp.push(num);	
				}
				else if(p[i]==' '){
					continue;
				}
				else if(isOperator(p[i])){
					int b= BLExp.top();
					BLExp.pop();
					int a= BLExp.top();
					BLExp.pop();
					int result= f(p[i],a,b);
					BLExp.push(result);
				}
			}
			return BLExp.top();
		}
};
int main(){
	ExpressionEvaluator evaluator;
	evaluator.input();
	cout<<"Dang bieu thuc hau to: "<<evaluator.infix()<<endl;
	cout<<"Gia tri cua bieu thuc bang: "<<evaluator.Evaluator();
}
