//第六章
//如果在任何函数体外未初始化的内置类型将被初始化为0，在函数体内未被初始化的内置类型将不被初始化
//类类型无论在哪，初不初始化都由类自身决定，通常会被默认初始化

//局部静态变量
//函数体内的局部变量定义时加关键字static，变成局部静态变量
//函数体结束的时候也不会释放其内存空间，有点类似全局变量，函数体内的初始化语句只执行一次，第二次调用函数会跳过初始化语句
//因为局部静态变量类似于全局变量，因此它如果是内置类型，如果没被初始化也会被初始化为0

//分离式编译
//每个file编译成一个.obj文件，编译器负责把所有目标文件链接在一起形成.exe

//传引用参数
//实参是对象，形参是引用，形参是实参的另一个名字，形参和实参都指内存中同一片区域，形参改变的时候，内存里的值改变，实参也就改变了——引用形参

//使用引用避免copy
//如果要比较两个string对象str1和str2，且其长度都很长，不便于copy，可将str1和str2传入函数isShorter中
//bool isShorter(const string &s1,const string &s2){
//		return (s1.size()<s2.size());
//}
//s1就是str1的另一个名字，s2就是str2的另一个名字，比较s1和s2，就是比较str1和str2

//使用引用形参返回额外信息
//string::size_type find_char(const string &s,char c,string::size_type &occurs){
//	string::size_type ret=s.size();
//	occurs=0;
//	for(string::size_type i=0;i!=s.size();++i){
//		if(s[i]==c){
//			if(ret==s.size()){
//				ret=i;
//			}
//			++occurs;//occurs通过“引用形参”的形式被保存了下来
//		}
//	}
//	return ret;
//}
//index=find_char(s,'o',ctr);
//不仅字符c第一次出现的位置ret被返回，occurs也作为引用形参，通过ctr，被保存了下来，ctr的值就是出现的次数

//initializer_list形参
//如果函数的实参数量不确定但是都是同一类型，可以使用initializer_list类型的形参，#include <initializer_list>
//initializer_list<T> lst;//默认初始化T类型元素，初始化列表为空
//initializer_list<T> lst{a,b,c...};//只能用花括号初始化，lst里的元素个数和初始值一样多，lst的元素是初始值的副本，列表里的元素必须是const对象
//lst2=lst;/lst2(lst);//lst中的元素不会拷贝给lst2，而是lst和lst2共享元素
//lst.size();
//lst.begin();
//lst.end();

//#include <iostream>
//#include <string>//一定不要忘记了
//#include <initializer_list>
//using namespace std;
//void err_msg(initializer_list<string> ls){
//	for (auto beg=ls.begin();beg!=ls.end();beg++)
//	{
//		
//		cout<< *beg <<endl;
//	}
//}
//int main(){
//	err_msg({"Hello","World"});//必须用花括号
//	err_msg({"Hello","my","world"});
//}

//函数形参尽量使用常量引用(eg：const string &)/指向常量的指针
//如果不需要通过形参改变实参的值，那么使用常量引用/指向常量的指针更好，因为常量引用/指向常量的指针可以接受非常量的类型、常量类型、字面值常量
//而非常量引用/一般指针只能接受非常量类型

//函数返回指向数组的指针
//第一种方法：使用typedef
//typedef int arrint [10];
//arrint* func(); //arrint*就是指向数组的指针类型，这样写类型很方便！
//第二种方法：不使用typedef
//int (*func()) [10];

//函数重载
//如果同一作用域里的几个函数名字相同形参列表不同，我们称之为重载函数
//形参含有顶层const不算重载，因为在实参赋值给形参时顶层const可以忽略
//形参含有底层const可以实现函数重载，因为const对象只能赋给形参含有底层const的函数，非const对象虽然既可以赋给形参不含有底层const的函数
//也可以赋给形参含有底层const的函数，但是编译器会优先选择形参不含底层const的函数
//一般来说，是否写成重载函数要看是否更方便使用

//const_cast和函数重载
//const_cast常用于函数重载！！
//const string& shorterString(const string& s1,const string& s2){
//		return s1.size()<=s2.size()? s1:s2;
//}
//string& shortString(string& s1,string& s2){
//		const string&r=shorterString(const_cast<const string&>(s1),const_cast<const string&>(s2));
//		return const_cast<string&>(r);
//}