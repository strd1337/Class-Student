#include "BheadLAB4.h"


//����� Student

//����������� �� ���������
Student::Student()
{
	p_name = "None";	//���
	p_spec = "None";	//�������������
	p_year = 0;			//��� ��������
	p_aveScore = 0;		//������� ����	
}


//������������ � �����������


//���
Student::Student(const String & name)
{
	p_name = name;
	p_spec = "None";	
	p_year = 0;			
	p_aveScore = 0;	
}


//���, �������������
Student::Student(const String & name, const String & spec)
{
	p_name = name;
	p_spec = spec;
	p_year = 0;			
	p_aveScore = 0;	
}


//���, ����-��, ��� ��������
Student::Student(const String & name, const String & spec, const int year)	
{
	p_name = name;
	p_spec = spec;
	p_year = year;			
	p_aveScore = 0;
}


//���, ����-��, ���, ����.����	
Student::Student(const String & name, const String & spec, const int year, const float aveScore)
{
	p_name = name;
	p_spec = spec;
	p_year = year;			
	p_aveScore = aveScore;
}


//����������� �����������
Student::Student(const Student & other)
{
	p_name = other.p_name;
	p_spec = other.p_spec;
	p_year = other.p_year;
	p_aveScore = other.p_aveScore;
}


//������������� � ��������
Student & Student::operator = (const Student & other)
{
	//������������ ������ ����
	if (this == &other)
		return *this;
	
	p_name = other.p_name;
	p_spec = other.p_spec;
	p_year = other.p_year;
	p_aveScore = other.p_aveScore;
	
	return *this;
}


//������ ���-�� � ��������
void Student::printStudent() const
{
	cout << "\n��� ��������: " << p_name << endl;
    cout << "������������� ��������: " << p_spec << endl;
    cout << "��� �������� ��������: " << p_year << endl;
    cout << "������� ���� ��������: " << p_aveScore << endl;
}


//��������� ������
void Student::editData()
{
	int editChoice; 		
	
	start:
		
	do
	{
	   	//����
	   	cout << "\n���� ��������������:\n";
	   	cout << "1.�������������� ����� ��������;\n";
		cout << "2.�������������� ������������� ��������;\n";
		cout << "3.�������������� ���� �������� ��������;\n";
		cout << "4.�������������� �������� ����� ��������.\n";
	  	cout << "5.����� �� ���� ��������������.\n";
	  	
	   	//���� ������ ������������
	  	cout << "\n������� �����: ";		
		cin >> editChoice;
			
		//���� ������������ ���� ����� �� �� ����,
		//�� �������� ��������� �� ������
	   	if ((editChoice < 1) || (editChoice > 5))
			cout << "\n������������ ����. ����������, ������� ����� �� ����.\n";
		else if (editChoice == 5)
			return;
				
	} while ((editChoice < 1) || (editChoice > 5));

	switch(editChoice)
	{		
		case 1: 
			cout << "\n��� ��������: " << p_name << endl;
			cout << "������� ����� ��� ��������: ";
			cin >> p_name;
			break;
		case 2: 
			cout << "\n������������� ��������: " << p_spec << endl;
			cout << "������� ����� ������������� ��������: ";
			cin >> p_spec;
			break;
		case 3: 
			cout << "\n��� �������� ��������: " << p_year << endl;
			cout << "������� ����� ������������� ��������: ";
			cin >> p_year;
			break;
		case 4: 
			cout << "\n������� ���� ��������: " << p_aveScore << endl;
			cout << "������� ����� ������� ���� ��������: ";
			cin >> p_aveScore;
			break;
	}
	
	goto start;
}


