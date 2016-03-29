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
	//getline(cin,str);遇到回车才会停止读入
	cin>>str;//遇到空格就会停止读入
	cout<<str.size()<<endl;//str.size()返回字符串的长度
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