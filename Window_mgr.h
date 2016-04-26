#include <vector>
#include "Screen.h"
class Window_mgr{
public:
	Window_mgr(){//空括号就是默认构造函数
		Screen& s=Screen(24,80,' ');
		screens.push_back(s);
	}
private:
	std::vector<Screen> screens;
};
//我们希望Window_mgr类开始时总是拥有一个默认初始化的Screen，即
//std::vector<Screen> screens{Screen(24,80,' ')};
//但是VS2010不支持类内初始化，因此选择在其默认构造函数里将指定Screen放入screens中
//这样声明一个Window_mgr类的对象后，用默认构造函数初始化，就达到了要求