//��������� ������
void Student::compareData(const Student & stdnt) const
{
	if (this == &stdnt) {
		cout << "\n��� ������ ���������� ���� � �� �� ������.\n";
		return;
	}

	int type;
	
	start:
		
	do
	{
		cout << "\n�������� �������������� ��� ���������:\n";
		cout << "1.��� ��������;\n";
		cout << "2.������������� ��������;\n";
		cout << "3.��� �������� ��������;\n";
		cout << "4.������� ���� ��������.\n";
		cout << "5.����� �� ���� ���������.\n";
		
		cout << "\n������� �����: ";		
		cin >> type;
		
		if ((type < 1) || (type > 5))
			cout << "\n������������ ����. ����������, ������� ����� �� ����.\n";
		else if (type == 5)
			return;
					
	}  while ((type < 1) || (type > 5));
	
		
	switch(type)
	{
		case 1:
			if (p_name > stdnt.p_name)
				cout << "\n��� ������� �������� ������, ��� �������.\n";
			else if (p_name < stdnt.p_name)
				cout << "\n��� ������� �������� ������, ��� �������.\n";
			else 
				cout << "\n����� ��������� �����.\n";
			break;
		case 2:
			if (p_spec > stdnt.p_spec)
				cout << "\n������������� ������� �������� ������, ��� �������.\n";
			else if (p_spec < stdnt.p_spec)
				cout << "\n������������� ������� �������� ������, ��� �������.\n";
			else 
				cout << "\n������������� ��������� �����.\n";
			break;
		case 3:
			if (p_year > stdnt.p_year)
				cout << "\n��� �������� ������� �������� ������, ��� �������.\n";
			else if (p_year < stdnt.p_year)
				cout << "\n��� �������� ������� �������� ������, ��� �������.\n";
			else 
				cout << "\n���� �������� ��������� �����.\n";
			break;
		case 4:
			if (p_aveScore > stdnt.p_aveScore)
				cout << "\n������� ���� ������� �������� ������, ��� �������.\n";
			else if (p_aveScore < stdnt.p_aveScore)
				cout << "\n������� ���� ������� �������� ������, ��� �������.\n";
			else 
				cout << "\n������� ����� ��������� �����.\n";
			break;	
	}
	
	goto start;
}									


//��������� �����
void Student::setName(const String & name)
{
	p_name = name;
}

											
//��������� �������������
void Student::setSpec(const String & spec)
{
	p_spec = spec;
}
	
										 
//��������� �����
void Student::setYear(const int year)	
{
	p_year = year;
}
	
									
//��������� ����.�����	
void Student::setAveScore(const float aveScore)							  						
{
	p_aveScore = aveScore;
}


//��������� �����
String Student::getName() const
{
	return p_name;
}

											
//��������� ������������� 
String Student::getSpec() const		
{
	return p_spec;
}

							
//��������� �����
int Student::getYear() const	
{
	return p_year;	
}

									
//��������� ����.�����
float Student::getAveScore() const									
{
	return p_aveScore;	
}


//����
istream & operator >> (istream & ist, Student & sdnt)	
{
	cout << "��� ��������: ";
	ist >> sdnt.p_name;
	cout << "C������������ ��������: ";
	ist >> sdnt.p_spec;
	cout << "��� �������� ��������: ";
	ist >>	sdnt.p_year;
	cout << "������� ���� ��������: ";
	ist >> sdnt.p_aveScore;
	
	return ist; 
}


//�����
ostream & operator << (ostream & ost, const Student & sdnt)
{
	cout << "\n��� ��������: ";
	ost << sdnt.p_name;
	cout << "\nC������������ ��������: ";
	ost << sdnt.p_spec;
	cout << "\n��� �������� ��������: ";
	ost << sdnt.p_year;
	cout << "\n������� ���� ��������: ";
	ost << sdnt.p_aveScore;
	
	return ost;
}


//�����
bool operator == (const Student & stdnt1, const Student & stdnt2)		
{
	return (stdnt1.p_name == stdnt2.p_name && stdnt1.p_spec == stdnt2.p_spec && 
			stdnt1.p_year == stdnt2.p_year && stdnt1.p_aveScore == stdnt2.p_aveScore);
}


//�� ����� 
bool operator != (const Student & stdnt1, const Student &stdnt2)		
{
	return (!(stdnt1.p_name == stdnt2.p_name && stdnt1.p_spec == stdnt2.p_spec && 
			stdnt1.p_year == stdnt2.p_year && stdnt1.p_aveScore == stdnt2.p_aveScore));
}


