#include <string>
//ͷ�ļ��ﲻҪ��using����
struct Sales_data 
{
	//���캯����û�з������ͣ����ֺ�������ͬ��������ж�����캯������ͬ�ڳ�Ա���������ܼ�const��
	//û���κ�ʵ�Ρ���Ĭ�Ϲ��캯���������������Ĺ��캯������ôҲ��Ҫ����һ��Ĭ�Ϲ��캯����һ����˵��Ҫ�Լ�����һ��Ĭ�Ϲ��캯����
	Sales_data();
	//ֻ��bookNo��ʼ������units_sold��revenue�Բ���Ĭ�ϳ�ʼ���������ǵ�Ĭ�ϳ�ʼ����δ�����ֵ����������Ĺ��캯������
	Sales_data(const std::string& s):bookNo(s){}
	//��������֧�����ڳ�ʼ����Ӧ�ò������³�ʼ������ÿһ����Ա����ֵ
	Sales_data(const std::string& s,unsigned n,double p):bookNo(s),units_sold(n),revenue(n*p){}
	//���캯�����������ڣ���������ڿ����⣬�����Ǻ�����ǰ���������������ڵ�һ���Ǽ򵥺������������ʽ��������
	Sales_data(std::istream & cin);
	//��Ա����
	                //������Ա����
	std::string isbn() const{//һ��Ҫ˼��һ�¼Ӳ���const
		return bookNo;//return this->bookNo;
	}//����bookNo��isbn()����֮���壬���Ǳ������������ʱ��һ���ȴ�������ٴ������������Ⱥ�˳��û��ϵ
	//����isbn()��������ǰ�����͵Ķ��������const���󣬶�this����ָ��const��������Ҫ��const�ı�this�����ͣ�ʹ�����ָ�������󣬲���
	//�������ض����bookNo���������ǾͲ��ܶ�һ������������øó�Ա������
	Sales_data& combine(const Sales_data& rhs);
	double avg_price() const;
	//��Ա
	std::string bookNo;
	unsigned int units_sold;
	double revenue;//VS2010��֧�����ڳ�ʼ��
};
//�ǳ�Ա����
Sales_data& add(const Sales_data& a1,const Sales_data& a2);

std::istream& read(std::istream& cin,Sales_data& a);

std::ostream& print(std::ostream& cout,const Sales_data& a);
