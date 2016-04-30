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

//һ����ĳ�Ա������ָ������ָ����Ǹ��������

//Screen::pos�����༴������
//�ȱ����Ա���������ڱ��뺯�������������׶εĴ���ʽֻ�ʺ��ڳ�Ա������ʹ�õı�����������ʹ�õ����ְ����������ͺͲ����б���ʹ�õ����ֱ���������
//�����ͳ�Աһ�㶨������Ŀ�ͷ��������ڱ�����������

//һ����˵�ڲ�������������¶�������������е����֣���ʹ�������Ѿ�ʹ�ù�
//������������������typedef��һ��������������ʹ���˸����֣���ô���ھͲ������¶��������

//��Ա������ʹ�õ����ְ������·�ʽ����
//(1)�ڳ�Ա�����ڲ�������
//(2)���������ڲ�������
//(3)�ڳ�Ա��������֮ǰ�������������ڲ�������

//���캯����̽
//Sales_data::Sales_data(const string &s,unsigned cnt,double price):bookNo(s),units_sold(cnt),revenue(cnt*price){}

//Sales_data::Sales_data(const string &s,unsigned cnt,double price){
//	bookNo=s;
//	units_sold=cnt;
//	revenue=cnt*price;
//}
//��һ�ֹ��캯����ʽ��ֱ�Ӷ��岢��ʼ��
//�ڶ��ֹ��캯����ʽ�Ǹ�ֵ����
//�����const�������ö�������ֵ����ô�ڶ��ֹ��췽ʽ���Ǵ���ģ����Խ���ʹ�õ�һ�ַ�ʽ

//���캯����ʼֵ�б�ֻ˵�����ڳ�ʼ����Ա��ֵ�������޶���ʼ���ľ���ִ��˳��
//��Ա��ʼ����ִ��˳������ж����˳����ͬ
//class X{
//	int i;
//	int j;
//public:
//	X(int ii): j(ii), i(j){}
//}
//��ִ��i�ĳ�ʼ������ִ��j�ĳ�ʼ��������i��ʼ��ʱj��û��ʼ���������j��ʼ��i�����
//�����캯����ʼֵ�б��˳������ж����˳��һ�£��������Ƚ�ֱ��

//Ĭ��ʵ�κ͹��캯��
//class Sales_data{
//public:
//	Sales_data(std::string s = " "):bookNo(s){}//��ΪSales_data()���Ե������������Ҳ��Ĭ�Ϲ��캯��
//	//���๹�캯����֮ǰһ��
//	Sales_data(std::string s,unsigned cnt,double rev):bookNo(s),units_sold(cnt),revenue(cnt*rev){}
//	Sales_data(std::istream &is){read(is,*this);}
//	//�����Ա��֮ǰһ��
//};
//���һ�����캯��Ϊ�����β��ṩ��Ĭ��ʵ�Σ���ô������Ĭ�Ϲ��캯��