#include <string>
//头文件里不要用using声明
struct Sales_data 
{
	                //常量成员函数
	std::string isbn() const{//一定要思考一下加不加const
		return bookNo;//return this->bookNo;
	}//尽管bookNo在isbn()函数之后定义，但是编译器处理类的时候一般先处理变量再处理函数，所以先后顺序没关系
	//根据isbn()函数，当前类类型的对象可以是const对象，而this不能指向const对象，所以要加const改变this的类型，使其可以指向常量对象，才能
	//正常返回对象的bookNo，否则我们就不能对一个常量对象调用该成员函数了
	Sales_data& combine(const Sales_data& rhs);
	double avg_price() const;
	std::string bookNo;
	unsigned int units_sold;
	double revenue;//VS2010不支持类内初始化
};
//类的成员函数声明一定要在类内，定义可以在内在外，一般简单的函数在内定义——隐式的内联函数，超过五行的函数在外定义
//在外定义时一定要在函数名前加类名，加了类名编译器就知道接下来的代码都在类的作用域内
//之所以使用::是因为类本身就是一个作用域
//根据combine()函数，当前类类型的对象不会是const对象，因此不用加const
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
