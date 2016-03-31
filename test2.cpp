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
}//如果在头文件中使用了using声明，那么每个包含该头文件的源程序都将有该using声明，所以这个一定要谨慎
*/

/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	getline(cin,str);//从标准输入流中输入字符串赋给str，遇到回车即停止，遇到空格不停止，如果一开始就遇到回车，str是一个空串
	//getline(cin,str)和cin>>str的区别在于，cin>>str遇到空格也会停止，getline(cin,str)遇到空格不会
	cout<<str<<endl;
}*/

//string类的一些函数操作
//1、size()函数
/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	string::size_type strlen;
	//getline(cin,str);遇到回车才会停止读入
	cin>>str;//遇到空格就会停止读入
	strlen=str.size();//str.size()返回字符串的长度
	//str.size()返回值是string::size_type类型，这是一种配套类型，为了适应不同的机器，它与unsigned int具有相同含义
	//但是切记，要将该函数返回值赋给一个变量，它必须是string::size_type类型的，不能是int类型
	//赋值给int类型还有一个问题，int类型数的范围太小，并不能保存太长的字符串，很容易溢出
	cout<<strlen<<endl;
}*/
//2、empty()函数
/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	if(str.empty())//如果字符串为空str.empty()为true
		cout<<"The string is empty"<<endl;
	else cout<<str<<endl;
	return 0;
}*/
//3、字符串的连接
/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string str1="Hello";
	string str2="World!";
	string str3=str1+str2;//correct   '+' means paste
	//string str4="Hello"+"World"; error cannot add two pointers
	string str5=str1+"Lucy";//corre  '+'两边至少有一个string类型的就可以
	cout<<str3<<endl;
}*/
//4、字符串索引号须是string::size_type类型,尽管也许int也不会报错
/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string::size_type idx;//取值范围0~str.size()-1
	string str;
	getline(cin,str);
	for(idx=0;idx<str.size();idx++){//str.size()返回值是string::size_type类型，因此idx也需要是string::size_type类型
		cout<<str[idx]<<endl;
	}
}*/

//vector元素尽管连续存储，位于“堆”，数组类型是c++内置类型，位于“栈”，堆和栈的区别？
//虽然可以对给定元素个数的vector对象预先分配内存，但是更有效的方法是先初始化一个空的vector对象，然后动态的增加元素

//vector初始化!
/*#include <iostream>
#include <string>
#include <vector>//vector不是数据类型，是一个类模板，可以生成多个数据类型，vector也是在std内的
using namespace std;
int main(){
	vector<int> ivec1;//vector<int>是数据类型，ivec1就是一个装有int型变量的容器，默认初始化含0个int元素
	vector<int> ivec2(ivec1);//ivec2是ivec1的副本
	vector<int> ivec3(10,-1);//ivec3中有10个int元素，每个元素值为-1
	vector<int> ivec4(10);//ivec4中有10个元素，每个元素值初始化为0，int值默认初始化为0
	vector<string> svec1;//vector<string>是数据类型，svec1就是一个装有string类变量的容器，默认初始化含0个元素
	vector<string> svec2(svec1);//svec2是svec1的副本
	vector<string> svec3(10,"Hi");//svec3中含有10个string，每个都是Hi
	vector<string> svec4(10);//svec4中含10个string,每个string都默认初始化为空字符串——string类的默认构造函数
}*/

