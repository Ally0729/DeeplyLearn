//第四章
//求值顺序
//在大多数时候，组合方式是确定的而求值顺序是不确定的
//int i=f1()*f2();
//f1和f2一定会在乘法运算前调用，但是f1先调用还是f2先，是不确定的
//如果f1和f2是无关的函数，那么没什么关系，但是如果f1和f2中都对同一个对象进行了改动，那么先调用谁就很有关系，这样的不确定行为就将被认定为错误
//int i=0;
//cout<<i<<" "<<++i<<endl;
//先计算i的值还是++i的值是不确定的，如果先计算i，那么输出结果是0,1；如果先计算++i，那么输出结果是1,1，这样的不确定行为被认定为错误
//*beg++——用法正确！
//++运算优先级高于*
//*beg++==*(beg++)  对beg加一，将改变前的指向的对象返回作为结果，对改变前的beg指的元素取值
//*beg=toupper(*beg++); 左边*beg是使用，右边beg++是改变，先改变在使用还是先使用在改变？——错误！
//结论：如果在一个表达式内，有一处改变了某个对象的值，那么再这个表达式其他地方就不要再使用这样对象，因为不确定是先使用再改变还是先改变在使用

//++i和i++
//前置递增运算符是执行加一或减一操作后，将改变后的结果作为表达式的值
//后置递增运算符是执行加一或减一操作后，将改变前的结果的副本作为表达式的值
//*++iter==*(++iter) 对iter指向的下一个元素取值
//*iter++==*(iter++)对iter加一，将改变前所指的对象返回作为结果，对改变前的iter所指的元素取值

//sizeof  ——两种用法sizeof(type); 、 sizeof expr;
//Sales_data data,*p;
//sizeof(Sales_data);
//sizeof data;//和//sizeof(Sales_data);等价
//sizeof p;//指针p所占字节数
//sizeof *p;//指针p所指对象所占字节数
//即使p是个空指针也可以，因为获得p所指对象所占的字节数不需要真正获取p所指的对象，所有p即使没有指向对象也是可以的
//对引用类型sizeof，得到和引用绑定的对象所占字节数

//整型提升：bool/char/signed char/unsigned char/short/unsigned short—>int
//有符号数和无符号数进行算术运算，如果有符号数的类型小于等于无符号数的类型（有符号数的类型能转成无符号数的类型），那么
//就将有符号数转成无符号数，如int和unsigned int，要将int转成unsigned int
//否则，将无符号数类型转成有符号数类型，如long和unsigned int，如果long和int所占字节数相同，则将long转成unsigned int，如果long
//所占字节数大于int，就将unsigned int转成long
//任何指向非常量的指针都可以转化成void*类型，指向任意对象的指针都可以转化成const void*

//强制类型转换
//static_cast和const_cast互补，没有交集
//只要不含底层const，都可以使用static_cast进行强制类型转换
//int i=5;
//double j=static_cast<double>(i);
//const int *p=&i;
//含有底层const，想把含有const的转换成不含底层const的，使用const_cast，其他情况都不能使用const_cast(都可以使用static_cast)进行强制类型转换
//	const int *p=&i;
//int* pi=const_cast<int*>(p);

//第五章
//switch语句：如果某个case匹配成功，则会一直执行下去，除非显示中断，所以我们不能忘记break
//switch(ch){
//		case 'a':
//		case 'e':
//		case 'i':
//		case 'o':
//     case 'u':
//			   ++cnt;
//             break;
//}

//异常
//throw runtime_error("can not divided by 0"); 
//"can not divided by 0"用于初始化runtime_error对象
//除了exception、bad_alloc和bad_cast对象不需要初始化（使用默认初始化）
//其他异常类型都需要用字符串初始化(不能使用默认初始化)
//异常类型只定义了一个what()成员函数，该函数没有参数，返回的是C风格的字符串，如果异常类型有一个字符串初始值，返回的就是该字符串
//否则返回内容由编译器决定

//assert(expr);
//位于<cassert>中,当expr不满足时，在Debug下，会在控制台打印错误信息(expr)

//try{
//		program-statements
//}catch(exception declaration){         eg:   catch (runtime_error err)        err.what()
//		handle-exception
//}catch(exception declaration){
//		handle-exception
//}catch(exception declaration){
//		handle-exception
//}