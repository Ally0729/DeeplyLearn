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