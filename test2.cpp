/*#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(){
	string str="Hello!";
	string myName;
	cin>>myName;
	cout<<myName<<" say "<<str<<endl;
}//�����ͷ�ļ���ʹ����using��������ôÿ��������ͷ�ļ���Դ���򶼽��и�using�������������һ��Ҫ����
*/

/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	getline(cin,str);//�ӱ�׼�������������ַ�������str�������س���ֹͣ�������ո�ֹͣ�����һ��ʼ�������س���str��һ���մ�
	//getline(cin,str)��cin>>str���������ڣ�cin>>str�����ո�Ҳ��ֹͣ��getline(cin,str)�����ո񲻻�
	cout<<str<<endl;
}*/

//string���һЩ��������
//1��size()����
/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	string::size_type strlen;
	//getline(cin,str);�����س��Ż�ֹͣ����
	cin>>str;//�����ո�ͻ�ֹͣ����
	strlen=str.size();//str.size()�����ַ����ĳ���
	//str.size()����ֵ��string::size_type���ͣ�����һ���������ͣ�Ϊ����Ӧ��ͬ�Ļ���������unsigned int������ͬ����
	//�����мǣ�Ҫ���ú�������ֵ����һ����������������string::size_type���͵ģ�������int����
	//��ֵ��int���ͻ���һ�����⣬int�������ķ�Χ̫С�������ܱ���̫�����ַ��������������
	cout<<strlen<<endl;
}*/
//2��empty()����
/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	if(str.empty())//����ַ���Ϊ��str.empty()Ϊtrue
		cout<<"The string is empty"<<endl;
	else cout<<str<<endl;
	return 0;
}*/
//3���ַ���������
/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string str1="Hello";
	string str2="World!";
	string str3=str1+str2;//correct   '+' means paste
	//string str4="Hello"+"World"; error cannot add two pointers
	string str5=str1+"Lucy";//corre  '+'����������һ��string���͵ľͿ���
	cout<<str3<<endl;
}*/
//4���ַ�������������string::size_type����,����Ҳ��intҲ���ᱨ��
/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string::size_type idx;//ȡֵ��Χ0~str.size()-1
	string str;
	getline(cin,str);
	for(idx=0;idx<str.size();idx++){//str.size()����ֵ��string::size_type���ͣ����idxҲ��Ҫ��string::size_type����
		cout<<str[idx]<<endl;
	}
}*/