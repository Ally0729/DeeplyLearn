#include <string>
class Screen{
public:
	typedef std::string::size_type pos;//������ͳ�Ա��������privateҲ������public������ͨ��Ա��ͬ���Ǳ����ȶ�����ʹ��
	Screen();                                                               //����string�๹�캯��
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(wd*ht,c){}
	char get() const{
		return contents[cursor];
	}//��ʽ��������
	char get(pos r,pos c) const;//��ʽ����������ֻ��Ҫ�ڶ����ʱ���inline
	Screen& move(pos r,pos c);
	Screen& set(char c);
	Screen& set(pos r,pos col,char ch);
private:
	pos cursor;
	pos width;
	pos height;
	std::string contents;
};
//���´���Ӧ������Ӧ��.cpp��
inline char Screen::get(pos r,pos c) const{//�������Ǽ�����
	pos row=r*width;
	return contents[row+c];
}
inline Screen& Screen::move(pos r,pos c){
	pos row=r*width;
	cursor=row+c;
	return *this;
}
inline Screen& Screen::set(char c){
	contents[cursor]=c;
	return *this;
}
inline Screen& Screen::set(pos r,pos col,char ch){
	contents[r*width+col]=ch;
	return *this;
}
Screen myScreen;
//������ƶ���ָ��λ�ã�Ȼ�����ø�λ�õ��ַ�ֵ
myScreen.move(4,0);
myScreen.set('#');
//��Ϊmove��set�������صĶ������ã������������ÿ�������ֵ�������ص��Ƕ�������˵ȼ����������
myScreen.move(4,0).set('#');
//����������ص���Screen��������Screen&���ͻ�������⣬myScreen.move(4,0).set('#');�ȼ�����������
temp=myScreen.move(4,0);
temp.set('#');//temp�����ˣ���myScreen��û�б�����
//�������������ã�ֻ������ֵ�����ص��Ƕ���ĸ��������
//�ٸ��������һ��display�ĺ������������ӡScreen�����ݣ���ô�ú���Ӧ����һ��������Ա�����������������ܵ��øó�Ա������
//�ú�������*this���������ͱ�����const Screen&��������佫����
//myScreen.display(cout).set('#')
//��ΪmyScreen.display(cout)���ص���һ���������󣬲��ܶԳ����������д����������myScreen�Ƿǳ�����������display�����ķ���ֵ�ǳ�������
//��Ҳ������ת���ɳ�������

//һ��const����ĳ�Ա�������޸ģ�����const�����mutable��Ա�����޸�
//mutable size_t access;