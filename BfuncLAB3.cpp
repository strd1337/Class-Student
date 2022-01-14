#include "BheadLAB3.h"
 

//����������� �� ���������
String::String()
{
	//������� ������ �� ���������:
	p_length = 0;					//�����			
	pointer = new char[1];			//�������� ������ ��� ����������� ����	
	pointer[0] = '\0';				//����������� ����������� ����
}	


//����������� c ���������� char *str
String::String(const char * str)
{
	p_length = strlen(str);				//���-�� �������� ������
	pointer = new char [p_length + 1];	//�������� ������ ��� ������
	strcpy(pointer, str);				//�������� ����������
}


//����������� �����������
String::String(const String & other)
{
	p_length = other.p_length;			//���-�� �������� ������
	pointer = new char [p_length + 1];	//�������� ������ ��� ������
	strcpy(pointer, other.pointer);		//�������� ����������
}

//����������
String::~String()
{
	delete [] pointer;
}


//������������� �������
String & String::operator = (const String & other)
{
	//������������ ������ ����
	if (this == &other)
		return *this;

	delete [] pointer;					//����������� ������
	p_length = other.p_length; 			//���-�� �������� ������
	pointer = new char [p_length + 1];	//�������� ������ ��� ������
	strcpy(pointer, other.pointer);		//�������� ����������
	
	return *this;	
}


//������������� char *
String & String::operator = (const char * str)
{
	delete [] pointer;					//����������� ������
	p_length = strlen(str); 			//���-�� �������� ������
	pointer = new char [p_length + 1];	//�������� ������ ��� ������
	strcpy(pointer, str);				//�������� ����������
	
	return *this;	
}


//������ + ��������
String String::operator + (const String & other)
{
	String tmp(*this);
	
	tmp += other;
	
	return tmp;
}


//������ + char *
String String::operator + (const char * str)
{
	String tmp(str);
	
	tmp += str;
	
	return tmp;
}


//+= ������
String & String::operator += (const String & other)
{
	//����� ����� ������
	p_length += other.p_length;
	
	//������ ��� ����� ������
	char *tmp = new char [p_length + 1];
	
	//��������
	strcpy(tmp, pointer);
	
	//��������� 
	strcat(tmp, other.pointer);
	
	//������� ������ �� ���������� ������
	delete [] pointer;
	
	//����������� ����� ������
	pointer = tmp;
	
	//���������� ������
	return *this;
}


//+= char *				
String & String::operator += (const char * str)				
{
	//����� ����� ������
	p_length += strlen(str);
	
	//������ ��� ����� ������
	char *tmp = new char [p_length + 1];
	
	//��������
	strcpy(tmp, pointer);
	
	//��������� 
	strcat(tmp, str);
	
	//������� ������ �� ���������� ������
	delete [] pointer;
	
	//����������� ����� ������
	pointer = tmp;
	
	//���������� ������
	return *this;
}


//char* + ������
String operator + (const char *str, const String & other)
{
	//������. ������
	String tmp(str);
	
	//����������
	tmp += other;
	
	//����������
	return tmp;
}
	

//���������� ������ ��� ������ � ������� ���� const
const char & String::operator [] (int i) const
{
	return pointer[i];
}


//���������� ������ ��� ������/������ � ������� ���� �e-const
char & String::operator [] (int i)
{
	return pointer[i];
} 	


//������
bool operator > (const String & str1, const String & str2)
{
	return (strcmp(str1.pointer, str2.pointer) > 0);
}


//������
bool operator < (const String & str1, const String & str2)
{
	return (strcmp(str1.pointer, str2.pointer) < 0);	
}


//==
bool operator == (const String & str1, const String & str2)
{
	return (strcmp(str1.pointer, str2.pointer) == 0);
}


//!=
bool operator != (const String & str1, const String & str2)
{
	return (!(strcmp(str1.pointer, str2.pointer) == 0));
}


//����
istream & operator >> (istream & ist, String & str)
{	
	//������ �����
	char tmp[100];			
	
	//���� ������������ 
	ist.get(tmp, 100);	
	
	//false, ���� ���� ������ �����������
	if (ist)
		str = tmp;
	
	while (ist && ist.get() != '\n')
		continue;
	
	return ist;		
}


//�����
ostream & operator << (ostream & ost, const String & str)
{
	ost << str.pointer;
	return ost;
}
