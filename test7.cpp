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
Sales_data::Sales_data(const string &s,unsigned cnt,double price):bookNo(s),units_sold(cnt),revenue(cnt*price){}

Sales_data::Sales_data(const string &s,unsigned cnt,double price){
	bookNo=s;
	units_sold=cnt;
	revenue=cnt*price;
}
//��һ�ֹ��캯����ʽ��ֱ�Ӷ��岢��ʼ��
//�ڶ��ֹ��캯����ʽ�Ǹ�ֵ����
//�����const�������ö�������ֵ����ô�ڶ��ֹ��췽ʽ���Ǵ���ģ����Խ���ʹ�õ�һ�ַ�ʽ

//���캯����ʼֵ�б�ֻ˵�����ڳ�ʼ����Ա��ֵ�������޶���ʼ���ľ���ִ��˳��
//��Ա��ʼ����ִ��˳������ж����˳����ͬ
class X{
	int i;
	int j;
public:
	X(int ii): j(ii), i(j){}
}
//��ִ��i�ĳ�ʼ������ִ��j�ĳ�ʼ��������i��ʼ��ʱj��û��ʼ���������j��ʼ��i�����
//�����캯����ʼֵ�б��˳������ж����˳��һ�£��������Ƚ�ֱ��

//Ĭ��ʵ�κ͹��캯��
class Sales_data{
public:
	Sales_data(std::string s = " "):bookNo(s){}//��ΪSales_data()���Ե������������Ҳ��Ĭ�Ϲ��캯��
	//���๹�캯����֮ǰһ��
	Sales_data(std::string s,unsigned cnt,double rev):bookNo(s),units_sold(cnt),revenue(cnt*rev){}
	Sales_data(std::istream &is){read(is,*this);}
	//�����Ա��֮ǰһ��
};
//���һ�����캯��Ϊ�����β��ṩ��Ĭ��ʵ�Σ���ô������Ĭ�Ϲ��캯��

//���캯���������ʽת��
//��Sales_data���У�����string��istream�Ĺ��캯���ֱ�����������������Sales_data��ʽת���Ĺ���
//Ҳ����˵����ҪSales_data�ĵط�������string��istream����
//string null_book="9-999-99999-9";'
//����һ��linshideSales_data����
//�ö����units_sold��revenue����0��bookNo����null_book;
//item.combine(null_book);//��null_book��ʽת����Sales_data��Ĺ�����ʵ�ʵ�����Sales_data���н���һ��string����Ĺ��캯��
//�ȼ����������
//string null_book="9-999-99999-9";
//Sales_data s(null_book);
//item.combine(s);
//ֻ����һ������ת��
//item.combine("9-999-99999-9");//error  ����ֵ������string��Sales_data����������ת��
//item.combine(string("9-999-99999-9"));//correct ����string�๹�캯��
//item.combine(Sales_data("9-999-99999-9"));//correct ����Sales_data�๹�캯��

//���ƹ��캯���������ʽת��
//�����캯��������explicit��ע��explicit���Ƶ�����ʽת����ֻ��������������ʱ��ʹ��explicit�ؼ��֣����ⶨ���ʱ���ظ�ʹ��
class Sales_data{
public:
	Sales_data();
	Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
	explicit Sales_data(const std::string &s):bookNo(s){}
	explicit Sales_data(std::istream &is);
	//������֮ǰ�汾һ��
};
//item.combine(null_book);//error
//item.combine(is);//error
//explicit���캯��ֻ��ʹ��ֱ�ӳ�ʼ��������ʹ�ø�ֵ��ʼ������Ϊ��ֵ��ʼ������ʹ�����ʽ����ת��
//Sales_data item1(null_book);//correct
//Sales_data item2=null_book;//error
//������ʽ����ת��
//item.combine(static_cast<Sales_data>(null_book));

//��ľ�̬��Ա
//static��Ա������������Ķ���û��ϵ��������ֱ�����
//static��Ա�����������ɿ�����publicҲ������private
class Account{
public:
	void calculate() {amount += amount * interestRate;}
	static double rate() {return interestRate;}
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};
//ÿ��Amount������һ��owner��amount����������Amount������interestRate����
//���ƣ���ľ�̬��Ա����Ҳ��Ӧ�ú��κζ������һ�����ǲ�����thisָ�룬����������const��Ҳ����ʹ��thisָ��
//ʹ����������ʷ�����static��Ա
//Account::rate();
//��Ȼ��̬��Ա���������ĳ�����󣬵�obj1.rate()��Ȼ�ǶԵ�
//static�ؼ���ֻ�����ں��������ĵط�ʹ�ã����⺯������ĵط����ظ�ʹ��
//��Ϊ��̬��Ա����������κ�һ�����󣬶����캯�����������Ķ���
//��˵����̬��Ա�����ɹ��캯����ʼ����
//��̬��Ա���κκ����⣨main()����ʼ��
//double Amount::interestRate=9;//λ����Ӧ.cpp����main()�����ⲿ
//��̬��Ա�����Ϳ����ǲ���ȫ���ͣ��Ǿ�̬��Ա������
class Bar{
public:
	//
private:
	static Bar mem1;//������û�ж����꣬���ǲ���ȫ����
	Bar *mem2;
	Bar mem3;//error
};
//statci ��Ա������������
//��static��Ա�����ԣ�ֻ�������ָ�������
//static��Ա������Ĭ��ʵ�Σ���static��Ա������