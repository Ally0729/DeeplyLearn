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