#include "iostream"
#include "vector"
#include "cstdlib"
#include "string"
#include "cstring"
using namespace std;
void qiaochuangE();
void qiaochuangT();
void qiaochuangV();
void qiaochuangF();
void qiaochuangN();
void qiaochuangQ();
//�����Ķ���
char qcstr[200];//�����ַ���
vector<string>qcstring;//���ս��
vector<string>::iterator it;
int n = 0;
char m = '1';//T(m)
//E-->TE'||E'=P
void qiaochuangE() {
	qiaochuangT();
	//�ж�'('+')'
	qiaochuangF();
	//+T||-T
	qiaochuangQ();
}
void qiaochuangT() {
	//�ж�'('+')'
	qiaochuangF();
	//*T||/T
	qiaochuangN();
}
void qiaochuangN() {
	string data1;//��һ������
	string data2;//�ڶ�������
	string qcZJF;//�ռ���
	string x, y = "T";
	if (qcstr[n] == '*') {
		n++;
		it = qcstring.end();
		it--;
		data1 = (*it);
		qcstring.erase(it);
		qiaochuangF();
		it = qcstring.end();
		it--;
		data2 = (*it);
		qcstring.erase(it);
		x = y + m;
		m++;
		qcZJF = x;
		qcstring.push_back(qcZJF);
		cout << qcZJF.c_str() << ":=" << data1.c_str() << "*" << data2.c_str() << "     " << "(" << "*" << "," << data1.c_str() << "," <<data2.c_str() << "," << qcZJF.c_str() << ")" << endl;
		qiaochuangN();
	}
	if (qcstr[n] == '/') {
		n++;
		it = qcstring.end();
		it--;
		data1 = (*it);
		qcstring.erase(it);
		qiaochuangF();
		it = qcstring.end();
		it--;
		data2 = (*it);
		qcstring.erase(it);
		x = y + m;
		m++;
		qcZJF = x;
		qcstring.push_back(qcZJF);
		cout << qcZJF.c_str() << ":=" << data1.c_str() << "/" << data2.c_str() << "     " << "(" << "/" << "," << data1.c_str() << "," << data2.c_str() << "," << qcZJF.c_str() << ")" << endl;
		qiaochuangN();
	}
}
void qiaochuangQ() {
	string data1;//��һ������
	string data2;//�ڶ�������
	string qcZJF;//�ռ���
	string x, y = "T";
	if (qcstr[n] == '-') {
		n++;
		qiaochuangT();
		it = qcstring.end();
		it--;
		data2 = (*it);
		qcstring.erase(it);
		it = qcstring.end();
		it--;
		data1 = (*it);
		qcstring.erase(it);
		x = y + m;
		m++;
		qcZJF = x;
		qcstring.push_back(qcZJF);
		cout << qcZJF.c_str() << ":=" << data1.c_str() << "-" << data2.c_str() << "     " << "(" << "-" << "," << data1.c_str() << "," << data2.c_str() << "," << qcZJF.c_str() << ")" << endl;
		qiaochuangQ();
	}
	else if (qcstr[n] == '+') {
		n++;
		qiaochuangT();
		it = qcstring.end();
		it--;
		data2 = (*it);
		qcstring.erase(it);
		it = qcstring.end();
		it--;
		data1 = (*it);
		qcstring.erase(it);
		x = y + m;
		m++;
		qcZJF = x;
		qcstring.push_back(qcZJF);
		cout << qcZJF.c_str() << ":=" << data1.c_str() << "+" << data2.c_str() << "     " << "(" << "+" << "," << data1.c_str() << "," << data2.c_str() << "," << qcZJF.c_str() << ")" << endl;
		qiaochuangQ();
	}
}
void qiaochuangF() {
	if (qcstr[n] == '(') {
		n++;
		qiaochuangE();
		if (qcstr[n] == ')') {
			n++;
		}
	}
	else {
		qiaochuangV();
	}

}
void qiaochuangV() {
	string qc;
	if (isalpha(qcstr[n])) {
		qc = qcstr[n];
		qcstring.push_back(qc);
		n++;
	}
}
void qiaochuang() {
	char qc[100] = "x:=(a+b)*c/d";
	int a = strlen(qc);
	for (int i = 0; i < a; i++) {
		qcstr[i] = qc[i];
	}
	string data1;//��һ������
	string data2;//�ڶ�������
	string qcZJF;
	string x, y = "T";
	//�ж��ս��
	qiaochuangV();
	if (qcstr[n] == ':') {
		n++;
		if (qcstr[n] == '=') {
			n++;
		}
	}
	qiaochuangE();
	it = qcstring.end();
	it--;
	data2=(*it);
	qcstring.erase(it--);
	data1 = (*it);
	cout << data1.c_str() << ":=" << data2.c_str() << "     " << "(" << ":=" << "," << data2.c_str() << "," << "-" << "," << data1.c_str() << ")" << endl;
}
int main()
{
	qiaochuang();
	system("pause");
	return 0;
}
