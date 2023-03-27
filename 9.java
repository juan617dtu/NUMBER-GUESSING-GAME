import java.text.NumberFormat;
import java.text.ParsePosition;
import java.util.Random;
import java.util.Scanner;

public class Main {
	
	static boolean restartGame = true;
	static int cpuScore = 0, userScore = 0;
	static String username;
	static Scanner scanf = new Scanner(System.in);
	
	static boolean isDigit(String str) {
		
		ParsePosition pos = new ParsePosition(0);
		NumberFormat.getInstance().parse(str, pos);
		return str.length() == pos.getIndex();
	}
	
	static String oddOrEven(int n) {
		
		if (n % 2 == 0) return "EVEN";
		
		return "ODD";
	}

	public static void main(String[] args) {
		
		do {
			                    
			 System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			 System.out.println(" ____________________________________________________________"
			 		+ "___\n|\t\t\t\t\t\t\t\t|");
			 System.out.println("|\t\t\tNUMBER GUESSING GAME\t\t\t|");
			 System.out.println("|_____________________________________________________________"
			 		+ "__|\n\n");
			 
			 System.out.print("ENTER YOUR USERNAME: ");
			 username = scanf.nextLine();
			 username = username.trim();
			 
			 boolean flag1 = false; String difficulty; double varDifficulty = 0;	
			 do {
				 System.out.println("\nSELECT DIFFICULTY:\n\n-EASY(1)\n-MEDIUM(2)\n-HARD(3)\n"
				 		+ "-EXIT(4)\n");
				 difficulty = scanf.nextLine();
				 difficulty = difficulty.trim();
				 if (!isDigit(difficulty)) {
					 System.out.println("\n\nINVALID INPUT.\n");
					 flag1 = true;
				 }
				 else { varDifficulty = Double.parseDouble(difficulty); 
				 	if (varDifficulty < 1 || varDifficulty > 4) {
				 		System.out.println("\n\nINVALID INPUT.\n");
						 flag1 = true;
				 	}
				 	else if (varDifficulty == 4) {
				 		System.exit(0);
				 	}
				 	else {
				 		flag1 = false;
				 	}
				 }
			 } while(flag1 == true);
			 
			boolean flag2 = false; String limit; int varLimit = 0;
			do {
				System.out.println("\n\n\nCHOOSE LIMIT:\n\n***10(A)***\n***100(B)***\n"
						+ "***1000(C)***\n***EXIT(D)***\n");
				limit = scanf.nextLine();
				limit = limit.trim().toUpperCase();
				switch (limit.charAt(0)) {
				case 'A':
					flag2 = false;
					varLimit = 10;
					break;
				case 'B':
					flag2 = false;
					varLimit = 100;
					break;
				case 'C':
					flag2 = false;
					varLimit = 1000;
					break;
				case 'D':
					System.out.println("\nDO YOU WANT TO EXIT?\nYES(Y)\nNO(N)");
					char charConfirmation; 
					String confirmation = scanf.nextLine();
					confirmation = confirmation.trim().toUpperCase();
					charConfirmation = confirmation.charAt(0);
					while(true) {
						if (charConfirmation == 'Y') System.exit(0); 
						else if (charConfirmation == 'N') {
								flag2 = true;
								break;
						}
						else {
							System.out.println("\n\nINVALID INPUT\nDO YOU WANT TO EXIT?\nYES(Y)\n"
									+ "NO(N)");
							confirmation = scanf.nextLine();
							confirmation = confirmation.trim().toUpperCase();
							charConfirmation = confirmation.charAt(0);
						}
					}
				default:
					System.out.print("\nINVALID INPUT.");
	                flag2 = true;
	                break;
				}
			} while (flag2 == true);
			
			 System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
			 		+ "DIFFICULTY: ");
			 switch ((int)varDifficulty) {
			 case 1:
				 System.out.print("EASY");
				 break;
			 case 2:
				 System.out.print("MEDIUM");
				 break;
			default:
				System.out.print("HARD");
				break;
			 }
			 System.out.print("\t\t\t\t\t\tLIMIT: " + varLimit);
			 
			 System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
			 		+ "PRESS ENTER TO CONTINUE OR ANY KEY TO EXIT: ");
			 String c = scanf.nextLine();
			 if (c.length() != 0) System.exit(0);
			 
