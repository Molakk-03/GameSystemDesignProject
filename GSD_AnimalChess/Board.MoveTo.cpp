#include "Board.h"
#include "Animal.h"
#include "Animals.h" 

// Board�� MoveTo �޼��� ����


bool Board::MoveTo(int ax, int ay, int bx, int by) {
	//�̵��� ���� ���� ������ ������ ü��/���ݷ� �� �� ü���� 0 ���ϸ� ����
	if (pBoard[ax][ay]) {
		//�� �� ����0
	}

	//�ܼ� �̵�
	pBoard[ax][ay] = pBoard[bx][ay];

	// �̵��� �Ϸ�� ��� ������ �ڸ��� 0���� 
	pBoard[bx][by] = 0;

	return true;
}