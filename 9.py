import random, sys

restartGame = True
username = ""
cpuScore = 0
user_score = 0  

while restartGame == True:
    print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
    print("_______________________________________________________________\n|\t\t\t\t\t\t\t\t|")
    print("|\t\t\tNUMBER GUESSING GAME\t\t\t|")
    print("|_______________________________________________________________|\n\n")

    username = input("ENTER YOUR USERNAME: ")
    username = username.strip()

    while True:
        difficulty = input("SELECT DIFFICULTY:\n\n-EASY(1)\n-MEDIUM(2)\n-HARD(3)\n-EXIT(4)\n\n")
        difficulty = difficulty.strip()
        if difficulty.isdigit():
            var_difficulty = int(difficulty)
            if var_difficulty < 1 or var_difficulty > 4:
                print("\n\nINVALID INPUT.\n")
            elif var_difficulty == 4:
                sys,exit()
            else:
                break
        else:
            print("\n\nINVALID INPUT.\n")
        
    while True:
        limit = input("\n\n\nCHOOSE LIMIT:\n\n***10(A)***\n***100(B)***\n***1000(C)***\n***EXIT(D)***\n\n")
        limit = limit.strip()
        if not limit.isalpha():
            print("\nINVALID INPUT.")
        else:
            limit = limit.lower()
        if limit == 'a':
            var_limit = 10
            break
        elif limit == 'b':
            var_limit = 100
            break
        elif limit == 'c':
            var_limit = 1000
            break
        elif limit == 'd':
            while True:
                confirmation = input("\nDO YOU WANT TO EXIT?\nYES(Y)\nNO(N)\n")
                confirmation = confirmation.strip()
                if not confirmation.isalpha():
                    print("\n\nINVALID INPUT")
                else:
                    confirmation = confirmation.lower()                
                if confirmation == 'n':
                    break
                elif confirmation == 'y': 
                    sys.exit()
                else: 
                    print("\n\nINVALID INPUT")
        else:
            print("\nINVALID INPUT.")

    print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDIFFICULTY: ", end='')
    if var_difficulty == 1:
        print("EASY", end='') 
    elif var_difficulty == 2:
        print("MEDIUM", end='')
    else:
        print("HARD", end='')
    
    print("\t\t\t\t\t\tLIMIT: {0}".format(var_limit))
    key = input("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE OR ANY KEY TO EXIT: ")
    if key != '':
        sys.exit()  
    
    print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSCORE: CPU {0} - {1} {2}".format(cpuScore, user_score, username), end="")
    print("\t\t\t\t\t\tNUMBER OF ATTEMPTS: ", end="")
    if var_difficulty == 1:
        if var_limit == 10: 
            attempts = 4
        elif var_limit == 100:
            attempts = 10
        else:
            attempts = 15
    elif var_difficulty == 2:
        if var_limit == 10:
            attempts = 3
        elif var_limit == 100:
            attempts = 6
        else:
            attempts == 10
    else:
        if var_limit == 10:
            attempts = 2
        elif var_limit == 100:
            attempts = 4
        else:
            attempts = 8
    print(attempts)

    varRandomNum = random.randint(1, var_limit)

    while True:
        guess = input("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nMAKE A GUESS: ")
        guess = guess.strip()
        if not guess.isdigit():
            attempts -= 1
            print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSCORE: CPU {0} - {1} {2}".format(cpuScore, user_score, username), end="")
            print("\t\t\t\t\t\tNUMBER OF ATTEMPTS: {0}".format(attempts))
        else:
            varGuess = int(guess)
            if varGuess != varRandomNum:
                attempts -= 1
                print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSCORE: CPU {0} - {1} {2}".format(cpuScore, user_score, username), end="")
                print("\t\t\t\t\t\tNUMBER OF ATTEMPTS: {0}".format(attempts))
                if varGuess < varRandomNum:
                    print("\n\n\nYOU ARE LOOKING FOR A BIGGER NUMBER")
                else:
                    print("\n\n\nYOU ARE LOOKING FOR A SMALLER NUMBER")
        if attempts == 0 or varGuess == varRandomNum:
            break

    if attempts == 0:
        cpuScore += 1
        print("\n\n\nGAME OVER! YOU LOST, {0}!".format(username))
        print("THE NUMBER WAS {0}\n\n\n\n".format(varRandomNum))
        print("SCORE: CPU {0} - {1} {2}\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n".format(cpuScore, user_score, username))
    else:
        user_score += 1
        print("\n\n\nYOU WON, {0}! THE NUMBER WAS {1}\n\n\n\n\n".format(username, varGuess))

    
    while True:
        playAgain = input("DO YOU WANT TO PLAY AGAIN? YES(Y) NO(N): ")
        playAgain = playAgain.strip().upper()
        if playAgain == 'Y':
            break
        if playAgain == 'N':
            restartGame = False
            break

print("Thanks for playing, " + username + '!')
print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")



    
