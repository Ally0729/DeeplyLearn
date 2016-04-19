//第六章
//如果在任何函数体外未初始化的内置类型将被初始化为0，在函数体内未被初始化的内置类型将不被初始化
//类类型无论在哪，初不初始化都由类自身决定，通常会被默认初始化

//局部静态变量
//函数体内的局部变量定义时加关键字static，变成局部静态变量
//函数体结束的时候也不会释放其内存空间，有点类似全局变量，函数体内的初始化语句只执行一次，第二次调用函数会跳过初始化语句
//因为局部静态变量类似于全局变量，因此它如果是内置类型，如果没被初始化也会被初始化为0

//分离式编译
//每个file编译成一个.obj文件，编译器负责把所有目标文件链接在一起形成.exe

//传引用参数
//实参是对象，形参是引用，形参是实参的另一个名字，形参和实参都指内存中同一片区域，形参改变的时候，内存里的值改变，实参也就改变了——引用形参

//使用引用避免copy
//如果要比较两个string对象str1和str2，且其长度都很长，不便于copy，可将str1和str2传入函数isShorter中
//bool isShorter(const string &s1,const string &s2){
//		return (s1.size()<s2.size());
//}
//s1就是str1的另一个名字，s2就是str2的另一个名字，比较s1和s2，就是比较str1和str2

//使用引用形参返回额外信息
//string::size_type find_char(const string &s,char c,string::size_type &occurs){
//	string::size_type ret=s.size();
//	occurs=0;
//	for(string::size_type i=0;i!=s.size();++i){
//		if(s[i]==c){
//			if(ret==s.size()){
//				ret=i;
//			}
//			++occurs;//occurs通过“引用形参”的形式被保存了下来
//		}
//	}
//	return ret;
//}
//index=find_char(s,'o',ctr);
//不仅字符c第一次出现的位置ret被返回，occurs也作为引用形参，通过ctr，被保存了下来，ctr的值就是出现的次数