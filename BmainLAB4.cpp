/*

b) Создать класс студент, у которого есть имя, специальность, год обучения и средний
балл. Определить функции установки, изменения данных, сравнения. Для задания
текстовых полей использовать оператор new. Определить конструкторы, деструктор и
другие функции. Создать класс группа содержащий студентов (неограниченное
количество). Определить методы вставки, удаление студентов, определения среднего балла
по группе, конструкторы, деструкторы и др. необходимые функции.

*/


#include "BfuncLAB4.cpp"


int main(void) {
	
	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	
	cout << "\nКонструктор без параметров:\n";
	Student A;
	cout << "\nПечать объекта A:";
	A.printStudent();
	
	cout << "\nКонструкторы с параметрами(1,2,3,4):\n";
	Student B("Дима"), C("Дима", "CR");
	Student D("Дима", "CR", 1), E("Дима", "CR", 1, 8.2);
	
	cout << "\nПечать объекта B:";
	B.printStudent();
	cout << "\nПечать объекта C:";
	C.printStudent();
	cout << "\nПечать объекта D:";
	cout << D << endl;
	cout << "\nПечать объекта E:";
	cout << E << endl;
	
	cout << "\nКонструктор копирования F(E):\n";
	Student F(E);
	cout << "\nПечать объекта F:";
	F.printStudent();
	
	cout << "\nКонструктор присваивания A = F:\n";
	cout << "\nПечать объекта A:";
	A.printStudent();
	cout << "\nПечать объекта F:";
	F.printStudent();
	A = F;
	cout << "\nПечать объекта A:";
	A.printStudent();
	
	cout << "\nКонструктор присваивания A = A:\n";
	A = A;
	cout << "\nПечать объекта A:";
	cout << A << endl;
	
	cout << "\nСеттеры:\n";
	Student G;
	cout << "\nПечать объекта G:";
	G.printStudent();
	G.setName("Алёна");
	G.setSpec("MN");
	G.setYear(3);
	G.setAveScore(7.8);
	cout << "\nПечать объекта G:";
	G.printStudent();

	cout << "\nГеттеры:\n";
	cout << "\nИмя студента: ";
	cout << G.getName() << endl;
	cout << "Cпециальность студента: ";
	cout << G.getSpec() << endl;
	cout << "Год обучения студента: ";
	cout << G.getYear() << endl;
	cout << "Средний балл студента: ";
	cout << G.getAveScore() << endl;
	
	cout << "\nСравнения:\n";
	Student K("1", "1", 1, 1), L("2", "2", 2, 2);
	cout << "\nПечать объекта A:";
	A.printStudent();
	cout << "\nПечать объекта K:";
	K.printStudent();
	cout << "\nПечать объекта L:";
	L.printStudent();
	cout << "\nA == A:\n";
	if (A == A)
		cout << "Вы правы\n";
	else
		cout << "Вы не правы\n";
	cout << "\nA != A:\n";
	if (A != A)
		cout << "Вы правы\n";
	else
		cout << "Вы не правы\n";
	cout << "\nK > L:\n";
	if (K > L)
		cout << "Вы правы\n";
	else
		cout << "Вы не правы\n";
	cout << "\nK < L:\n";
	if (K < L)
		cout << "Вы правы\n";
	else
		cout << "Вы не правы\n";
	
	cout << "\nВвод/вывод данных студента P:\n";
	Student P;
	cin >> P;
	cout << "\nПечать объекта P:";
	cout << P << endl;

	cout << "\nРедактирование:\n";
	cout << "\nПечать объекта A:";
	A.printStudent();
	A.editData();
	cout << "\nПечать объекта A:";
	A.printStudent();
	
	cout << "\nСравнение:\n";
	Student M("3", "1", 2, 3), N("2", "1", 1, 5);
	cout << "\nПечать объекта M:";
	M.printStudent();
	cout << "\nПечать объекта N:";
	N.printStudent();
	M.compareData(N);
	
	cout << "\nСоздание группы CR:\n";
	cout << "\nДобавление студентов A, B, F, D\n";
	Group CR;
	cout << "\nПечать объекта A:";
	A.printStudent();
	cout << "\nПечать объекта B:";
	B.printStudent();
	cout << "\nПечать объекта F:";
	F.printStudent();
	cout << "\nПечать объекта D:";
	D.printStudent();
	CR.addStudent(A);
	CR.addStudent(B);
	CR.addStudent(F);
	CR.addStudent(D);
	CR.printGroup("CR");
	CR.findAveScore("CR");
	
	cout << "\nСоздание группы MN:\n";
	cout << "\nДобавление студентов G, L\n";
	Group MN;
	cout << "\nПечать объекта G:";
	G.printStudent();
	cout << "\nПечать объекта L:";
	L.printStudent();
	MN.addStudent(G);
	MN.addStudent(L);

	MN.printGroup("MN");
	
	cout << "\nУдаляем студентов из группы MN и добавляем студента P:\n";
	MN.deleteStudent();
	MN.deleteStudent();
	MN.printGroup("MN");
	MN.addStudent(P);
	MN.printGroup("MN");
	
	cout << "\nУдаляем всех студентов из группы CR:\n";
	CR.deleteAll();
	CR.printGroup("CR");

	return 0;
}
