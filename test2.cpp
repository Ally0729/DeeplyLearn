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

//vectorԪ�ؾ��������洢��λ�ڡ��ѡ�������������c++�������ͣ�λ�ڡ�ջ�����Ѻ�ջ������
//��Ȼ���ԶԸ���Ԫ�ظ�����vector����Ԥ�ȷ����ڴ棬���Ǹ���Ч�ķ������ȳ�ʼ��һ���յ�vector����Ȼ��̬������Ԫ��

//vector��ʼ��!
/*#include <iostream>
#include <string>
#include <vector>//vector�����������ͣ���һ����ģ�壬�������ɶ���������ͣ�vectorҲ����std�ڵ�
using namespace std;
int main(){
	vector<int> ivec1;//vector<int>���������ͣ�ivec1����һ��װ��int�ͱ�����������Ĭ�ϳ�ʼ����0��intԪ��
	vector<int> ivec2(ivec1);//ivec2��ivec1�ĸ���
	vector<int> ivec3(10,-1);//ivec3����10��intԪ�أ�ÿ��Ԫ��ֵΪ-1
	vector<int> ivec4(10);//ivec4����10��Ԫ�أ�ÿ��Ԫ��ֵ��ʼ��Ϊ0��intֵĬ�ϳ�ʼ��Ϊ0
	vector<string> svec1;//vector<string>���������ͣ�svec1����һ��װ��string�������������Ĭ�ϳ�ʼ����0��Ԫ��
	vector<string> svec2(svec1);//svec2��svec1�ĸ���
	vector<string> svec3(10,"Hi");//svec3�к���10��string��ÿ������Hi
	vector<string> svec4(10);//svec4�к�10��string,ÿ��string��Ĭ�ϳ�ʼ��Ϊ���ַ�������string���Ĭ�Ϲ��캯��
}*/

//vector����Ĳ�����
//size() ������Ԫ�صĸ���������ֵ��vector<...>::size_type
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> ivec(5,5);
	vector<int>::size_type len=ivec.size();
	cout<<len<<endl;
}*/
//��vector�����Ԫ�أ���
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	vector<string> text;//���ȶ���һ���յ�vector����
	string word;
	vector<string>::size_type i;	
	cin>>word;
	while(word!="END"){
		text.push_back(word);
		cin>>word;
	}
	for(i=0;i<text.size();i++){
		cout<<text[i]<<' ';
	}
	cout<<endl;
}*/
//�±�����������Ԫ��,��push_back()�����Ԫ��
//error:
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> ivec;
	vector<int>::size_type idx;
	for(idx=0;idx!=10;idx++){
		ivec[idx]=idx;
	}
}*/
//correct
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> svec;
	vector<int>::size_type idx;
	for(idx=0;idx!=10;idx++){
		svec.push_back(idx);
	}
	for(idx=0;idx!=svec.size();idx++)
		cout<<svec[idx];
	cout<<endl;
}*/

