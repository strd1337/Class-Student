#include "BheadLAB4.h"


//Класс Student

//конструктор по умолчанию
Student::Student()
{
	p_name = "None";	//имя
	p_spec = "None";	//специальность
	p_year = 0;			//год обучения
	p_aveScore = 0;		//средний балл	
}


//конструкторы с параметрами


//имя
Student::Student(const String & name)
{
	p_name = name;
	p_spec = "None";	
	p_year = 0;			
	p_aveScore = 0;	
}


//имя, специальность
Student::Student(const String & name, const String & spec)
{
	p_name = name;
	p_spec = spec;
	p_year = 0;			
	p_aveScore = 0;	
}


//имя, спец-ть, год обучения
Student::Student(const String & name, const String & spec, const int year)	
{
	p_name = name;
	p_spec = spec;
	p_year = year;			
	p_aveScore = 0;
}


//имя, спец-ть, год, сред.балл	
Student::Student(const String & name, const String & spec, const int year, const float aveScore)
{
	p_name = name;
	p_spec = spec;
	p_year = year;			
	p_aveScore = aveScore;
}


//конструктор копирования
Student::Student(const Student & other)
{
	p_name = other.p_name;
	p_spec = other.p_spec;
	p_year = other.p_year;
	p_aveScore = other.p_aveScore;
}


//присванивание с объектом
Student & Student::operator = (const Student & other)
{
	//присваивание самому себе
	if (this == &other)
		return *this;
	
	p_name = other.p_name;
	p_spec = other.p_spec;
	p_year = other.p_year;
	p_aveScore = other.p_aveScore;
	
	return *this;
}


//печать инф-ии о студенте
void Student::printStudent() const
{
	cout << "\nИмя студента: " << p_name << endl;
    cout << "Специальность студента: " << p_spec << endl;
    cout << "Год обучения студента: " << p_year << endl;
    cout << "Средний балл студента: " << p_aveScore << endl;
}


//изменение данных
void Student::editData()
{
	int editChoice; 		
	
	start:
		
	do
	{
	   	//меню
	   	cout << "\nМеню редактирования:\n";
	   	cout << "1.Редактирование имени студента;\n";
		cout << "2.Редактирование специальность студента;\n";
		cout << "3.Редактирование года обучения студента;\n";
		cout << "4.Редактирование среднего балла студента.\n";
	  	cout << "5.Выйти из меню редактирования.\n";
	  	
	   	//ввод выбора пользователя
	  	cout << "\nВведите номер: ";		
		cin >> editChoice;
			
		//если пользователь ввел число не из меню,
		//то вывводим сообщение об ошибке
	   	if ((editChoice < 1) || (editChoice > 5))
			cout << "\nНеправильный ввод. Пожалуйста, введите номер из меню.\n";
		else if (editChoice == 5)
			return;
				
	} while ((editChoice < 1) || (editChoice > 5));

	switch(editChoice)
	{		
		case 1: 
			cout << "\nИмя студента: " << p_name << endl;
			cout << "Введите новое имя студента: ";
			cin >> p_name;
			break;
		case 2: 
			cout << "\nСпециальность студента: " << p_spec << endl;
			cout << "Введите новую специальность студента: ";
			cin >> p_spec;
			break;
		case 3: 
			cout << "\nГод обучения студента: " << p_year << endl;
			cout << "Введите новую специальность студента: ";
			cin >> p_year;
			break;
		case 4: 
			cout << "\nСредний балл студента: " << p_aveScore << endl;
			cout << "Введите новый средний балл студента: ";
			cin >> p_aveScore;
			break;
	}
	
	goto start;
}


