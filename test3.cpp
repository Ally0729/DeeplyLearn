//�����ָ��������vector��iterator����������Ӧ�þ�������ʹ�������ָ��
//���������vector���������ڣ�����Ĵ�Сһ�������ǲ��ܸĵģ���vector���Զ�̬����ӳ�Ա��һ��Ҳ��vector�����ɿն���Ȼ�󲻶����
//ֻ�е�vector���ٶȲ����������ʱ��ſ�������
//����ĳ�ʼ��
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int a[]={3,2,4};//��ʽ��ʼ������Ҫָ������Ĵ�С������C++��C������
	//���û����ʽ��ʼ����ô�����ں�������ᱻ��ʼ��Ϊ0���ں������ڲ��ᱻ��ʼ�����������Ԫ�����࣬��ô�������Ķ��������Ĭ�Ϲ��캯�����г�ʼ��
    //��������û��Ĭ�Ϲ��캯�����Ǳ��������ʽ��ʼ��
	int a[5]={0,1,2}//a[3]=a[4]=0;���������ͳ�ʼ����0��
	string str[5]={"Hello","Hi","World"};//str[3]=str[4]="" ���ַ��������Ĭ�Ϲ��캯����
	//������ַ����� ch1==ch2
	char ch1[]="Hello";
	char ch2[]={'H','e','l','l','o','\0'};
	char ch3[4]="Ally";//error ch3����5��Ԫ��
	//��vector��ͬ�����鲻������һ�������ʼ����Ҳ���ܱ���һ�����鸨��
	vector<int> ivec1;
	vector<int> ivec2(ivec1);//һ��������������һ��������ʼ��
	//int a[3]={0,0,0};
	//int b[3](a);//error һ�����鲻������һ�������ʼ��
	ivec2=ivec1;//һ���������Ա���һ��������ֵ��ivec2�е�Ԫ����ivec1�е�Ԫ�صĸ���
	//b=a; error һ�����鲻�ܱ���һ�����鸳ֵ
}*/
//����ĳ��Ⱥ������±����ȷ������size_t
//a[n];n��������size_t
/*#include <iostream>
using namespace std;
int  main(){
	int arr[10]={0,1,2};
	int *p1=nullptr;
	p1=arr;
	int (*p2)[10]=&arr;//p2��p1��ָ�� ָ������ָ���ָ��
}*/
/*#include <iostream>
using namespace std;
int main(){
	int arr[10]={0,1,2};
	int (&refa)[10]=arr;//refa��arr���������
	refa[0]=9;//refa[0]==arr[0]
}*/