//iterator
//ÿ�ֱ�׼���������Ͷ��������Լ��ĵ��������ͣ�����һ�ּ��������Ԫ�ز�����Ԫ�ص���������
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> ivec;
	vector<int>::size_type idx;
	for(idx=0;idx!=10;idx++){
		ivec.push_back(idx);
	}
	//iterBegin��iterEnd�����϶���ָ��
	vector<int>::iterator iterBegin=ivec.begin();//������ָ���������һ��Ԫ��,ivec[0]
	vector<int>::iterator iterEnd=ivec.end();//������ָ�����������һ��Ԫ�ص���һ����ʵ�ʲ����ڣ�
	//�������Ϊ�գ�ivec.begin()��ivec.end()���صĵ�������ͬ
}*/
//ʹ��iterator������ÿһ�������ڵ�Ԫ��
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> ivec;
	vector<int>::size_type idx;
	vector<int>::iterator iter;
	for(idx=0;idx!=10;idx++){
		ivec.push_back(idx);
	}
	for(iter=ivec.begin();iter!=ivec.end();iter++){
		*iter=0;
	}
	for(iter=ivec.begin();iter!=ivec.end();iter++){
		cout<<*iter<<endl;
	}
}*/
//vector<...>::const_iterator ָ����Ըı�ָ�򣬵���ָ���Ԫ�ص�ֵ�����Ըı䣬ֻ������д
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	vector<string> svec;
	vector<string>::const_iterator citer;
	svec.push_back("Hello");
	svec.push_back("World");
	svec.push_back("Hello");
	svec.push_back("World");
	svec.push_back("Hello");
	svec.push_back("World");
	for(citer=svec.begin();citer!=svec.end();citer++){
		cout<<*citer<<endl;
		//*citer="Hi";error citer��const���͵�������ֻ�ܶ�����д
	}
}*/
//const vector<...>::iteraror ָ�벻�ܸı�ָ�򣬵���ָ��ָ���Ԫ�ص�ֵ���Ըı�
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	const vector<int> num(10,5);
	//const vector<int>::iterator cit1=num.begin(); error cit1�п��ܸı�num[0]��ֵ����num���Ԫ���ǲ������ı�ֵ��
	vector<int>::const_iterator cit2=num.begin();//correct
	cit2++;//correct
	//*cit2=1; error
}*/
//����������������
//iter+n/iter-n��nҪ��size_type���͵�
//iter1-iter2������������֮��ľ��룬����ֵ��difference_type���͵ģ����Ǹ�signed����
//vector<int>::iterator iter=ivec.begin()+ivec.size()/2;//������ָ���м�
//                                                           ivec.size()����vector<...>::size_type���͵ģ���������

//bitset
/*#include <iostream>
#include <string>
#include <bitset>//bitsetҲ��һ����ģ�壬��vector���ƣ�����bitset���������������ڳ��ȣ�����������
using namespace std;
int main(){
	string str="0011011011011011";
	bitset<32> bit1;//32 bits,all zero
	//��unsigned long��ֵ����ʼ��bitset����ֱֵ��ת��Ϊ�����Ƶ�λģʽ
	bitset<32> bit2(0xFFFF);//0~15 bits are set to 1��while16~31 bits are set to 0
	bitset<16> bit3(0xFFFF);//0~15 bits are set to 1
	bitset<8> bits4(0xFFFF);//0~7 bits are set to 1,0xFFFF�ĸ߰�λ������
	//��string��ʼ��bitset��string����ֱ�ӱ�ʾ��λģʽ
	//��string�����������ƣ����������������������Ҫ��ס~~~
	bitset<32> bits1("0011");//bits[0]=1,bits[1]=1,����λȫ��0
	bitset<32> bits2(str,5,4);//��str[5]��ʼ��4λ����ʼ��bits2��bits2[0]=1,bits2[1]=0,bits2[2]=1,bits2[3]=1,����λ��Ϊ0
	bitset<32> bits3(str,str.size()-4);//��str[str.size()-4]��ʼֱ��str������bits2[0]=1,bits2[1]=1,bits2[2]=0,bits2[3]=1,����λ��Ϊ0
}*/
//bitset�����ϵĲ���
/*#include <iostream>
#include <bitset>
#include <string>
#include <cstddef>
using namespace std;
int main(){
	bitset<32> bits1("001101101");//���ַ�����ʼ�����
	bool isAllZero=bits1.none();
	bool isNotAllZero=bits1.any();
	size_t bitCount=bits1.count();//size_t��cstddefͷ�ļ��ж���
	size_t bitSize=bits1.size();
	bool isOne=bits1.test(5);//test bits1[5]�ǲ���1
	bits1.set();//ȫ��λ��1
	bits1.reset();//ȫ��λ��0
	bits1.set(5);//bits1[5]��1
	bits1.reset(5);//bits1[5]��0
	bits1.flip();//ȫ����ת
	bits1.flip(5);//bits[5]��ת
}*/
/*#include <iostream>
#include <bitset>
using namespace std;
int main(){
	bitset<32> bits(0xffff);//bits��32λ�ģ���0xffff��ʼ����0~15λΪ1,16~31λΪ0
	cout<<bits<<endl;//��bits����������00000000000000001111111111111111
	                                                                //��λ                        ��λ
}*/