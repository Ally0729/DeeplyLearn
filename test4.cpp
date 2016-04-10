/*#include <iostream>
using namespace std;
int main(){
	int sum=0,my_value=0;
	while (cin>>my_value)//如果cin的不是int型的数据或者ctrl+z（文件结束的中断快捷键），那么while条件为false
	{
		sum+=my_value;
	}
	cout<<sum<<endl;
}*/
//类型转换
/*bool b=42;//b=1
   int i=b;//i=1
   i=3.14;//i=3
   double pi=i;//pi=3.0
   unsigned char c=-1;//把一个负数赋给一个无符号数，-1在内存里是11111111（补码）因此c=255
   //负数赋给无符号数=负数+这个无符号数的模
   signed char c=256；//char是8bit，256有9bit，因此c无意义
   unsigned u=10；
   int i=-42；
   std::cout<<i+u<<endl;//负数+无符号数，要先将负数转成无符号数，负数赋给无符号数=负数+这个无符号数的模
   //i转成无符号数unsiged int ,模是2^32，最终结果是2^32-42
   unsigned u1=10;
   unsigned u2=42;
   std::cout<<u1-u2<<endl;//u1-u2结果依旧应该是unsigned型因此最终要把-32转成2^32-32
*/
//字面值常量，十进制：20，八进制024，十六进制0x14
//十进制默认是有符号数，八进制和十六进制可以有符号也可以没有
//十进制字面值常量的类型是int、long、long long中能容下该值的最小的类型，注意short没有字面值常量
//八进制和十六进制的字面值常量的类型是int、unsigned int、long、unsigned long、long long、unsigned long long中能容下该值的最小的类型
//列表初始化  
//如果{}内的值（初始值）有丢失信息的风险，则编译器报错
//C++11新标准的一部分，但编译器暂时不支持
//	int units_sold={0};
//	int units_sold{0};
//在一个文件中声明定义的变量如果其他文件也要引用，那么就将该变量作为全局变量，其声明写进头文件，其他文件只要包含这个头文件即可
//const对象如果也要被其他文件引用，除了声明成全局变量外，必须用extern指明，如果const对象是用常量表达式初始化的
//可以将其声明写入头文件，其他文件只要包含这个头文件即可，否则必须要在其他文件中写其声明

//复合类型——引用
//引用是对象的另外一个名字，声明引用后必须初始化，因为引用一旦和对象绑定，不允许再被和其他对象绑定，不允许给引用赋值
//引用本身不是一个对象，所以不能被引用而引用
//引用要和绑定的对象的类型严格匹配，并且只能和对象绑定，不能和字面值常量绑定
//两个例外，其一const引用可以和字面值常量绑定

//复合类型——指针
//引用不是一个对象，内存不会为它分配地址，因此没有指向引用的指针
//指针要和指向的对象的类型严格匹配
//两个例外，其一指向常量的指针可以指向非常量对象
//只不过不允许通过指针改变对象的值，可以通过其他方法改变
//int *p=nullptr 空指针初始化
//指向指针的引用！
//int *p=nullptr;
//int *&r=p;

//区分const double *p和double const *p
//      const修饰double   const修饰*

//const
//const int ci=30;
//int j=ci;   correct  把const对象赋值给非const对象，并不改变const对象的值，因此合法！

//顶层const和底层const
//在拷贝时，顶层const忽略，底层const限制，含有底层const的是常量，不含底层const的是非常量，非常量可以赋给常量，反之不可以

//typedef
//typedef int age;
//int i=0;等价于age i=0;
//typedef char* pchar;  pchar是char型指针
//char* p=nullptr;等价于pchar p=nullptr;
//BUT~!!!
//const char* p='A';不等价于const pchar p='A';
//const修饰char                  const修饰pchar，即修饰指针