//сравнение данных
void Student::compareData(const Student & stdnt) const
{
	if (this == &stdnt) {
		cout << "\nНет смысла сравнивать одни и те же данные.\n";
		return;
	}

	int type;
	
	start:
		
	do
	{
		cout << "\nВыберите характеристику для сравнения:\n";
		cout << "1.Имя студента;\n";
		cout << "2.Специальность студента;\n";
		cout << "3.Год обучения студента;\n";
		cout << "4.Средний балл студента.\n";
		cout << "5.Выйти из меню сравнения.\n";
		
		cout << "\nВведите номер: ";		
		cin >> type;
		
		if ((type < 1) || (type > 5))
			cout << "\nНеправильный ввод. Пожалуйста, введите номер из меню.\n";
		else if (type == 5)
			return;
					
	}  while ((type < 1) || (type > 5));
	
		
	switch(type)
	{
		case 1:
			if (p_name > stdnt.p_name)
				cout << "\nИмя первого студента больше, чем второго.\n";
			else if (p_name < stdnt.p_name)
				cout << "\nИмя второго студента больше, чем первого.\n";
			else 
				cout << "\nИмена студентов равны.\n";
			break;
		case 2:
			if (p_spec > stdnt.p_spec)
				cout << "\nСпециальность первого студента больше, чем второго.\n";
			else if (p_spec < stdnt.p_spec)
				cout << "\nСпециальность второго студента больше, чем первого.\n";
			else 
				cout << "\nСпециальности студентов равны.\n";
			break;
		case 3:
			if (p_year > stdnt.p_year)
				cout << "\nГод обучения первого студента больше, чем второго.\n";
			else if (p_year < stdnt.p_year)
				cout << "\nГод обучения второго студента больше, чем первого.\n";
			else 
				cout << "\nГоды обучения студентов равны.\n";
			break;
		case 4:
			if (p_aveScore > stdnt.p_aveScore)
				cout << "\nСредний балл первого студента больше, чем второго.\n";
			else if (p_aveScore < stdnt.p_aveScore)
				cout << "\nСредний балл второго студента больше, чем первого.\n";
			else 
				cout << "\nСредние баллы студентов равны.\n";
			break;	
	}
	
	goto start;
}									


//установка имени
void Student::setName(const String & name)
{
	p_name = name;
}

											
//установка специальности
void Student::setSpec(const String & spec)
{
	p_spec = spec;
}
	
										 
//установка курса
void Student::setYear(const int year)	
{
	p_year = year;
}
	
									
//установка сред.балла	
void Student::setAveScore(const float aveScore)							  						
{
	p_aveScore = aveScore;
}


//получение имени
String Student::getName() const
{
	return p_name;
}

											
//получение специальности 
String Student::getSpec() const		
{
	return p_spec;
}

							
//получения курса
int Student::getYear() const	
{
	return p_year;	
}

									
//получение сред.балла
float Student::getAveScore() const									
{
	return p_aveScore;	
}


//ввод
istream & operator >> (istream & ist, Student & sdnt)	
{
	cout << "Имя студента: ";
	ist >> sdnt.p_name;
	cout << "Cпециальность студента: ";
	ist >> sdnt.p_spec;
	cout << "Год обучения студента: ";
	ist >>	sdnt.p_year;
	cout << "Средний балл студента: ";
	ist >> sdnt.p_aveScore;
	
	return ist; 
}


//вывод
ostream & operator << (ostream & ost, const Student & sdnt)
{
	cout << "\nИмя студента: ";
	ost << sdnt.p_name;
	cout << "\nCпециальность студента: ";
	ost << sdnt.p_spec;
	cout << "\nГод обучения студента: ";
	ost << sdnt.p_year;
	cout << "\nСредний балл студента: ";
	ost << sdnt.p_aveScore;
	
	return ost;
}


//равно
bool operator == (const Student & stdnt1, const Student & stdnt2)		
{
	return (stdnt1.p_name == stdnt2.p_name && stdnt1.p_spec == stdnt2.p_spec && 
			stdnt1.p_year == stdnt2.p_year && stdnt1.p_aveScore == stdnt2.p_aveScore);
}


//не равно 
bool operator != (const Student & stdnt1, const Student &stdnt2)		
{
	return (!(stdnt1.p_name == stdnt2.p_name && stdnt1.p_spec == stdnt2.p_spec && 
			stdnt1.p_year == stdnt2.p_year && stdnt1.p_aveScore == stdnt2.p_aveScore));
}


