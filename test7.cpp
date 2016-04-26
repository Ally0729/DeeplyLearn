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