//������
bool operator < (const Student & stdnt1, const Student & stdnt2)	
{
	return (stdnt1.p_name < stdnt2.p_name && stdnt1.p_spec < stdnt2.p_spec && 
			stdnt1.p_year < stdnt2.p_year && stdnt1.p_aveScore < stdnt2.p_aveScore);
}
	
	
//������ 
bool operator > (const Student &stdnt1, const Student &stdnt2)		
{
	return (stdnt1.p_name > stdnt2.p_name && stdnt1.p_spec > stdnt2.p_spec && 
			stdnt1.p_year > stdnt2.p_year && stdnt1.p_aveScore > stdnt2.p_aveScore);
}


//����� Group


//����������� �� ���������
Group::Group()
{
	p_count = 0;
	pointer = NULL;
}


//����������
Group::~Group()
{
	delete [] pointer;
}


//������ ������
void Group::printGroup(const char * str) const
{
    if (p_count > 0) {
    	cout << "\n������ ������ " << str << ":\n\n";
    	
        for (int i = 0; i < p_count; i++)
        {
        	cout << "������ " << i + 1 << " ��������:\n";
        	pointer[i].printStudent();
        	cout << endl;
		}
                
    } else      
        cout << "\n� ������ �� ������ ��������.\n" << endl; 
}


//���������� ��������
void Group::addStudent(const Student & stdnt)
{
	//���� � ������ ���� ��������
	if (pointer != NULL) {
		//�������� ������ ��� ������ ��������
		Student * tmp = new Student [p_count + 1];
		
		//�������� ���� ���������
		for (int i = 0; i < p_count; i++)
        	tmp[i] = pointer[i];
    
        //������� ������ 
        delete [] pointer;
        
        //����������� ������� � +1 ������
        pointer = tmp;
        
	} else 
		pointer = new Student [1];
	
	//���������� ���-��  
	pointer[p_count] = stdnt;
	
	//����. ���-�� ���������
	p_count++;
}


//�������� 
void Group::deleteStudent()
{
	if (p_count == 0) {
		cout << "\n� ������ ��� ���������. ���������� ������� ��������.\n";
		return;
	} else if (p_count == 1) {
        delete [] pointer;
        pointer = NULL;
        p_count = 0;
        return;
    }
	
	int choice;
	
	cout << "\n�������� ������:\n";
	for (int i = 0; i < p_count; i++)
		cout << i << ". " << i + 1 << " �������:" << pointer[i] << endl;
	
	do
	{
		cout << "\n������� �����: ";
		cin >> choice;
		
		if (choice < 0 || choice > p_count - 1)
			cout << "\n������������ ����. ����������, ������� ����� �� ����.\n";
			
	} while (choice < 0 || choice > p_count - 1);
	
	//�������� ������ �� 1 ������
	Student *tmp = new Student[p_count - 1];
	
	//�������� ���� ��������� �� ����������
    for (int i = 0; i < choice; i++)
        tmp[i] = pointer[i];
 	
 	//�������� ���� ��������� ����� ����������
    for (int i = choice + 1; i < p_count; i++)
        tmp[i - 1] = pointer[i];
 	
 	//������� ������
    delete[] pointer;
    
    //�������� ��� ���������� ��������
    pointer = tmp;
    
    //��������� ���-�� ���������
    p_count--;
    
    cout << "\n������� ������� ������ �� ������.\n";
}


//�������� ���� ��������� �� ������
void Group::deleteAll()
{
	delete [] pointer;
    pointer = NULL;
    p_count = 0;
    cout << "\n��� �������� ������� ������� �� ������.\n";
}


//����������� ����. �����
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
		
		cout << "\n������� ���� �� ������ " << str << " = " << score/count << endl;
	} else
		cout << "\n������. ������ �����. ���������� ����� ������� ���� �� ������.\n";
	
}
