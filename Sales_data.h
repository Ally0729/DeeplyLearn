//确保头文件多次被包含仍能安全工作的常用技术是预处理器
//#ifndef、#define、#ifdef、#endif为头文件保护符
/*#ifndef SALES_DATA_H//SALES_DATA_H是预处理变量,与头文件名字一致
#define SALES_DATA_H
struct Sales_data{
	std::string bookNo;
	unsigned units_sold=0;
	double rebenue=0.0;
};
#endif*/
//头文件格式：
/*
#ifndef 预处理变量名
#define 预处理变量名
头文件的主体部分
#endif
*/
//定义一个类的时候，对其成员都要进行初始化（赋值初始化），这样在构造类的对象的时候如果没有初始化，就可以用定义类的时候
//其成员的初始化方式来默认初始化对象

//头文件中不应包含using声明，因为头文件要在使用头文件的文件中打开，那么那个文件也会由此using声明，可能会产生冲突