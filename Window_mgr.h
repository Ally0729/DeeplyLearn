#include <vector>
#include "Screen.h"
class Window_mgr{
public:
	Window_mgr(){//�����ž���Ĭ�Ϲ��캯��
		Screen& s=Screen(24,80,' ');
		screens.push_back(s);
	}
private:
	std::vector<Screen> screens;
};
//����ϣ��Window_mgr�࿪ʼʱ����ӵ��һ��Ĭ�ϳ�ʼ����Screen����
//std::vector<Screen> screens{Screen(24,80,' ')};
//����VS2010��֧�����ڳ�ʼ�������ѡ������Ĭ�Ϲ��캯���ｫָ��Screen����screens��
//��������һ��Window_mgr��Ķ������Ĭ�Ϲ��캯����ʼ�����ʹﵽ��Ҫ��