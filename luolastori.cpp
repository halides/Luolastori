#include <iostream>
int luola[10][10];

int main() {
	luola[2][2] = 1;
	luola[5][8] = 1;
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<10; j++) {
			if (luola[i][j] == 0)
				std::cout << "X";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
