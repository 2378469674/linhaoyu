#include<stdio.h>
#include<iostream>
#include<exception>
#include<stdbool.h>
using namespace std;
inline void keep_window_open(){
	char ch;
	cin >> ch;
}
 
const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
 
class Token{
	public:
		char kind;
		double value;
		Token(char ch);
		Token(char ch, double val);
};
Token::Token(char ch)
	:kind(ch), value(0)
	{
	}
 
Token::Token(char ch, double val)
	:kind(ch), value(val)
	{
	}
 
class Token_stream{
	public:
		Token_stream();
		Token get();
		void putback(Token t);
		void ignore(char c);
	private:
		bool full;
		Token buffer;
};
Token_stream::Token_stream()
	:full(false),buffer(0)
	{
	}
void Token_stream::putback(Token t){
	if(full){
		perror("putback() into a full buffer");
	}
	buffer = t;
	full = true;
}
Token Token_stream::get(){
	if(full){
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	
	switch(ch){
		case print: 
		case quit:
		case '(': 
		case ')': 
		case '+': 
		case '-': 
		case '*': 
		case '/':  
		case '%':
			return Token(ch);
			
		case '.':
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9': 
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token(number, val);
		}
		default:
			perror("Bad Token");
	}
}
void Token_stream::ignore(char c){
	if(full && c == buffer.kind){
		full = false;
		return ;
	}
	
	full = false;
	
	char ch = 0;
	while(cin >> ch){
		if (ch == c){
			return ;
		}
	}
}
 
Token_stream ts;
double expression();
 
double primary(){
	Token t = ts.get();
	switch(t.kind){
		case '(':
			{
				double d = expression();
				t = ts.get();
				if(t.kind != ')'){
				perror("')' expected");
				}
				return d;
			}
		case number:
			return t.value;
		case '+':
			return primary(); 
		case '-':
			return -primary();
		default:
			perror("primary expected");
	}
}
 
double term(){
	double left = primary();
	Token t = ts.get();
	
	while(true){
		switch(t.kind){
			
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
				{
					double d = primary();
					if(d == 0) {
					perror("divide by zero");
					}
					left /= d;
					t = ts.get();
					break;
				} 
			case '%':
				{
					double d = primary();
					int i1 = int(left);
					if(i1 != left ){
						perror("left-hand operand of % not int");
					}
					int i2 = int(d);
					if(i2 != d ){
						perror("right-hand operand of % not int");
					}
					if(i2 == 0){
						perror("%:divide by zero");
					}
					left = i1%i2;
					t = ts.get();
					break;
				}
			default:
				ts.putback(t);
				return left;
		}
	}
}
 
double expression(){
	double left = term();
	Token t = ts.get();
	
	while(true){
		switch(t.kind){
			
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}
 
void  clean_up_mess()
{
	ts.ignore(print);
}
 
void calculator(){
	while(cin){
		try{
		cout << prompt;
			Token t = ts.get();
			while(t.kind == print){
				t = ts.get();
			}
			if(t.kind == quit){   
				return ;
			}
			ts.putback(t);
			cout << result << expression() << endl;
		}
		catch(exception& e){
			cerr << e.what() << endl;
			clean_up_mess();
		}
	}
}
 
int main()
try{
	calculator();
	keep_window_open();
	return 0;
}

catch(exception& e){
	cerr << e.what() << endl;
	keep_window_open();
	return 1;
}
catch(...){
	cerr << "exception" << endl;
	keep_window_open();
	return 2;
}
