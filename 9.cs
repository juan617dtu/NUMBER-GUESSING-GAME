using System;

bool restartGame = true;
int cpuScore = 0, userScore = 0;
string username;

do
{
    bool flag = false, flag2 = false, flag3 = false, flag5 = false;
    string difficulty, limit, guess, playAgain;
    char charLimit, charPlayAgain;
    int varDifficulty, varLimit = 0, attempts = 0, varGuess;

    Console.WriteLine("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    Console.WriteLine(" _______________________________________________________________\n|\t\t\t\t\t\t\t\t|");
    Console.WriteLine("|\t\t\tNUMBER GUESSING GAME\t\t\t|");
    Console.WriteLine("|_______________________________________________________________|\n\n");

    Console.Write("ENTER YOUR USERNAME: ");
    username = Console.ReadLine();
    username = username.Trim();
    
    do
    {
        Console.WriteLine("\nSELECT DIFFICULTY:\n\n-EASY(1)\n-MEDIUM(2)\n-HARD(3)\n-EXIT(4)\n");
        difficulty = Console.ReadLine();
        difficulty = difficulty.Trim();
        flag = Int32.TryParse(difficulty, out varDifficulty);
        if (!flag || varDifficulty < 1 || varDifficulty > 4)
        {
            Console.WriteLine("\n\nINVALID INPUT.\n");
            flag = true;
        }
        else if (varDifficulty == 4) System.Environment.Exit(0);
        else
        {
            flag = false;
        }
        
    } while (flag == true);
    
    do
    {
        Console.WriteLine("\n\n\nCHOOSE LIMIT:\n\n***10(A)***\n***100(B)***\n***1000(C)***\n***EXIT(D)***\n");
        limit = Console.ReadLine();
        limit = limit.Trim();
        charLimit = limit[0];
        switch (charLimit)
        {
            case 'a': 
                flag2 = false;
                charLimit = Char.ToUpper(charLimit);
                break;
            case 'A':
                flag2 = false;
                break;
            case 'b':
                flag2 = false;
                charLimit = Char.ToUpper(charLimit);
                break;
            case 'B':
                flag2 = false;
                break;
            case 'c':
                flag2 = false;
                charLimit = Char.ToUpper(charLimit);
                break;
            case 'C':
                flag2 = false;
                break;
            case 'd':
                flag2 = false;
                Console.WriteLine("\nDO YOU WANT TO EXIT?\nYES(Y)\nNO(N)");
                string confirmation;
                char charConfirmation;
                bool flag4 = false;
                confirmation = Console.ReadLine();
                confirmation = confirmation.Trim();
                charConfirmation = confirmation[0];
                do
                {
                    if (charConfirmation == 121 || charConfirmation == 89) System.Environment.Exit(0);
                    else if (charConfirmation == 110 || charConfirmation == 78)
                    {
                        flag2 = true;
                        flag4 = false;  
                    }
                    else
                    {
                        flag4 = true;
                        Console.WriteLine("\n\nINVALID INPUT\nDO YOU WANT TO EXIT?\nYES(Y)\nNO(N)");
                        confirmation = Console.ReadLine();
                        confirmation = confirmation.Trim();
                        charConfirmation = confirmation[0];
                    }
                } while (flag4 == true);
                break;
            case 'D':
                flag2 = false;
                System.Environment.Exit(0);
                break;
            default:
                Console.Write("\nINVALID INPUT.");
                flag2 = true;
                break;
        }
    } while (flag2 == true);

    if (charLimit == 65) varLimit = 10;
    else if (charLimit == 66) varLimit = 100;
    else if (charLimit == 67) varLimit = 1000;

    Console.Write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDIFFICULTY: ");
    switch (varDifficulty)
    {
        case 1:
            Console.Write("EASY");
            break;
        case 2:
            Console.Write("MEDIUM");
            break;
        default:
            Console.Write("HARD");
            break;
    }
    Console.Write("\t\t\t\t\t\tLIMIT: " + varLimit);
    Console.Write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE OR ANY KEY TO EXIT: ");
    if (Console.ReadKey().Key != ConsoleKey.Enter)
    {
        System.Environment.Exit(0);
    }
    
    Console.Write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSCORE: CPU " + cpuScore + " - " + userScore + " " + username);
    Console.Write("\t\t\t\t\t\tNUMBER OF ATTEMPTS: ");
    switch (varDifficulty)
    {
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
    Console.Write(attempts);

    Random randomNum = new Random();
    int varRandomNum = randomNum.Next(varLimit + 1);

    do
    {
        Console.Write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nMAKE A GUESS: ");
        guess = Console.ReadLine();
        guess = guess.Trim();
        flag3 = Int32.TryParse(guess, out varGuess);
        if (!flag3 || varGuess != varRandomNum)
        {
            attempts -= 1;
            Console.Write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSCORE: CPU " + cpuScore + " - " + userScore + " " + username);
            Console.Write("\t\t\t\t\t\tNUMBER OF ATTEMPTS: " + attempts);
            if (varGuess < varRandomNum) Console.Write("\n\n\nYOU ARE LOOKING FOR A BIGGER NUMBER");
            else if (varGuess > varRandomNum) Console.Write("\n\n\nYOU ARE LOOKING FOR A SMALLER NUMBER");
        }
        if (attempts == 0) break;
    } while (varGuess != varRandomNum);

    if (attempts == 0)
    {
        cpuScore += 1;
        Console.WriteLine("\n\n\nGAME OVER! YOU LOST, " + username + "!" + "\nTHE NUMBER WAS " + varRandomNum + "\n\n\n\n");
        Console.WriteLine("SCCORE: CPU " + cpuScore + " - " + userScore + " " + username + "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    else if (attempts != 0)
    {
        userScore += 1;
        Console.WriteLine("\n\n\nYOU WON, " + username + "! " + "THE NUMBER WAS " + varRandomNum + "\n\n\n\n\n");
        Console.WriteLine("SCORE: CPU " + cpuScore + " - " + userScore + " " + username + "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    do
    {
        Console.Write("DO YOU WANT TO PLAY AGAIN? YES(Y) NO(N): ");
        playAgain = Console.ReadLine();
        charPlayAgain = playAgain[0];
        switch (charPlayAgain)
        {
            case 'Y':
                flag5 = false;
                break;
            case 'y':
                flag5 = false;
                break;
            case 'N':
                restartGame = false;
                flag5 = false;
                break;
            case 'n':
                restartGame = false;
                flag5 = false;
                break;
            default:
                flag5 = true;
                break;
        }
    } while (flag5 == true);

} while (restartGame == true);

Console.Write("\nTHANKS FOR PLAYING, " + username + "!");
Console.WriteLine("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

return 0;
