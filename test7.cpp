//chapter 7
//��ĳ�Ա��������һ��Ҫ�����ڣ���������������⣬һ��򵥵ĺ������ڶ��塪����ʽ�������������������еĺ������ⶨ��
//���ⶨ��ʱһ��Ҫ�ں�����ǰ������������������������֪���������Ĵ��붼�������������
//֮����ʹ��::����Ϊ�౾�����һ��������
//����combine()��������ǰ�����͵Ķ��󲻻���const������˲��ü�const
#include <iostream>
#include "Sales_data.h"
using namespace std;
//���캯��
Sales_data::Sales_data(istream& cin){//��Ĺ��캯���ͳ�Ա�������������������һ�����������⣬������ǰҪ������
	read(cin,*this);//��ʼ����������
}
//��Ա����
Sales_data& Sales_data::combine(const Sales_data& rhs){
	units_sold+=rhs.units_sold;
	revenue+=rhs.revenue;
	return *this;
}
//����avg_price()��������ǰ�����͵Ķ��������const�������Ҫ��const
double Sales_data::avg_price() const{
	if(units_sold)
		return revenue/units_sold;
	else
		return 0;
}
//�ǳ�Ա����
//��ĸ����������������Ͷ��������ⲿ������Ҫ������ͬһ��ͷ�ļ���
Sales_data& add(const Sales_data& a1,const Sales_data& a2){//ʹ�����ñ���copy����
	Sales_data temp=a1;
	temp.combine(a2);
	return temp;
}
//IO�಻����copy������β�ʹ�����ô���copy
//ʵ�κ��βζ��Ƕ��󣬾���ʵ�ζ��βε�copy��ʵ���Ƕ����β������ã������βκ�ʵ�ε�һ�ְ󶨣�����copy
std::istream& read(std::istream& cin,Sales_data& a){
	double price=0.0;
	cin>>a.bookNo>>a.units_sold>>price;
	a.revenue=price*a.units_sold;
	return cin;//�����������Ķ���
}//if(read(read(cin,data1),data2))
//print()�����������У������ĺ���Ӧ�ü��ٶԸ�ʽ�Ŀ��ƣ������û�����ѡ��
std::ostream& print(std::ostream& cout,const Sales_data& a){//��ʹ���βθı�ʵ�Σ��ͼ���const
	cout<<a.isbn()<<" "<<a.units_sold<<" "<<a.revenue<<" "
		<<a.avg_price();
	return cout;//����������Ķ���
}
