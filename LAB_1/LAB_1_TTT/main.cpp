#include "Tttgame/Tttgame.h"
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Tttgame g(3, 3);
	g.game();
	return 0;
}
