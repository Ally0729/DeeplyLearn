//������
//������κκ�������δ��ʼ�����������ͽ�����ʼ��Ϊ0���ں�������δ����ʼ�����������ͽ�������ʼ��
//�������������ģ�������ʼ�����������������ͨ���ᱻĬ�ϳ�ʼ��

//�ֲ���̬����
//�������ڵľֲ���������ʱ�ӹؼ���static����ɾֲ���̬����
//�����������ʱ��Ҳ�����ͷ����ڴ�ռ䣬�е�����ȫ�ֱ������������ڵĳ�ʼ�����ִֻ��һ�Σ��ڶ��ε��ú�����������ʼ�����
//��Ϊ�ֲ���̬����������ȫ�ֱ����������������������ͣ����û����ʼ��Ҳ�ᱻ��ʼ��Ϊ0

//����ʽ����
//ÿ��file�����һ��.obj�ļ������������������Ŀ���ļ�������һ���γ�.exe

//�����ò���
//ʵ���Ƕ����β������ã��β���ʵ�ε���һ�����֣��βκ�ʵ�ζ�ָ�ڴ���ͬһƬ�����βθı��ʱ���ڴ����ֵ�ı䣬ʵ��Ҳ�͸ı��ˡ��������β�

//ʹ�����ñ���copy
//���Ҫ�Ƚ�����string����str1��str2�����䳤�ȶ��ܳ���������copy���ɽ�str1��str2���뺯��isShorter��
//bool isShorter(const string &s1,const string &s2){
//		return (s1.size()<s2.size());
//}
//s1����str1����һ�����֣�s2����str2����һ�����֣��Ƚ�s1��s2�����ǱȽ�str1��str2

//ʹ�������βη��ض�����Ϣ
//string::size_type find_char(const string &s,char c,string::size_type &occurs){
//	string::size_type ret=s.size();
//	occurs=0;
//	for(string::size_type i=0;i!=s.size();++i){
//		if(s[i]==c){
//			if(ret==s.size()){
//				ret=i;
//			}
//			++occurs;//occursͨ���������βΡ�����ʽ������������
//		}
//	}
//	return ret;
//}
//index=find_char(s,'o',ctr);
//�����ַ�c��һ�γ��ֵ�λ��ret�����أ�occursҲ��Ϊ�����βΣ�ͨ��ctr����������������ctr��ֵ���ǳ��ֵĴ���

//initializer_list�β�
//���������ʵ��������ȷ�����Ƕ���ͬһ���ͣ�����ʹ��initializer_list���͵��βΣ�#include <initializer_list>
//initializer_list<T> lst;//Ĭ�ϳ�ʼ��T����Ԫ�أ���ʼ���б�Ϊ��
//initializer_list<T> lst{a,b,c...};//ֻ���û����ų�ʼ����lst���Ԫ�ظ����ͳ�ʼֵһ���࣬lst��Ԫ���ǳ�ʼֵ�ĸ������б����Ԫ�ر�����const����
//lst2=lst;/lst2(lst);//lst�е�Ԫ�ز��´����lst2������lst��lst2����Ԫ��
//lst.size();
//lst.begin();
//lst.end();

//#include <iostream>
//#include <string>//һ����Ҫ������
//#include <initializer_list>
//using namespace std;
//void err_msg(initializer_list<string> ls){
//	for (auto beg=ls.begin();beg!=ls.end();beg++)
//	{
//		
//		cout<< *beg <<endl;
//	}
//}
//int main(){
//	err_msg({"Hello","World"});//�����û�����
//	err_msg({"Hello","my","world"});
//}

//�����βξ���ʹ�ó�������(eg��const string &)/ָ������ָ��
//�������Ҫͨ���βθı�ʵ�ε�ֵ����ôʹ�ó�������/ָ������ָ����ã���Ϊ��������/ָ������ָ����Խ��ܷǳ��������͡��������͡�����ֵ����
//���ǳ�������/һ��ָ��ֻ�ܽ��ܷǳ�������

//��������ָ�������ָ��
//��һ�ַ�����ʹ��typedef
//typedef int arrint [10];
//arrint* func(); //arrint*����ָ�������ָ�����ͣ�����д���ͺܷ��㣡
//�ڶ��ַ�������ʹ��typedef
//int (*func()) [10];

//��������
//���ͬһ��������ļ�������������ͬ�β��б�ͬ�����ǳ�֮Ϊ���غ���
//�βκ��ж���const�������أ���Ϊ��ʵ�θ�ֵ���β�ʱ����const���Ժ���
//�βκ��еײ�const����ʵ�ֺ������أ���Ϊconst����ֻ�ܸ����βκ��еײ�const�ĺ�������const������Ȼ�ȿ��Ը����ββ����еײ�const�ĺ���
//Ҳ���Ը����βκ��еײ�const�ĺ��������Ǳ�����������ѡ���ββ����ײ�const�ĺ���
//һ����˵���Ƿ�д�����غ���Ҫ���Ƿ������ʹ��

//const_cast�ͺ�������
//const_cast�����ں������أ���
//const string& shorterString(const string& s1,const string& s2){
//		return s1.size()<=s2.size()? s1:s2;
//}
//string& shortString(string& s1,string& s2){
//		const string&r=shorterString(const_cast<const string&>(s1),const_cast<const string&>(s2));
//		return const_cast<string&>(r);
//}