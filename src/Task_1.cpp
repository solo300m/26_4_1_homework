// Task_1.cpp: определяет точку входа для приложения.
//

#include "Task_1.h"
#include <time.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Player player;
	Track track1("One", 1, 11, 2023, 250);
	Track track2("Two", 1, 12, 2023, 150);
	Track track3("Three", 1, 10, 2023, 350);
	Track track4("Four", 1, 8, 2023, 250);
	player.add(track1);
	player.add(track2);
	player.add(track3);
	player.add(track4);
	int state;
	while (true)
	{
		cout << "Введите команду. 1-play, 2-pause, 3-next, 4-stop, 0-exit" << endl;
		cin >> state;
		if (state == 1) {
			player.play();
		}
		else if (state == 2) {
			player.pause();
		}
		else if (state == 3) {
			player.next();
		}
		else if (state == 4) {
			player.stop();
		}
		else if (state == 0) {
			break;
		}
		else {
			cout << "Вы выбрали не правильную команду. Повторите ввод или нажмите 0 для выхода из программы." << endl;
		}
	}
	return 0;
}
