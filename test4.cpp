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
