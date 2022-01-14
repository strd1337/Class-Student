#include "BfuncLAB3.cpp"


class Student
{
	private:
		String p_name;														//���
		String p_spec;														//�������������
		int p_year;															//��� ��������
		float p_aveScore;													//������� ����
	public:
		//������������
		Student();															//����������� �� ��������� 
		//������������ � ���������� 										//���� ���������:
		Student(const String &);											//��� ��������
		Student(const String &, const String &);							//���, �������������
		Student(const String &, const String &, const int);					//���, ����-��, ��� ��������
		Student(const String &, const String &, const int, const float);	//���, ����-��, ���, ����.����							
		Student(const Student &);											//����������� ����������� 
		
		//������ ������
		Student & operator = (const Student &);								//������������� � �������� 
		void printStudent() const;											//������ ���-�� � ��������
		void editData();													//��������� ������
		void compareData(const Student &) const;							//��������� ������
		//�������	
		void setName(const String &);										//��������� ����� 
		void setSpec(const String &);										//��������� ������������� 
		void setYear(const int);											//��������� �����
		void setAveScore(const float);							  			//��������� ����.�����
		//�������
		String getName() const;												//��������� �����
		String getSpec() const;												//��������� ������������� 
		int getYear() const;												//��������� �����
		float getAveScore() const;											//��������� ����.�����

		
		//������������� �������
		friend istream & operator >> (istream &, Student &); 				//����
		friend ostream & operator << (ostream &, const Student &);			//�����
		friend bool operator == (const Student &, const Student &);			//�����
		friend bool operator != (const Student &, const Student &);			//�� ����� 
		friend bool operator < (const Student &, const Student &);			//������ 
		friend bool operator > (const Student &, const Student &); 			//������ 
};


class Group : public Student
{
	private:
		Student *pointer;													//��������� �� ������ ���������
		int p_count;														//���-�� ��������� � ������
	public:
		//������������
		Group();															//����������� �� ���������
		~Group();															//����������
		
		//������ ������
		void printGroup(const char *) const;								//������ ������	
		void addStudent(const Student &);									//���������� � ������
		void deleteStudent();												//�������� �� ������
		void deleteAll();													//�������� ����
		void findAveScore(const char *) const;								//���������� ����.�����
};
