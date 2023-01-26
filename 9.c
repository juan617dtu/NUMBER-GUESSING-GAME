#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* remove_ws(char* d) {
	
	int non_spaces = 0;
	
	for (int i = 0; d[i] != '\0'; i++) {
		if (d[i] != ' ') {
			d[non_spaces] = d[i];
			non_spaces++;
		}
	}
	d[non_spaces] = '\0'; 
	return d;
}

int random_num(int l) {
	
	srand(time(NULL));
	int r = rand() % l;
	return r;
}

int main() {

	bool restart_game = true; 
	int cpu_score = 0, user_score = 0;
	char username[100];

	do {

		bool flag = false, flag2 = false, flag3 = false;  
		char difficulty[100], limit[100], guess[100], key[2], play_again[100];
		int var_difficulty, var_limit, attempts, var_rand_num, var_guess;

		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf(" _______________________________________________________________\n|\t\t\t\t\t\t\t\t|\n");
		printf("|\t\t\tNUMBER GUESSING GAME\t\t\t|\n");
		printf("|_______________________________________________________________|\n\n\n");

		printf("ENTER YOUR USERNAME: ");
		fgets(username, 100, stdin);
		remove_ws(username);
		username[strcspn(username, "\n")] = 0;

		do {
			printf("\nSELECT DIFFICULTY:\n\n-EASY(1)\n-MEDIUM(2)\n-HARD(3)\n-EXIT(4)\n\n");
			fgets(difficulty, 100, stdin);
			remove_ws(difficulty);
			var_difficulty = atoi(difficulty);
			if (var_difficulty < 1 || var_difficulty > 4) {
				printf("\n\nINVALID INPUT.\n\n");
				flag = true;
			}
			else if (var_difficulty == 4) {
				exit(0);
			}
			else {
				flag = false;
			}
		} while (flag == true);

		do {
			printf("\n\n\nCHOOSE LIMIT:\n\n***10(A)***\n***100(B)***\n***1000(C)***\n***EXIT(D)***\n\n");
			fgets(limit, 100, stdin);
			remove_ws(limit);
			switch (limit[0])
			{
			case 'a':
				flag2 = false;
				limit[0] = toupper(limit[0]);
				break;
			case 'A':
				flag2 = false;
				break;
			case 'b':
				flag2 = false;
				limit[0] = toupper(limit[0]);
				break;
			case 'B':
				flag2 = false;
				break;
			case 'c':
				flag2 = false;
				limit[0] = toupper(limit[0]);
				break;
			case 'C':
				flag2 = false;
				break;
			case 'd':
				flag2 = false;
				printf("\nDO YOU WANT TO EXIT?\nYES(Y)\nNO(N)\n");
				char confirmation[100];
				fgets(confirmation, 100, stdin);
				remove_ws(confirmation);
				while (1) {
					if (confirmation[0] == 121 || confirmation[0] == 89) exit(0);
					else if (confirmation[0] == 110 || confirmation[0] == 78) {
						flag2 = true;
						break;
					}
					else {
						printf("\n\nINVALID INPUT\nDO YOU WANT TO EXIT?\nYES(Y)\nNO(N)\n");
						fgets(confirmation, 100, stdin);
						remove_ws(confirmation);
					}
				}
				break;
			case 'D':
				flag2 = false;
				exit(0);
				break;
			default:
				printf("\nINVALID INPUT.");
				flag2 = true;
			}
		} while (flag2 == true);

		if (limit[0] == 65) var_limit = 10;
		else if (limit[0] == 66) var_limit = 100;
		else if (limit[0] == 67) var_limit = 1000;

		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDIFFICULTY: ");
		switch (var_difficulty)
		{
		case 1:
			printf("EASY");
			break;
		case 2:
			printf("MEDIUM");
			break;
		default:
			printf("HARD");
			break;
		}
		printf("\t\t\t\t\t\tLIMIT: %d", var_limit);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE OR ANY KEY TO EXIT: ");
		fgets(key, 2, stdin);
		switch (key[0])
		{
		case '\n':
			break;
		default:
			exit(0);
			break;
		}

		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSCORE: CPU %d - %d %s", cpu_score, user_score, username);
		printf("\t\t\t\t\t\tNUMBER OF ATTEMPTS: ");
		switch (var_difficulty)
		{
		case 1:
			if (var_limit == 10) attempts = 4;//4
			else if (var_limit == 100) attempts = 10;//10
			else if (var_limit == 1000) attempts = 15;//15
			break;
		case 2:
			if (var_limit == 10) attempts = 3;//3
			else if (var_limit == 100) attempts = 6;//6
			else if (var_limit == 1000) attempts = 10;//10
			break;
		default:
			if (var_limit == 10) attempts = 2;//2
			else if (var_limit == 100) attempts = 4;//4
			else if (var_limit == 1000) attempts = 8;//8
			break;
		}
		printf("%d", attempts);

		var_rand_num = random_num(var_limit);

		do {
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nMAKE A GUESS: ");
			fgets(guess, 100, stdin);
			remove_ws(guess);
			var_guess = atoi(guess);
			if (var_guess != var_rand_num) {
				attempts -= 1;
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSCORE: CPU %d - %d %s", cpu_score, user_score, username);
				printf("\t\t\t\t\t\tNUMBER OF ATTEMPTS: %d", attempts);
				if (var_guess < var_rand_num) printf("\n\n\nYOU ARE LOOKING FOR A BIGGER NUMBER");
				else if (var_guess > var_rand_num) printf("\n\n\nYOU ARE LOOKING FOR A SMALLER NUMBER");
			}
			if (attempts == 0) break;
		} while (var_guess != var_rand_num);

		if (attempts == 0) {
			cpu_score += 1;
			printf("\n\n\nGAME OVER! YOU LOST, %s!\nTHE NUMBER WAS %d\n\n\n\n\n", username, var_rand_num);
			printf("SCORE: CPU %d - %d %s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", cpu_score, user_score, username);
		}
		else if (attempts != 0) {
			user_score += 1;
			printf("\n\n\nYOU WON, %s! THE NUMBER WAS %d\n\n\n\n\n\n", username, var_rand_num);
			printf("SCORE: CPU %d - %d %s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", cpu_score, user_score, username);
		}

		do {
			printf("DO YOU WANT TO PLAY AGAIN? YES(Y) NO(N): ");
			fgets(play_again, 100, stdin);
			switch (play_again[0])
			{
			case 'Y':
				flag3 = false;
				break;
			case 'y':
				flag3 = false;
				break;
			case 'N':
				restart_game = false;
				flag3 = false;
				break;
			case 'n':
				restart_game = false;
				flag3 = false;
				break;
			default:
				flag3 = true;
				break;
			}
		} while (flag3 == true);
	
	} while (restart_game == true);

	printf("\nTHANKS FOR PLAYING, %s!", username);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	return 0;
}
