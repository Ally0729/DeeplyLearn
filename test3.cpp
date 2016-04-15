//数组和指针类似于vector和iterator，但是我们应该尽量避免使用数组和指针
//而且数组和vector的区别在于，数组的大小一旦给定是不能改的，而vector可以动态的添加成员，一般也是vector建立成空对象，然后不断添加
//只有当vector的速度不满足需求的时候才考虑数组
//数组的初始化
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int a[]={3,2,4};//显式初始化不需要指定数组的大小，这是C++和C的区别
	//如果没有显式初始化那么数组在函数体外会被初始化为0，在函数体内不会被初始化，如果数组元素是类，那么不管在哪都会用类的默认构造函数进行初始化
    //如果这个类没有默认构造函数，那必须进行显式初始化
	int a[5]={0,1,2}//a[3]=a[4]=0;（内置类型初始化成0）
	string str[5]={"Hello","Hi","World"};//str[3]=str[4]="" 空字符串（类的默认构造函数）
	//特殊的字符数组 ch1==ch2
	char ch1[]="Hello";
	char ch2[]={'H','e','l','l','o','\0'};
	char ch3[4]="Ally";//error ch3里有5个元素
	//和vector不同，数组不能用另一个数组初始化，也不能被另一个数组辅助
	vector<int> ivec1;
	vector<int> ivec2(ivec1);//一个容器可以用另一个容器初始化
	//int a[3]={0,0,0};
	//int b[3](a);//error 一个数组不能用另一个数组初始化
	ivec2=ivec1;//一个容器可以被另一个容器赋值，ivec2中的元素是ivec1中的元素的副本
	//b=a; error 一个数组不能被另一个数组赋值
}*/
//数组的长度和数组下标的正确类型是size_t
//a[n];n的类型是size_t
/*#include <iostream>
using namespace std;
int  main(){
	int arr[10]={0,1,2};
	int *p1=nullptr;
	p1=arr;
	int (*p2)[10]=&arr;//p2是p1的指针 指向数组指针的指针
}*/
/*#include <iostream>
using namespace std;
int main(){
	int arr[10]={0,1,2};
	int (&refa)[10]=arr;//refa是arr数组的引用
	refa[0]=9;//refa[0]==arr[0]
}*/
