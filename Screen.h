#include <string>
class Screen{
public:
	typedef std::string::size_type pos;//类的类型成员，可以是private也可以是public，和普通成员不同的是必须先定义在使用
	Screen();                                                               //调用string类构造函数
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(wd*ht,c){}
	char get() const{
		return contents[cursor];
	}//隐式内联函数
	char get(pos r,pos c) const;//显式内联函数，只需要在定义的时候加inline
	Screen& move(pos r,pos c);
	Screen& set(char c);
	Screen& set(pos r,pos col,char ch);
private:
	pos cursor;
	pos width;
	pos height;
	std::string contents;
};
//以下代码应该在相应的.cpp中
inline char Screen::get(pos r,pos c) const{//不能忘记加类名
	pos row=r*width;
	return contents[row+c];
}
inline Screen& Screen::move(pos r,pos c){
	pos row=r*width;
	cursor=row+c;
	return *this;
}
inline Screen& Screen::set(char c){
	contents[cursor]=c;
	return *this;
}
inline Screen& Screen::set(pos r,pos col,char ch){
	contents[r*width+col]=ch;
	return *this;
}
Screen myScreen;
//将光标移动到指定位置，然后设置该位置的字符值
myScreen.move(4,0);
myScreen.set('#');
//因为move和set函数返回的都是引用，函数返回引用可以做左值，即返回的是对象本身，因此等价于下面这句
myScreen.move(4,0).set('#');
//但是如果返回的是Screen，而不是Screen&，就会出现问题，myScreen.move(4,0).set('#');等价于下面两句
temp=myScreen.move(4,0);
temp.set('#');//temp设置了，而myScreen并没有被设置
//函数不返回引用，只能做右值，返回的是对象的副本，因此
//再给该类添加一个display的函数，他负责打印Screen的内容，那么该函数应该是一个常量成员函数（否则常量对象不能调用该成员函数）
//该函数返回*this，返回类型必须是const Screen&，下面这句将报错
//myScreen.display(cout).set('#')
//因为myScreen.display(cout)返回的是一个常量对象，不能对常量对象进行写操作，尽管myScreen是非常量对象，由于display函数的返回值是常量对象
//它也会类型转换成常量对象

//一个const对象的成员不允许被修改，但是const对象的mutable成员允许被修改
//mutable size_t access;