//vector对象的操作！
//size() 容器内元素的个数，返回值是vector<...>::size_type
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> ivec(5,5);
	vector<int>::size_type len=ivec.size();
	cout<<len<<endl;
}*/
//向vector中添加元素！！
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	vector<string> text;//首先定义一个空的vector对象
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
//下标操作不添加新元素,用push_back()添加新元素
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
//每种标准库容器类型都定义了自己的迭代器类型，它是一种检查容器内元素并遍历元素的数据类型
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> ivec;
	vector<int>::size_type idx;
	for(idx=0;idx!=10;idx++){
		ivec.push_back(idx);
	}
	//iterBegin和iterEnd本质上都是指针
	vector<int>::iterator iterBegin=ivec.begin();//迭代器指向容器里第一个元素,ivec[0]
	vector<int>::iterator iterEnd=ivec.end();//迭代器指向容器里最后一个元素的下一个（实际不存在）
	//如果容器为空，ivec.begin()和ivec.end()返回的迭代器相同
}*/
//使用iterator来遍历每一个容器内的元素
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
//vector<...>::const_iterator 指针可以改变指向，但是指向的元素的值不可以改变，只读不能写
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
		//*citer="Hi";error citer是const类型迭代器，只能读不能写
	}
}*/
//const vector<...>::iteraror 指针不能改变指向，但是指针指向的元素的值可以改变
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	const vector<int> num(10,5);
	//const vector<int>::iterator cit1=num.begin(); error cit1有可能改变num[0]的值，而num里的元素是不允许被改变值的
	vector<int>::const_iterator cit2=num.begin();//correct
	cit2++;//correct
	//*cit2=1; error
}*/
//迭代器的算数操作
//iter+n/iter-n，n要是size_type类型的
//iter1-iter2，两个迭代器之间的距离，返回值是difference_type类型的，这是个signed类型
//vector<int>::iterator iter=ivec.begin()+ivec.size()/2;//迭代器指向中间
//                                                           ivec.size()就是vector<...>::size_type类型的，满足条件

//bitset
/*#include <iostream>
#include <string>
#include <bitset>//bitset也是一种类模板，与vector相似，但是bitset对象的区别仅仅在于长度，不在于类型
using namespace std;
int main(){
	string str="0011011011011011";
	bitset<32> bit1;//32 bits,all zero
	//用unsigned long的值来初始化bitset，该值直接转化为二进制的位模式
	bitset<32> bit2(0xFFFF);//0~15 bits are set to 1，while16~31 bits are set to 0
	bitset<16> bit3(0xFFFF);//0~15 bits are set to 1
	bitset<8> bits4(0xFFFF);//0~7 bits are set to 1,0xFFFF的高八位被丢弃
	//用string初始化bitset，string对象直接表示成位模式
	//从string对象读入二进制，从右向左读！！！这个差别要记住~~~
	bitset<32> bits1("0011");//bits[0]=1,bits[1]=1,其余位全是0
	bitset<32> bits2(str,5,4);//从str[5]开始的4位，初始化bits2，bits2[0]=1,bits2[1]=0,bits2[2]=1,bits2[3]=1,其余位均为0
	bitset<32> bits3(str,str.size()-4);//从str[str.size()-4]开始直到str结束，bits2[0]=1,bits2[1]=1,bits2[2]=0,bits2[3]=1,其余位均为0
}*/
//bitset对象上的操作
/*#include <iostream>
#include <bitset>
#include <string>
#include <cstddef>
using namespace std;
int main(){
	bitset<32> bits1("001101101");//用字符串初始化最好
	bool isAllZero=bits1.none();
	bool isNotAllZero=bits1.any();
	size_t bitCount=bits1.count();//size_t在cstddef头文件中定义
	size_t bitSize=bits1.size();
	bool isOne=bits1.test(5);//test bits1[5]是不是1
	bits1.set();//全部位置1
	bits1.reset();//全部位置0
	bits1.set(5);//bits1[5]置1
	bits1.reset(5);//bits1[5]置0
	bits1.flip();//全部反转
	bits1.flip(5);//bits[5]反转
}*/
/*#include <iostream>
#include <bitset>
using namespace std;
int main(){
	bitset<32> bits(0xffff);//bits是32位的，用0xffff初始化后0~15位为1,16~31位为0
	cout<<bits<<endl;//将bits输出，结果是00000000000000001111111111111111
	                                                                //高位                        低位
}*/