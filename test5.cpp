//������
//��ֵ˳��
//�ڴ����ʱ����Ϸ�ʽ��ȷ���Ķ���ֵ˳���ǲ�ȷ����
//int i=f1()*f2();
//f1��f2һ�����ڳ˷�����ǰ���ã�����f1�ȵ��û���f2�ȣ��ǲ�ȷ����
//���f1��f2���޹صĺ�������ôûʲô��ϵ���������f1��f2�ж���ͬһ����������˸Ķ�����ô�ȵ���˭�ͺ��й�ϵ�������Ĳ�ȷ����Ϊ�ͽ����϶�Ϊ����
//int i=0;
//cout<<i<<" "<<++i<<endl;
//�ȼ���i��ֵ����++i��ֵ�ǲ�ȷ���ģ�����ȼ���i����ô��������0,1������ȼ���++i����ô��������1,1�������Ĳ�ȷ����Ϊ���϶�Ϊ����
//*beg++�����÷���ȷ��
//++�������ȼ�����*
//*beg++==*(beg++)  ��beg��һ�����ı�ǰ��ָ��Ķ��󷵻���Ϊ������Ըı�ǰ��begָ��Ԫ��ȡֵ
//*beg=toupper(*beg++); ���*beg��ʹ�ã��ұ�beg++�Ǹı䣬�ȸı���ʹ�û�����ʹ���ڸı䣿��������
//���ۣ������һ�����ʽ�ڣ���һ���ı���ĳ�������ֵ����ô��������ʽ�����ط��Ͳ�Ҫ��ʹ������������Ϊ��ȷ������ʹ���ٸı仹���ȸı���ʹ��

//++i��i++
//ǰ�õ����������ִ�м�һ���һ�����󣬽��ı��Ľ����Ϊ���ʽ��ֵ
//���õ����������ִ�м�һ���һ�����󣬽��ı�ǰ�Ľ���ĸ�����Ϊ���ʽ��ֵ
//*++iter==*(++iter) ��iterָ�����һ��Ԫ��ȡֵ
//*iter++==*(iter++)��iter��һ�����ı�ǰ��ָ�Ķ��󷵻���Ϊ������Ըı�ǰ��iter��ָ��Ԫ��ȡֵ

//sizeof  ���������÷�sizeof(type); �� sizeof expr;
//Sales_data data,*p;
//sizeof(Sales_data);
//sizeof data;//��//sizeof(Sales_data);�ȼ�
//sizeof p;//ָ��p��ռ�ֽ���
//sizeof *p;//ָ��p��ָ������ռ�ֽ���
//��ʹp�Ǹ���ָ��Ҳ���ԣ���Ϊ���p��ָ������ռ���ֽ�������Ҫ������ȡp��ָ�Ķ�������p��ʹû��ָ�����Ҳ�ǿ��Ե�
//����������sizeof���õ������ð󶨵Ķ�����ռ�ֽ���

//����������bool/char/signed char/unsigned char/short/unsigned short��>int
//�з��������޷����������������㣬����з�����������С�ڵ����޷����������ͣ��з�������������ת���޷����������ͣ�����ô
//�ͽ��з�����ת���޷���������int��unsigned int��Ҫ��intת��unsigned int
//���򣬽��޷���������ת���з��������ͣ���long��unsigned int�����long��int��ռ�ֽ�����ͬ����longת��unsigned int�����long
//��ռ�ֽ�������int���ͽ�unsigned intת��long
//�κ�ָ��ǳ�����ָ�붼����ת����void*���ͣ�ָ����������ָ�붼����ת����const void*

//ǿ������ת��
//static_cast��const_cast������û�н���
//ֻҪ�����ײ�const��������ʹ��static_cast����ǿ������ת��
//int i=5;
//double j=static_cast<double>(i);
//const int *p=&i;
//���еײ�const����Ѻ���const��ת���ɲ����ײ�const�ģ�ʹ��const_cast���������������ʹ��const_cast(������ʹ��static_cast)����ǿ������ת��
//	const int *p=&i;
//int* pi=const_cast<int*>(p);

//������
//switch��䣺���ĳ��caseƥ��ɹ������һֱִ����ȥ��������ʾ�жϣ��������ǲ�������break
//switch(ch){
//		case 'a':
//		case 'e':
//		case 'i':
//		case 'o':
//     case 'u':
//			   ++cnt;
//             break;
//}

//�쳣
//throw runtime_error("can not divided by 0"); 
//"can not divided by 0"���ڳ�ʼ��runtime_error����
//����exception��bad_alloc��bad_cast������Ҫ��ʼ����ʹ��Ĭ�ϳ�ʼ����
//�����쳣���Ͷ���Ҫ���ַ�����ʼ��(����ʹ��Ĭ�ϳ�ʼ��)
//�쳣����ֻ������һ��what()��Ա�������ú���û�в��������ص���C�����ַ���������쳣������һ���ַ�����ʼֵ�����صľ��Ǹ��ַ���
//���򷵻������ɱ���������

//assert(expr);
//λ��<cassert>��,��expr������ʱ����Debug�£����ڿ���̨��ӡ������Ϣ(expr)

//try{
//		program-statements
//}catch(exception declaration){         eg:   catch (runtime_error err)        err.what()
//		handle-exception
//}catch(exception declaration){
//		handle-exception
//}catch(exception declaration){
//		handle-exception
//}