#include <string>
//ͷ�ļ��ﲻҪ��using����
struct Sales_data 
{
	                //������Ա����
	std::string isbn() const{//һ��Ҫ˼��һ�¼Ӳ���const
		return bookNo;//return this->bookNo;
	}//����bookNo��isbn()����֮���壬���Ǳ������������ʱ��һ���ȴ�������ٴ������������Ⱥ�˳��û��ϵ
	//����isbn()��������ǰ�����͵Ķ��������const���󣬶�this����ָ��const��������Ҫ��const�ı�this�����ͣ�ʹ�����ָ�������󣬲���
	//�������ض����bookNo���������ǾͲ��ܶ�һ������������øó�Ա������
	Sales_data& combine(const Sales_data& rhs);
	double avg_price() const;
	std::string bookNo;
	unsigned int units_sold;
	double revenue;//VS2010��֧�����ڳ�ʼ��
};
//��ĳ�Ա��������һ��Ҫ�����ڣ���������������⣬һ��򵥵ĺ������ڶ��塪����ʽ�������������������еĺ������ⶨ��
//���ⶨ��ʱһ��Ҫ�ں�����ǰ������������������������֪���������Ĵ��붼�������������
//֮����ʹ��::����Ϊ�౾�����һ��������
//����combine()��������ǰ�����͵Ķ��󲻻���const������˲��ü�const
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
