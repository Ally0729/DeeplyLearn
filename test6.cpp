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

//Ĭ��ʵ��
//string screen(int ht,int wid,char backgrnd);//һ������
//string screen(int ht=24,int wid=80,char backgrnd=' ');//����Ĭ��ʵ�ε�����
//����Ϊһ�������β��ṩĬ��ʵ�Σ�����һ��ĳ���βα�������Ĭ��ʵ�Σ����������е��βζ�������Ĭ��ֵ
//���ú���Ĭ��ʵ�εĺ�����
//screen();
//screen(66);
//screen(66,256);
//screen(66,256,'#');
//screen(,,'?');//error
//screen('?');//error
//Ĭ��ʵ�ε������������Էֲ�����Ĭ��ʵ�εĸ�ֵ
//string screen(int ht,int wid,char backgrnd=' ');
//string screen(int ht,int wid,char backgrnd='*');//error��һ��ȷ��Ĭ��ʵ�ξͲ����ٸ�
//string screen(int ht=24,int wid=80,char backgrnd);//correct ��Ϊbackgrnd�Ѿ�����Ĭ��ʵ��

//NDEBUG
//assert����Ϊ������һ����NDEBUG��Ԥ������������û�ж���NDEBUG��assert�Ż��������ʱ�ļ�飬��������ˣ�assertʲôҲ����
//#define NDEBUG
//Ĭ�����������NDEBUG
//assert(word.size()<threshold)
//���Լ������������Դ���
//if (word.size()>threshold)
//{
//	cerr<<"Error:"<<__FILE__<<":in function"<<__func__<<"at line"<<__LINE__<<endl<<"Compiled on"<<__DATE__<<"at"<<__TIME__<<endl
//		<<"Word read as"<<word<<"length too short"<<endl;
//}

//��������ʵ�����͵��β����͵�ת����Ϊ�����ȼ�
//��ȷƥ��
//1.ʵ�����ͺ��β�������ȫ��ͬ
//2.ʵ�δ��������ͻ�������ת��ָ������
//3.�Ƿ��ж���const
//ͨ��constת��ʵ�ֵ�ƥ�䡪���βκ��еײ�constʵ�β���
//��������
//��������ת��
//������ת��
//eg
//void ff(int);
//void ff(short);
//ff('a');//����ff(int)������������������ff(short)������������ת����������ȵ���ff(int);
//������������ת�������ȼ���ͬ��intת����float��intת����long�����ȼ���ͬ
//ָ������ָ��
//�����������䷵��ֵ���ͺͲ������͹�ͬ����
//����bool lengthCompare(const string &s1,const string &s2);��������bool (const string &,const string &);
//����ָ������ָ��
//typedef bool func (const string&,const string &);
//func *p=&lengthCompare;//'&'���п���
//���������ȼ�
//p(s1,s2);
//(*p)(s1,s2);
//lengthCompare(s1,s2);