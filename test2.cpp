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
	//getline(cin,str);�����س��Ż�ֹͣ����
	cin>>str;//�����ո�ͻ�ֹͣ����
	cout<<str.size()<<endl;//str.size()�����ַ����ĳ���
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