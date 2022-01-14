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
		char *pointer;												//указатель на строку
		int p_length;												//длина строки
	public:
		//конструкторы
		String();													//конструктор по умолчанию 
		String(const char *);										//конструктор с параметром 
		String(const String &);										//конструктор копирования 
		~String();													//деструктор 
		
		//методы класса
		String operator + (const String &);							//сложение с объектом 
		String operator + (const char *);							//сложение с char * 
		String & operator = (const String &);						//присванивание с объектом 
		String & operator = (const char *);							//присванивание с char * 
		String & operator += (const String &);						//+= с объектом 
		String & operator += (const char *);						//+= с char * 
		const char & operator [] (int) const;						//[] const чтение
		char & operator [] (int); 									//[] не-const чтение/запись
		int lengthStr() { return p_length; };						//возвращает длину строки
		
		//дружественные функции
		friend String operator + (const char *, const String &);	//char* + объект
		friend bool operator == (const String &, const String &);	//равно
		friend bool operator != (const String &, const String &);	//не равно 
		friend bool operator < (const String &, const String &);	//меньше 
		friend bool operator > (const String &, const String &); 	//больше 
		friend istream & operator >> (istream &, String &); 		//ввод
		friend ostream & operator << (ostream &, const String &);	//вывод
};