//меньше
bool operator < (const Student & stdnt1, const Student & stdnt2)	
{
	return (stdnt1.p_name < stdnt2.p_name && stdnt1.p_spec < stdnt2.p_spec && 
			stdnt1.p_year < stdnt2.p_year && stdnt1.p_aveScore < stdnt2.p_aveScore);
}
	
	
//больше 
bool operator > (const Student &stdnt1, const Student &stdnt2)		
{
	return (stdnt1.p_name > stdnt2.p_name && stdnt1.p_spec > stdnt2.p_spec && 
			stdnt1.p_year > stdnt2.p_year && stdnt1.p_aveScore > stdnt2.p_aveScore);
}


//Класс Group


//конструктор по умолчанию
Group::Group()
{
	p_count = 0;
	pointer = NULL;
}


//деструктор
Group::~Group()
{
	delete [] pointer;
}


//печать группы
void Group::printGroup(const char * str) const
{
    if (p_count > 0) {
    	cout << "\nПечать группы " << str << ":\n\n";
    	
        for (int i = 0; i < p_count; i++)
        {
        	cout << "Данные " << i + 1 << " студента:\n";
        	pointer[i].printStudent();
        	cout << endl;
		}
                
    } else      
        cout << "\nВ группе ни одного студента.\n" << endl; 
}


//добавление студента
void Group::addStudent(const Student & stdnt)
{
	//если в группе есть студенты
	if (pointer != NULL) {
		//выделяем память для нового студента
		Student * tmp = new Student [p_count + 1];
		
		//копируем всех студентов
		for (int i = 0; i < p_count; i++)
        	tmp[i] = pointer[i];
    
        //очищаем память 
        delete [] pointer;
        
        //присваиваем обратно с +1 местом
        pointer = tmp;
        
	} else 
		pointer = new Student [1];
	
	//добавление инф-ию  
	pointer[p_count] = stdnt;
	
	//увел. кол-во студентов
	p_count++;
}


//удаление 
void Group::deleteStudent()
{
	if (p_count == 0) {
		cout << "\nВ группе нет студентов. Невозможно удалить студента.\n";
		return;
	} else if (p_count == 1) {
        delete [] pointer;
        pointer = NULL;
        p_count = 0;
        return;
    }
	
	int choice;
	
	cout << "\nСтуденты группы:\n";
	for (int i = 0; i < p_count; i++)
		cout << i << ". " << i + 1 << " студент:" << pointer[i] << endl;
	
	do
	{
		cout << "\nВведите номер: ";
		cin >> choice;
		
		if (choice < 0 || choice > p_count - 1)
			cout << "\nНеправильный ввод. Пожалуйста, введите номер из меню.\n";
			
	} while (choice < 0 || choice > p_count - 1);
	
	//выделяем память на 1 меньше
	Student *tmp = new Student[p_count - 1];
	
	//копируем всех студентов до выбранного
    for (int i = 0; i < choice; i++)
        tmp[i] = pointer[i];
 	
 	//копируем всех студентов после выбранного
    for (int i = choice + 1; i < p_count; i++)
        tmp[i - 1] = pointer[i];
 	
 	//удаляем старое
    delete[] pointer;
    
    //копируем без выбранного элемента
    pointer = tmp;
    
    //уменьшаем кол-во студентов
    p_count--;
    
    cout << "\nСтудент успешно удален из группы.\n";
}


//удаление всех студентов из группы
void Group::deleteAll()
{
	delete [] pointer;
    pointer = NULL;
    p_count = 0;
    cout << "\nВсе студенты успешно удалены из группы.\n";
}


//определение сред. балла
void Group::findAveScore(const char * str) const
{
	if (p_count != 0) {
		float score = 0;
		int count = 0;
	
		for (int i = 0; i < p_count; i++)
		{
			score += pointer[i].getAveScore();
			count++;
		}
		
		cout << "\nСредний балл по группе " << str << " = " << score/count << endl;
	} else
		cout << "\nОшибка. Группа пуста. Невозможно найти средний балл по группе.\n";
	
}
