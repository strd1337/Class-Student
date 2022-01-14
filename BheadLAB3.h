#include <Windows.h>
#include <stdlib.h> 	
#include <math.h>   				
#include <conio.h>  	
#include <iomanip> 
#include <iostream>	


using namespace std;


class String
{
	private:
		char *pointer;												//��������� �� ������
		int p_length;												//����� ������
	public:
		//������������
		String();													//����������� �� ��������� 
		String(const char *);										//����������� � ���������� 
		String(const String &);										//����������� ����������� 
		~String();													//���������� 
		
		//������ ������
		String operator + (const String &);							//�������� � �������� 
		String operator + (const char *);							//�������� � char * 
		String & operator = (const String &);						//������������� � �������� 
		String & operator = (const char *);							//������������� � char * 
		String & operator += (const String &);						//+= � �������� 
		String & operator += (const char *);						//+= � char * 
		const char & operator [] (int) const;						//[] const ������
		char & operator [] (int); 									//[] ��-const ������/������
		int lengthStr() { return p_length; };						//���������� ����� ������
		
		//������������� �������
		friend String operator + (const char *, const String &);	//char* + ������
		friend bool operator == (const String &, const String &);	//�����
		friend bool operator != (const String &, const String &);	//�� ����� 
		friend bool operator < (const String &, const String &);	//������ 
		friend bool operator > (const String &, const String &); 	//������ 
		friend istream & operator >> (istream &, String &); 		//����
		friend ostream & operator << (ostream &, const String &);	//�����
};
