#include "stdafx.h"
#include "std_lib_facilities_new_version.h"
using namespace std;
double val;
class Token{
public:
 char kind;        
 double value;     
 Token(char ch)    
  :kind(ch), value(0) { }
 Token(char ch, double val)     
  :kind(ch), value(val) { }
};
Token_stream::Token_stream()
 :full(false), buffer(0)    
{
}
void Token_stream::putback(Token t)
{
 if (full) error("putback() into a full buffer");
 buffer = t;      
 full = true;     
}
 char ch;
 cin >> ch;   
 switch (ch) 
 {
  case ';':   
  case 'q':    
  case '(': case ')': case '+': case '-': case '*': case '/':
   return Token(ch);        
  case '.':
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':

  {
   cin.putback(ch);        
   cin >> val;              
   return Token('#', val);   
  }

 default:
  error("Bad token");
 }
}
Token_stream ts;       

double expression();    
      
double primary()
{
 Token t = ts.get();

 switch (t.kind) 
 {
  case '(':    // handle '(' expression ')'
  {
   double d = expression();
   t = ts.get();
   if (t.kind != ')') error("')' expected)");
   return d;
   break;
  }

  case '#':            
  {
   return t.value;  
   break;
  }
  
  default:
  error("primary expected");
 }
}
double term()
{
 double left = primary();
 Token t = ts.get();        
 while (true) 
 {
  switch (t.kind) 
  {
   case '*':
   {
    left *= primary();
    t = ts.get();
    break;
   }
    
   case '/':
   {
    double d = primary();
    if (d == 0) error("divide by zero");
    left /= d;
    t = ts.get();
    break;
   }  

   default:
   ts.putback(t);     

  return left;
  }
 } 
}
double expression()
{
 double left = term();      
 Token t = ts.get();       
 while (true) {
  switch (t.kind) {
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
int main()
try
{
 while (cin) 
 {
  Token t = ts.get();

  if (t.kind == 'q') 
   break; // 'q' for quit
  if (t.kind == ';')        // ';' for "print now"
   cout << "=" << val << '\n';
  else
   ts.putback(t);
  val = expression();
 }
 keep_window_open();
}
catch (exception& e) {
 cerr << "error: " << e.what() << '\n';
 keep_window_open();
 return 1;
}
catch (...) {
 cerr << "Oops: unknown exception!\n";
 keep_window_open();
 return 2;
}
