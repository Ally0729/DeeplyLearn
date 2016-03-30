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
