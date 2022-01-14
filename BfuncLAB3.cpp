#include "BheadLAB3.h"
 

//конструктор по умолчанию
String::String()
{
	//создаем строку по умолчанию:
	p_length = 0;					//длина			
	pointer = new char[1];			//выделяем память под завершающий нуль	
	pointer[0] = '\0';				//присваиваем завершающий ноль
}	


//конструктор c параметром char *str
String::String(const char * str)
{
	p_length = strlen(str);				//кол-во символов строки
	pointer = new char [p_length + 1];	//выделяем память под строку
	strcpy(pointer, str);				//копируем содержимое
}


//конструктор копирования
String::String(const String & other)
{
	p_length = other.p_length;			//кол-во символов строки
	pointer = new char [p_length + 1];	//выделяем память под строку
	strcpy(pointer, other.pointer);		//копируем содержимое
}

//деструктор
String::~String()
{
	delete [] pointer;
}


//присванивание объекта
String & String::operator = (const String & other)
{
	//присваивание самому себе
	if (this == &other)
		return *this;

	delete [] pointer;					//освобождаем память
	p_length = other.p_length; 			//кол-во символов строки
	pointer = new char [p_length + 1];	//выделяем память под строку
	strcpy(pointer, other.pointer);		//копируем содержимое
	
	return *this;	
}


//присванивание char *
String & String::operator = (const char * str)
{
	delete [] pointer;					//освобождаем память
	p_length = strlen(str); 			//кол-во символов строки
	pointer = new char [p_length + 1];	//выделяем память под строку
	strcpy(pointer, str);				//копируем содержимое
	
	return *this;	
}


//объект + объектом
String String::operator + (const String & other)
{
	String tmp(*this);
	
	tmp += other;
	
	return tmp;
}


//объект + char *
String String::operator + (const char * str)
{
	String tmp(str);
	
	tmp += str;
	
	return tmp;
}


//+= объект
String & String::operator += (const String & other)
{
	//длина новой строки
	p_length += other.p_length;
	
	//память для новой строки
	char *tmp = new char [p_length + 1];
	
	//копируем
	strcpy(tmp, pointer);
	
	//соединяем 
	strcat(tmp, other.pointer);
	
	//очищаем память от предыдущей строки
	delete [] pointer;
	
	//присваиваем новую строку
	pointer = tmp;
	
	//возвращаем объект
	return *this;
}


//+= char *				
String & String::operator += (const char * str)				
{
	//длина новой строки
	p_length += strlen(str);
	
	//память для новой строки
	char *tmp = new char [p_length + 1];
	
	//копируем
	strcpy(tmp, pointer);
	
	//соединяем 
	strcat(tmp, str);
	
	//очищаем память от предыдущей строки
	delete [] pointer;
	
	//присваиваем новую строку
	pointer = tmp;
	
	//возвращаем объект
	return *this;
}


//char* + объект
String operator + (const char *str, const String & other)
{
	//времен. объект
	String tmp(str);
	
	//складываем
	tmp += other;
	
	//возвращаем
	return tmp;
}
	

//символьный доступ для чтения к объекту типа const
const char & String::operator [] (int i) const
{
	return pointer[i];
}


//символьный доступ для чтения/записи к объекту типа нe-const
char & String::operator [] (int i)
{
	return pointer[i];
} 	


//больше
bool operator > (const String & str1, const String & str2)
{
	return (strcmp(str1.pointer, str2.pointer) > 0);
}


//меньше
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


//ввод
istream & operator >> (istream & ist, String & str)
{	
	//предел ввода
	char tmp[100];			
	
	//ввод пользователя 
	ist.get(tmp, 100);	
	
	//false, если ввод данных прерывается
	if (ist)
		str = tmp;
	
	while (ist && ist.get() != '\n')
		continue;
	
	return ist;		
}


//вывод
ostream & operator << (ostream & ost, const String & str)
{
	ost << str.pointer;
	return ost;
}
