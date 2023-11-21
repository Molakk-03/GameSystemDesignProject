#include <iostream>
#include <string>
#include "Console.h"
#include "Board.h"
#include "Animal.h"

using namespace std;

// Console�� ExcitionCommand �޼��� ����

void Console::ExecuteCommand(void) {
	string param[2];

	int x[2] = { 0, };
	int y[2] = { 0, };

	Animal *pTarget = 0;

	//��ɾ� �Է�
	cin >> param[0] >> param[1];
	
	//��ɾ�� ���� ��ġ ��������
	x[0] = param[0][0] - 'A';
	y[0] = 7 - (param[0][1] - '1'); // ���� ��ġ

	x[1] = param[1][0] - 'A';
	y[1] = 7 - (param[1][1] - '1'); // �̵� ��ġ

	//�� ��������
	pTarget = board.GetAnimal(x[0], y[0]);

	//�̵� ��ġ�� ���� ���� ���
	if (board.GetAnimal(x[1], y[1])) {
		//���� ���
		if (pTarget->Attack(x[1], y[1], x[0], y[0])) {
			board.MoveTo(x[1], y[1], x[0], y[0]);
		}
	}
	else {
		//�̵� �������� �˻�
		if (pTarget->Move(x[1], y[1], x[0], y[0])) {
			//������ ��� �̵�
			board.MoveTo(x[1], y[1], x[0], y[0]);
		}
	}
	return;
}