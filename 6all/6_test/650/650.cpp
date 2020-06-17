


//声明
void f();
void f(int);
void f(int,int);
void f(double,double=3.14);
//调用

f(2.56,42);//有二义性
f(42)//完美匹配
f(42,0)//完美匹配
f(2.56,3.14)//完美匹配
