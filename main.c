#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int energy = 100;
int grades = 70;
int happiness = 70;
int money = 50000;
void clearScreen();
void displayStats();
int getChoice(int max_choice);
void morningRoutine();
void campusActivities();
void workRoutine();
void eveningRoutine();
void updateStats(int e, int g, int h, int m);
void displayWelcomeAscii(char *name);
void displayDancingStickman();
int showWelcomeScreen();
void displayWelcomeAscii(char *name) {
    printf("\n");
    printf("    ______    _             _        _     _  __    \n");
    printf("   |  ____|  | |           ( )      | |   (_)/ _|   \n");
    printf("   | |__   __| | ___ _ __  |/ ___   | |    _| |_ ___ \n");
    printf("   |  __| / _` |/ _ \\ '_ \\  / __|   | |   | |  _/ _ \\\n");
    printf("   | |___| (_| |  __/ | | | \\__ \\   | |___| | ||  __/\n");
    printf("   |______\\__,_|\\___|_| |_| |___/   |_____|_|_| \\___|\n");
    printf("\n");
    printf("   Hello %s! Welcome to Eden's Life!\n", name);
    printf("   ========================================\n\n");
}
int showWelcomeScreen() {
    char name[50];
    char choice;
    clearScreen();
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    clearScreen();
    displayWelcomeAscii(name);
    do {
        printf("Press 'Y' to start or 'N' to quit: ");
        scanf(" %c", &choice);
        choice = toupper(choice);
    } while (choice != 'Y' && choice != 'N');
    if (choice == 'N') {
        clearScreen();
        printf("\n");
        printf("   😿 I'm sad you don't want to see my life. Bye-bye! 😿\n");
        printf("\n");
        return 0;
    }
    return 1;
}
void displayDancingStickman() {
    const char* frames[] = {
        "    \\o/\n"
        "     |\n"
        "    / \\\n",
        
        "     o\n"
        "    /|\\\n"
        "    / \\\n",
        
        "    \\o/\n"
        "     |\n"
        "    / \\\n",
        
        "     o\n"
        "    \\|/\n"
        "    / \\\n"
    };
    printf("\nThanks for playing! Here's a little dance!\n");
    for (int i = 0; i < 8; i++) {
        clearScreen();
        printf("%s", frames[i % 4]);
        printf("\nGoodbye! 👋\n");
        #ifdef _WIN32
            Sleep(300);
        #else
            usleep(300000);
        #endif
    }
}
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void displayStats() {
    printf("\nSTATS:\n");
    printf("Energy: %d/100\n", energy);
    printf("Grades: %d/100\n", grades);
    printf("Happiness: %d/100\n", happiness);
    printf("Money: UGX %d\n", money);
}
int getChoice(int max_choice) {
    int choice;
    char buffer[100];
    do {
        printf("\nEnter your choice (1-%d): ", max_choice);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &choice) != 1) {
                choice = 0;
            }
        }
    } while (choice < 1 || choice > max_choice);
    return choice;
}
void updateStats(int e, int g, int h, int m) {
    energy += e;
    grades += g;
    happiness += h;
    money += m;
    energy = (energy > 100) ? 100 : (energy < 0) ? 0 : energy;
    grades = (grades > 100) ? 100 : (grades < 0) ? 0 : grades;
    happiness = (happiness > 100) ? 100 : (happiness < 0) ? 0 : happiness;
}
void morningRoutine() {
    printf("\n=== MORNING ROUTINE ===\n");
    printf("What would you like to do?\n");
    printf("1. Wake up and have breakfast (Energy -10, Happiness +5)\n");
    printf("2. Go back to sleep (Energy +30, Grades -10, Happiness +5)\n");
    int choice = getChoice(2);
    if (choice == 1) {
        printf("\nYou get up and prepare for the day.\n");
        updateStats(-10, 0, 5, -2000); // Added cost for breakfast
    } else {
        printf("\nYou sleep in and miss morning classes.\n");
        updateStats(30, -10, 5, 0);
    }
    displayStats();
}
void campusActivities() {
    printf("\n=== CAMPUS ACTIVITIES ===\n");
    printf("It's 11:00 AM. What's your plan?\n");
    printf("1. Attend lectures (Energy -20, Grades +15, Happiness -5)\n");
    printf("2. Skip lectures (Energy -5, Grades -10, Happiness +10)\n");
    printf("3. Study in library (Energy -15, Grades +20, Happiness -10)\n");
    int choice = getChoice(3);
    switch(choice) {
        case 1:
            printf("\nYou attend your lectures attentively.\n");
            updateStats(-20, 15, -5, -1000);
            break;
        case 2:
            printf("\nYou skip lectures and download movies.\n");
            updateStats(-5, -10, 10, -3000); 
            break;
        case 3:
            printf("\nYou spend time studying in the library.\n");
            updateStats(-15, 20, -10, -500); 
            break;
    }

    displayStats();
}
void workRoutine() {
    printf("\n=== WORK ROUTINE ===\n");
    printf("Do you want to go to work?\n");
    printf("1. Work part-time (Energy -30, Happiness -10, Money +20000)\n");
    printf("2. Do freelance work (Energy -20, Happiness -5, Money +15000)\n");
    printf("3. Rest at home (Energy +10, Happiness +10)\n");
    int choice = getChoice(3);
    switch(choice) {
        case 1:
            printf("\nYou work a shift at your part-time job.\n");
            updateStats(-30, 0, -10, 20000);
            break;
        case 2:
            printf("\nYou do some freelance work from home.\n");
            updateStats(-20, 0, -5, 15000);
            break;
        case 3:
            printf("\nYou skip work and relax instead.\n");
            updateStats(10, 0, 10, 0);
            break;
    }
    displayStats();
}
void eveningRoutine() {
    printf("\n=== EVENING ACTIVITIES ===\n");
    printf("How do you want to spend your evening?\n");
    printf("1. Watch movies (Energy -10, Grades -5, Happiness +20, Money -5000)\n");
    printf("2. Study more (Energy -20, Grades +15, Happiness -10)\n");
    printf("3. Go out with friends (Energy -25, Grades -10, Happiness +30, Money -10000)\n");
    printf("4. Early sleep (Energy +40, Happiness +5)\n");
    int choice = getChoice(4);
    switch(choice) {
        case 1:
            printf("\nYou relax watching movies.\n");
            updateStats(-10, -5, 20, -5000);
            break;
        case 2:
            printf("\nYou do some extra studying.\n");
            updateStats(-20, 15, -10, 0);
            break;
        case 3:
            printf("\nYou go out with friends.\n");
            updateStats(-25, -10, 30, -10000);
            break;
        case 4:
            printf("\nYou get an early night's sleep.\n");
            updateStats(40, 0, 5, 0);
            break;
    }
    displayStats();
}
int main() {
    srand(time(NULL));

    if (!showWelcomeScreen()) {
        return 0;
    }
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        energy = 100;
        grades = 70;
        happiness = 70;
        money = 50000;
        clearScreen();
        // Start the day
        printf("\nIt's 6:00 AM. A new day begins...\n");
        morningRoutine();
        if (energy > 0) {
            campusActivities();
        }
        if (energy > 0) {
            workRoutine();
        }
        if (energy > 0) {
            eveningRoutine();
        }
        printf("\n=== END OF DAY SUMMARY ===\n");
        displayStats();
        if (grades < 50 || happiness < 20 || energy < 10 || money < 0) {
            printf("\n=== GAME OVER ===\n");
            if (grades < 50) printf("Your grades are too low! Academic probation!\n");
            if (happiness < 20) printf("You're severely depressed! Seek help!\n");
            if (energy < 10) printf("You've collapsed from exhaustion!\n");
            if (money < 0) printf("You're in debt! Time to call home!\n");
        }
        printf("\nWould you like to play another day? (y/n): ");
        scanf(" %c", &playAgain);
        getchar();
    }
    displayDancingStickman();
    return 0;
}
