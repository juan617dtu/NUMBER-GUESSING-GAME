#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include <string>
#include "utilities.h"

int main() {

		bool restart_game = true;
		int cpu_score{}, user_score{};
		std::string username;

		do {

			bool flag = false, flag2 = false, flag3 = false;
			std::string difficulty{}; std::vector<int> int_difficulty{}; int a{};
			std::string limit{}; std::vector<char> char_limit{}; char b{}; int int_limit{};
			std::string confirmation{};
			int attempts{}, var_rand_int{}, i{};
			char play_again{};
			std::string guess{}; std::vector<int> int_guess{}; int c{};

			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				<< " _______________________________________________________________" << std::endl
				<< "|\t\t\t\t\t\t\t\t|" << std::endl
				<< "|\t\t\tNUMBER GUESSING GAME\t\t\t|" << std::endl
				<< "|_______________________________________________________________|\n\n" << std::endl;

			std::cout << "ENTER YOUR USERNAME: ";
			getline(std::cin >> std::ws, username);
			t_trim(username);

			do {
				std::cout << "\nSELECT DIFFICULTY:\n\n-EASY(1)\n-MEDIUM(2)\n-HARD(3)\n-EXIT(4)\n" << std::endl;
				getline(std::cin, difficulty, '\n');
				std::stringstream sstream(difficulty);
				sstream >> a;
				int_difficulty.push_back(a);
				if (int_difficulty[0] < 1 || int_difficulty[0] > 4) {
					std::cout << "\n\nINVALID INPUT.\n" << std::endl;
					int_difficulty.clear();
					flag = true;
				}
				else if (int_difficulty[0] == 4) exit(0);
				else { flag = false; }
			} while (flag == true);

			do {
				std::cout << "\n\n\nCHOOSE LIMIT:\n\n***10(A)***\n***100(B)***\n***1000(C)***\n***EXIT(D)***\n" 
					<< std::endl;
				getline(std::cin, limit, '\n');
				std::stringstream sstream2(limit);
				sstream2 >> b;
				char_limit.push_back(b);
				switch (char_limit[0])
				{
				case 'a':
					flag2 = false;
					char_limit[0] = toupper(char_limit[0]);
					break;
				case 'A':
					flag2 = false;
					break;
				case 'b':
					flag2 = false;
					char_limit[0] = toupper(char_limit[0]);
					break;
				case 'B':
					flag2 = false;
					break;
				case 'c':
					flag2 = false;
					char_limit[0] = toupper(char_limit[0]);
					break;
				case 'C':
					flag2 = false;
					break;
				case 'd':
					char_limit.clear();
					flag2 = false;
					std::cout << "\nDO YOU WANT TO EXIT?\nYES(Y)\nNO(N)"
						<< std::endl;
					getline(std::cin >> std::ws, confirmation);
					while (1) {
						if (confirmation[0] == 'y' || confirmation[0] == 'Y') exit(0);
						else if (confirmation[0] == 'n' || confirmation[0] == 'N') {
							flag2 = true;
							break;
						}
						else {
							std::cout << "\n\nINVALID INPUT\nDO YOU WANT TO EXIT?\nYES(Y)\nNO(N)"
								<< std::endl;
							getline(std::cin >> std::ws, confirmation);							
						}
					}
					break;
				case 'D':
					flag2 = false;
					exit(0);
					break;
				default:
					char_limit.clear();
					std::cout << std::endl << "INVALID INPUT." << std::endl;
					flag2 = true;
				}
			} while (flag2 == true);

			if (char_limit[0] == 'A') int_limit = 10;
			else if (char_limit[0] == 'B') int_limit = 100;
			else if (char_limit[0] == 'C') int_limit = 1000;
			
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				<< std::endl << "DIFFICULTY: ";
			switch (int_difficulty[0])
			{
			case 1:
				std::cout << "EASY";
				break;
			case 2:
				std::cout << "MEDIUM";
				break;
			case 3:
				std::cout << "HARD";
				break;
			}
			std::cout << "\t\t\t\t\t\tLIMIT: " << int_limit
				<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				
				<< std::endl << "PRESS ENTER TO CONTINUE OR ANY KEY TO EXIT: ";
			if (std::cin.get() != '\n') exit(0);

			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl
				<< "SCORE: CPU " << cpu_score << " - " << user_score << ' ' << username
				<< "\t\t\t\t\t\tNUMBER OF ATTEMPTS: ";
			switch (int_difficulty[0])
			{
			case 1:
				if (int_limit == 10) attempts = 4;//4
				else if (int_limit == 100) attempts = 10;//10
				else if (int_limit == 1000) attempts = 15;//15
				break;
			case 2:
				if (int_limit == 10) attempts = 3;//3
				else if (int_limit == 100) attempts = 6;//6
				else if (int_limit == 1000) attempts = 10;//10
				break;
			case 3:
				if (int_limit == 10) attempts = 2;//2
				else if (int_limit == 100) attempts = 4;//4
				else if (int_limit == 1000) attempts = 8;//8
				break;
			}
			std::cout << attempts;

			var_rand_int = random_int(int_limit);

			for (i; attempts != 0; ++i) {
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl
					<< "MAKE A GUESS: ";
				getline(std::cin, guess, '\n');
				std::stringstream sstream3(guess);
				sstream3 >> c;
				int_guess.push_back(c);
				if (int_guess[i] != var_rand_int) {
					attempts -= 1;
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl
						<< "SCORE: CPU " << cpu_score << " - " << user_score << ' ' << username
						<< "\t\t\t\t\t\tNUMBER OF ATTEMPTS: " << attempts;
					if (int_guess[i] < var_rand_int) {
						std::cout << "\n\n" << std::endl
							<< "YOU ARE LOOKING FOR A BIGGER NUMBER";
					}
					else if (int_guess[i] > var_rand_int) {
						std::cout << "\n\n" << std::endl
							<< "YOU ARE LOOKING FOR A SMALLER NUMBER";
					}
				}
				else if (int_guess[i] == var_rand_int) break;
			}
			if (attempts == 0) {
				cpu_score += 1;
				std::cout << "\n\n\nGAME OVER! YOU LOST, " << username << '!' << std::endl
					<< "THE NUMBER WAS " << var_rand_int << "\n\n\n\n" << std::endl
					<< "SCORE: CPU " << cpu_score << " - " << user_score << ' ' << username
					<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
			}
			else if (attempts != 0) {
				user_score += 1;
				std::cout << "\n\n\nYOU WON, " << username << '!' << " THE NUMBER WAS " << var_rand_int
					<< "\n\n\n\n\n" << std::endl
					<< "SCORE: CPU " << cpu_score << " - " << user_score << ' ' << username
					<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
			}
			do {
				std::cout << "DO YOU WANT TO PLAY AGAIN? YES(Y) NO(N): ";
				std::cin >> play_again;
				play_again = toupper(play_again);
				switch (play_again)
				{
				case 'Y':
					flag3 = false;
					break;
				case 'N':
					restart_game = false;
					flag3 = false;
					break;
				default:
					flag3 = true;
					break;
				}
			} while (flag3 == true);
		} while (restart_game == true);

		std::cout << std::endl << "THANKS FOR PLAYING, " << username << '!'
			<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	
		return 0;
}
