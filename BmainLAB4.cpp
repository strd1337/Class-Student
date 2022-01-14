/*

b) ������� ����� �������, � �������� ���� ���, �������������, ��� �������� � �������
����. ���������� ������� ���������, ��������� ������, ���������. ��� �������
��������� ����� ������������ �������� new. ���������� ������������, ���������� �
������ �������. ������� ����� ������ ���������� ��������� (��������������
����������). ���������� ������ �������, �������� ���������, ����������� �������� �����
�� ������, ������������, ����������� � ��. ����������� �������.

*/


#include "BfuncLAB4.cpp"


int main(void) {
	
	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	
	cout << "\n����������� ��� ����������:\n";
	Student A;
	cout << "\n������ ������� A:";
	A.printStudent();
	
	cout << "\n������������ � �����������(1,2,3,4):\n";
	Student B("����"), C("����", "CR");
	Student D("����", "CR", 1), E("����", "CR", 1, 8.2);
	
	cout << "\n������ ������� B:";
	B.printStudent();
	cout << "\n������ ������� C:";
	C.printStudent();
	cout << "\n������ ������� D:";
	cout << D << endl;
	cout << "\n������ ������� E:";
	cout << E << endl;
	
	cout << "\n����������� ����������� F(E):\n";
	Student F(E);
	cout << "\n������ ������� F:";
	F.printStudent();
	
	cout << "\n����������� ������������ A = F:\n";
	cout << "\n������ ������� A:";
	A.printStudent();
	cout << "\n������ ������� F:";
	F.printStudent();
	A = F;
	cout << "\n������ ������� A:";
	A.printStudent();
	
	cout << "\n����������� ������������ A = A:\n";
	A = A;
	cout << "\n������ ������� A:";
	cout << A << endl;
	
	cout << "\n�������:\n";
	Student G;
	cout << "\n������ ������� G:";
	G.printStudent();
	G.setName("����");
	G.setSpec("MN");
	G.setYear(3);
	G.setAveScore(7.8);
	cout << "\n������ ������� G:";
	G.printStudent();

	cout << "\n�������:\n";
	cout << "\n��� ��������: ";
	cout << G.getName() << endl;
	cout << "C������������ ��������: ";
	cout << G.getSpec() << endl;
	cout << "��� �������� ��������: ";
	cout << G.getYear() << endl;
	cout << "������� ���� ��������: ";
	cout << G.getAveScore() << endl;
	
	cout << "\n���������:\n";
	Student K("1", "1", 1, 1), L("2", "2", 2, 2);
	cout << "\n������ ������� A:";
	A.printStudent();
	cout << "\n������ ������� K:";
	K.printStudent();
	cout << "\n������ ������� L:";
	L.printStudent();
	cout << "\nA == A:\n";
	if (A == A)
		cout << "�� �����\n";
	else
		cout << "�� �� �����\n";
	cout << "\nA != A:\n";
	if (A != A)
		cout << "�� �����\n";
	else
		cout << "�� �� �����\n";
	cout << "\nK > L:\n";
	if (K > L)
		cout << "�� �����\n";
	else
		cout << "�� �� �����\n";
	cout << "\nK < L:\n";
	if (K < L)
		cout << "�� �����\n";
	else
		cout << "�� �� �����\n";
	
	cout << "\n����/����� ������ �������� P:\n";
	Student P;
	cin >> P;
	cout << "\n������ ������� P:";
	cout << P << endl;

	cout << "\n��������������:\n";
	cout << "\n������ ������� A:";
	A.printStudent();
	A.editData();
	cout << "\n������ ������� A:";
	A.printStudent();
	
	cout << "\n���������:\n";
	Student M("3", "1", 2, 3), N("2", "1", 1, 5);
	cout << "\n������ ������� M:";
	M.printStudent();
	cout << "\n������ ������� N:";
	N.printStudent();
	M.compareData(N);
	
	cout << "\n�������� ������ CR:\n";
	cout << "\n���������� ��������� A, B, F, D\n";
	Group CR;
	cout << "\n������ ������� A:";
	A.printStudent();
	cout << "\n������ ������� B:";
	B.printStudent();
	cout << "\n������ ������� F:";
	F.printStudent();
	cout << "\n������ ������� D:";
	D.printStudent();
	CR.addStudent(A);
	CR.addStudent(B);
	CR.addStudent(F);
	CR.addStudent(D);
	CR.printGroup("CR");
	CR.findAveScore("CR");
	
	cout << "\n�������� ������ MN:\n";
	cout << "\n���������� ��������� G, L\n";
	Group MN;
	cout << "\n������ ������� G:";
	G.printStudent();
	cout << "\n������ ������� L:";
	L.printStudent();
	MN.addStudent(G);
	MN.addStudent(L);

	MN.printGroup("MN");
	
	cout << "\n������� ��������� �� ������ MN � ��������� �������� P:\n";
	MN.deleteStudent();
	MN.deleteStudent();
	MN.printGroup("MN");
	MN.addStudent(P);
	MN.printGroup("MN");
	
	cout << "\n������� ���� ��������� �� ������ CR:\n";
	CR.deleteAll();
	CR.printGroup("CR");

	return 0;
}
