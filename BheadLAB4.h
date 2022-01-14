#include "BfuncLAB3.cpp"


class Student
{
	private:
		String p_name;														//имя
		String p_spec;														//специальность
		int p_year;															//год обучения
		float p_aveScore;													//средний балл
	public:
		//конструкторы
		Student();															//конструктор по умолчанию 
		//конструкторы с параметром 										//если параметры:
		Student(const String &);											//имя студента
		Student(const String &, const String &);							//имя, специальность
		Student(const String &, const String &, const int);					//имя, спец-ть, год обучения
		Student(const String &, const String &, const int, const float);	//имя, спец-ть, год, сред.балл							
		Student(const Student &);											//конструктор копирования 
		
		//методы класса
		Student & operator = (const Student &);								//присванивание с объектом 
		void printStudent() const;											//печать инф-ии о студенте
		void editData();													//изменение данных
		void compareData(const Student &) const;							//сравнение данных
		//Сеттеры	
		void setName(const String &);										//установка имени 
		void setSpec(const String &);										//установка специальности 
		void setYear(const int);											//установка курса
		void setAveScore(const float);							  			//установка сред.балла
		//Геттеры
		String getName() const;												//получение имени
		String getSpec() const;												//получение специальности 
		int getYear() const;												//получения курса
		float getAveScore() const;											//получение сред.балла

		
		//дружественные функции
		friend istream & operator >> (istream &, Student &); 				//ввод
		friend ostream & operator << (ostream &, const Student &);			//вывод
		friend bool operator == (const Student &, const Student &);			//равно
		friend bool operator != (const Student &, const Student &);			//не равно 
		friend bool operator < (const Student &, const Student &);			//меньше 
		friend bool operator > (const Student &, const Student &); 			//больше 
};


class Group : public Student
{
	private:
		Student *pointer;													//указатель на массив студентов
		int p_count;														//кол-во студентов в группе
	public:
		//конструкторы
		Group();															//конструктор по умолчанию
		~Group();															//деструктор
		
		//методы класса
		void printGroup(const char *) const;								//печать группы	
		void addStudent(const Student &);									//добавление в группу
		void deleteStudent();												//удаление из группы
		void deleteAll();													//удаление всех
		void findAveScore(const char *) const;								//нахождение сред.балла
};
