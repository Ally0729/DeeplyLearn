/*#include <iostream>
using namespace std;
int main(){
	int sum=0,my_value=0;
	while (cin>>my_value)//���cin�Ĳ���int�͵����ݻ���ctrl+z���ļ��������жϿ�ݼ�������ôwhile����Ϊfalse
	{
		sum+=my_value;
	}
	cout<<sum<<endl;
}*/
//����ת��
/*bool b=42;//b=1
   int i=b;//i=1
   i=3.14;//i=3
   double pi=i;//pi=3.0
   unsigned char c=-1;//��һ����������һ���޷�������-1���ڴ�����11111111�����룩���c=255
   //���������޷�����=����+����޷�������ģ
   signed char c=256��//char��8bit��256��9bit�����c������
   unsigned u=10��
   int i=-42��
   std::cout<<i+u<<endl;//����+�޷�������Ҫ�Ƚ�����ת���޷����������������޷�����=����+����޷�������ģ
   //iת���޷�����unsiged int ,ģ��2^32�����ս����2^32-42
   unsigned u1=10;
   unsigned u2=42;
   std::cout<<u1-u2<<endl;//u1-u2�������Ӧ����unsigned���������Ҫ��-32ת��2^32-32
*/
//����ֵ������ʮ���ƣ�20���˽���024��ʮ������0x14
//ʮ����Ĭ�����з��������˽��ƺ�ʮ�����ƿ����з���Ҳ����û��
//ʮ��������ֵ������������int��long��long long�������¸�ֵ����С�����ͣ�ע��shortû������ֵ����
//�˽��ƺ�ʮ�����Ƶ�����ֵ������������int��unsigned int��long��unsigned long��long long��unsigned long long�������¸�ֵ����С������
//�б��ʼ��  
//���{}�ڵ�ֵ����ʼֵ���ж�ʧ��Ϣ�ķ��գ������������
//C++11�±�׼��һ���֣�����������ʱ��֧��
//	int units_sold={0};
//	int units_sold{0};
