//chapter 7
//类的成员函数声明一定要在类内，定义可以在内在外，一般简单的函数在内定义——隐式的内联函数，超过五行的函数在外定义
//在外定义时一定要在函数名前加类名，加了类名编译器就知道接下来的代码都在类的作用域内
//之所以使用::是因为类本身就是一个作用域
//根据combine()函数，当前类类型的对象不会是const对象，因此不用加const
#include <iostream>
#include "Sales_data.h"
using namespace std;
//构造函数
Sales_data::Sales_data(istream& cin){//类的构造函数和成员函数都和类紧密相连，一旦定义在类外，函数名前要加类名
	read(cin,*this);//初始化整个对象
}
//成员函数
Sales_data& Sales_data::combine(const Sales_data& rhs){
	units_sold+=rhs.units_sold;
	revenue+=rhs.revenue;
	return *this;
}
//根据avg_price()函数，当前类类型的对象可以是const对象，因此要加const
double Sales_data::avg_price() const{
	if(units_sold)
		return revenue/units_sold;
	else
		return 0;
}
//非成员函数
//类的辅助函数必须声明和定义在类外部，但是要和类在同一个头文件里
Sales_data& add(const Sales_data& a1,const Sales_data& a2){//使用引用避免copy过程
	Sales_data temp=a1;
	temp.combine(a2);
	return temp;
}
//IO类不允许copy，因此形参使用引用代替copy
//实参和形参都是对象，就是实参对形参的copy，实参是对象形参是引用，就是形参和实参的一种绑定，不用copy
std::istream& read(std::istream& cin,Sales_data& a){
	double price=0.0;
	cin>>a.bookNo>>a.units_sold>>price;
	a.revenue=price*a.units_sold;
	return cin;//返回输入流的对象
}//if(read(read(cin,data1),data2))
//print()函数不负责换行！这样的函数应该减少对格式的控制，方便用户自行选择
std::ostream& print(std::ostream& cout,const Sales_data& a){//不使用形参改变实参，就加上const
	cout<<a.isbn()<<" "<<a.units_sold<<" "<<a.revenue<<" "
		<<a.avg_price();
	return cout;//返回输出流的对象
}

//一个类的成员可以是指向该类的指针或是该类的引用

//Screen::pos——类即作用域
//先编译成员的声明，在编译函数，但这种两阶段的处理方式只适合于成员函数中使用的变量，声明中使用的名字包括返回类型和参数列表中使用的名字必须先声明
//如类型成员一般定义在类的开头，这就属于必须先声明的

//一般来说内层作用域可以重新定义外层作用域中的名字，即使改名字已经使用过
//但是如果是外层作用域typedef了一个类型名，类内使用了改名字，那么类内就不能重新定义该名字

//成员函数中使用的名字按照如下方式解析
//(1)在成员函数内查找声明
//(2)在整个类内查找声明
//(3)在成员函数定义之前的整个作用域内查找声明

//构造函数再探
Sales_data::Sales_data(const string &s,unsigned cnt,double price):bookNo(s),units_sold(cnt),revenue(cnt*price){}

Sales_data::Sales_data(const string &s,unsigned cnt,double price){
	bookNo=s;
	units_sold=cnt;
	revenue=cnt*price;
}
//第一种构造函数方式是直接定义并初始化
//第二种构造函数方式是赋值操作
//如果是const或者引用对象不允许赋值，那么第二种构造方式就是错误的，所以建议使用第一种方式

//构造函数初始值列表只说明用于初始化成员的值，而不限定初始化的具体执行顺序
//成员初始化的执行顺序和类中定义的顺序相同
class X{
	int i;
	int j;
public:
	X(int ii): j(ii), i(j){}
}
//先执行i的初始化，再执行j的初始化，由于i初始化时j还没初始化，因此用j初始化i会出错
//最好令构造函数初始值列表的顺序和类中定义的顺序一致，看起来比较直观

//默认实参和构造函数
class Sales_data{
public:
	Sales_data(std::string s = " "):bookNo(s){}//因为Sales_data()可以调用它，因此它也是默认构造函数
	//其余构造函数和之前一致
	Sales_data(std::string s,unsigned cnt,double rev):bookNo(s),units_sold(cnt),revenue(cnt*rev){}
	Sales_data(std::istream &is){read(is,*this);}
	//其余成员和之前一致
};
//如果一个构造函数为所有形参提供了默认实参，那么它就是默认构造函数

//构造函数定义的隐式转换
//在Sales_data类中，接受string和istream的构造函数分别定义了这两种类型向Sales_data隐式转换的规则
//也就是说在需要Sales_data的地方可以用string和istream代替
//string null_book="9-999-99999-9";'
//构造一个linshideSales_data对象
//该对象的units_sold和revenue等于0，bookNo等于null_book;
//item.combine(null_book);//在null_book隐式转换成Sales_data类的过程中实际调用了Sales_data类中接受一个string对象的构造函数
//等价于以下语句
//string null_book="9-999-99999-9";
//Sales_data s(null_book);
//item.combine(s);
//只允许一步类型转换
//item.combine("9-999-99999-9");//error  字面值常量—string—Sales_data是两步类型转换
//item.combine(string("9-999-99999-9"));//correct 调用string类构造函数
//item.combine(Sales_data("9-999-99999-9"));//correct 调用Sales_data类构造函数

//抑制构造函数定义的隐式转换
//将构造函数声明成explicit，注意explicit抑制的是隐式转换，只用在类内声明的时候使用explicit关键字，类外定义的时候不重复使用
class Sales_data{
public:
	Sales_data();
	Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
	explicit Sales_data(const std::string &s):bookNo(s){}
	explicit Sales_data(std::istream &is);
	//其余与之前版本一致
};
//item.combine(null_book);//error
//item.combine(is);//error
//explicit构造函数只能使用直接初始化，不能使用赋值初始化，因为赋值初始化本身就存在隐式类型转换
//Sales_data item1(null_book);//correct
//Sales_data item2=null_book;//error
//可以显式类型转换
//item.combine(static_cast<Sales_data>(null_book));

//类的静态成员
//static成员（函数）和类的对象没关系，它和类直接相关
//static成员（函数）依旧可以是public也可以是private
class Account{
public:
	void calculate() {amount += amount * interestRate;}
	static double rate() {return interestRate;}
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};
//每个Amount对象都有一个owner和amount变量，所有Amount对象公用interestRate变量
//类似，类的静态成员函数也不应该和任何对象绑定在一起，它们不包含this指针，不能声明成const，也不能使用this指针
//使用作用域访问符访问static成员
//Account::rate();
//虽然静态成员不属于类的某个对象，但obj1.rate()仍然是对的
//static关键字只在类内函数声明的地方使用，类外函数定义的地方不重复使用
//因为静态成员不属于类的任何一个对象，而构造函数构造的是类的对象
//这说明静态成员不是由构造函数初始化的
//静态成员在任何函数外（main()）初始化
//double Amount::interestRate=9;//位于相应.cpp程序main()函数外部
//静态成员的类型可以是不完全类型，非静态成员不可以
class Bar{
public:
	//
private:
	static Bar mem1;//至此类没有定义完，类是不完全类型
	Bar *mem2;
	Bar mem3;//error
};
//statci 成员可以是类类型
//非static成员不可以，只能是类的指针或引用
//static成员可以做默认实参，非static成员不可以