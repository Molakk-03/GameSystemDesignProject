#pragma once

#include "Board.h"
#include "Graphics.h"
#include "Animal.h"

class Console {
private:
	Board board;
	Graphics graphics;

	//ó���� player1�� ���� ����
	unsigned int iTeam = Animal::player1;

private:
	Console(Console& program);

	void ExecuteCommand(void);

public:
	Console(void);

	int Run(void);

};