			 System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSCORE: CPU "
			 + cpuScore + " - " + userScore + " " + username);
			 System.out.print("\t\t\t\t\t\tNUMBER OF ATTEMPTS: ");
			 int attempts = 0;
			 switch ((int)varDifficulty){
			 case 1:
		          if (varLimit == 10) attempts = 4;//4
		          else if (varLimit == 100) attempts = 10;//10
		          else if (varLimit == 1000) attempts = 15;//15
		          break;
		     case 2:
		          if (varLimit == 10) attempts = 3;//3
		          else if (varLimit == 100) attempts = 6;//6
		          else if (varLimit == 1000) attempts = 10;//10
		          break;
		     default:
		          if (varLimit == 10) attempts = 2;//2
	              else if (varLimit == 100) attempts = 4;//4
	              else if (varLimit == 1000) attempts = 8;//8
		          break;
			    }
			 System.out.print(attempts);
			 
			 Random rand = new Random();
			 int varRandNum = rand.nextInt(varLimit + 1); String guess; double varGuess = 0;
			 
			 do {
				 System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				 		+ "MAKE A GUESS: ");
				 guess = scanf.nextLine();
				 guess = guess.trim();
				 if (!isDigit(guess)) {
					 attempts -= 1;
					 System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSCORE: CPU "
					 + cpuScore + " - " + userScore + " " + username);
					 System.out.print("\t\t\t\t\t\tNUMBER OF ATTEMPTS: " + attempts);
				 }
				 else {
					 varGuess = Double.parseDouble(guess);
					 if (varGuess < varRandNum) {
						 attempts -= 1;
						 System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
						 		+ "SCORE: CPU "
						 + cpuScore + " - " + userScore + " " + username);
						 System.out.print("\t\t\t\t\t\tNUMBER OF ATTEMPTS: " + attempts);
						 System.out.print("\n\n\nYOU ARE LOOKING FOR A BIGGER AND "
								 + oddOrEven((int)varRandNum) + " NUMBER");
					 }
					 else if (varGuess > varRandNum) {
						 attempts -= 1;
						 System.out.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
						 		+ "SCORE: CPU "
						 + cpuScore + " - " + userScore + " " + username);
						 System.out.print("\t\t\t\t\t\tNUMBER OF ATTEMPTS: " + attempts);
						 System.out.print("\n\n\nYOU ARE LOOKING FOR A SMALLER AND " 
								 + oddOrEven((int)varRandNum) + " NUMBER");
					 }
				 }
			 } while ((int)varGuess != varRandNum && attempts > 0);
			 
			 if (attempts == 0) {
				 cpuScore += 1;
				 System.out.println("\n\n\nGAME OVER! YOU LOST, " + username + "!"
				 + "\nTHE NUMBER WAS "+ varRandNum + "\n\n\n\n");
				 System.out.println("SCCORE: CPU " + cpuScore + " - " + userScore + " "
				 + username + "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			 }
			 else if (attempts > 0) {
				 userScore += 1;
				 System.out.println("\n\n\nYOU WON, " + username + "! " + "THE NUMBER WAS "
				 + varRandNum + "\n\n\n\n\n");
			     System.out.println("SCORE: CPU " + cpuScore + " - " + userScore + " "
				 + username + "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			 }
			 
			 boolean flag3 = false; String playAgain; char charPlayAgain;
			 do {
				 System.out.print("DO YOU WANT TO PLAY AGAIN? YES(Y) NO(N): ");
				 
				 playAgain = scanf.nextLine();
				 playAgain = playAgain.trim().toUpperCase();
				 charPlayAgain = playAgain.charAt(0);
				 
				 switch(charPlayAgain) {
				 case 'Y':
					 flag3 = false;
					 break;
				 case 'N':
					 flag3 = false; 			
					 restartGame = false;
					 break;
				default:
					flag3 = true;
					break;

				 }
			 } while (flag3 == true);
			 
		} while (restartGame == true);
		
		System.out.print("\nTHANKS FOR PLAYING, " + username + "!");
		System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}

}
