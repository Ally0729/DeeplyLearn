#include <string>
//头文件里不要用using声明
class Sales_data 
{
	//友元函数声明（不是通常意义上的函数声明，只是表明了访问权限，函数还需要进行一次真正意义上的声明，通常放在同一个头文件中（类外））
	friend Sales_data& add(const Sales_data& a1,const Sales_data& a2);
	friend std::istream& read(std::istream& cin,Sales_data& a);
	friend std::ostream& print(std::ostream& cout,const Sales_data& a);

public:
	//构造函数（没有返回类型，名字和类名相同，类可以有多个构造函数，不同于成员函数，不能加const）
	//没有任何实参——默认构造函数（定义了其他的构造函数，那么也需要定义一个默认构造函数，一般来说都要自己创建一个默认构造函数）
	Sales_data();
	//只对bookNo初始化，而units_sold和revenue仍采用默认初始化，但它们的默认初始化是未定义的值，因此这样的构造函数不好
	Sales_data(const std::string& s):bookNo(s){}
	//编译器不支持类内初始化，应该采用如下初始化，给每一个成员赋初值
	Sales_data(const std::string& s,unsigned n,double p):bookNo(s),units_sold(n),revenue(n*p){}
	//构造函数声明在类内，定义可在内可在外，在外是函数名前加类名，定义在内的一般是简单函数——变成隐式内联函数
	Sales_data(std::istream & cin);
	//成员函数
	                //常量成员函数
	std::string isbn() const{//一定要思考一下加不加const
		return bookNo;//return this->bookNo;
	}//尽管bookNo在isbn()函数之后定义，但是编译器处理类的时候一般先处理变量再处理函数，所以先后顺序没关系
	//根据isbn()函数，当前类类型的对象可以是const对象，而this不能指向const对象，所以要加const改变this的类型，使其可以指向常量对象，才能
	//正常返回对象的bookNo，否则我们就不能对一个常量对象调用该成员函数了
	Sales_data& combine(const Sales_data& rhs);

private:
	double avg_price() const;
	//成员
	std::string bookNo;
	unsigned int units_sold;
	double revenue;//VS2010不支持类内初始化
};
//非成员函数（相对于友元函数的声明，这才是真正意义上的声明）
Sales_data& add(const Sales_data& a1,const Sales_data& a2);

std::istream& read(std::istream& cin,Sales_data& a);

std::ostream& print(std::ostream& cout,const Sales_data& a);
//类的构造函数和成员函数声明在类内，定义可内（隐式内联函数），可外(.cpp)（函数名前加类名）
			//(和类联系的很紧密的)
//类的非成员（接口）函数和友元函数（真正的）声明在类外（友元函数在类内在声明一次，不是真正意义上的声明，加friend关键字），但是要在同一个头文件里，定义在类外(.cpp)（函数名前不加类名）
            //(和类有些关系的)