// Librarys_
// Screens_
// Meseges_
// Functions_
// Main_function_
	// Start_Game_ 
	// Menu_Screen_
		// Start_Menu_Screen_
		// Move_to_Play_Screen_
		// Exit_game_
		// Wrong_input_
	// Play_Screen_
		// Start_Play_Screen_
		// Move_to_Menu_screen_
		// Exit_gmae_
		// If_user_win_
		// If_user_lose_
		// If_game_draw_
		// Wrong_input_
	// Exit_game_

// Librarys_========================================================
#include <iostream>
#include <cstdlib>	// For Random Number
#include <time.h>	// For Random Number
#include <stdlib.h>	// For Clean Sclreen
using namespace std;

// Screens_=========================================================
enum all_screens {
	Menu_screen,
	Play_screen
};

void show_menu_screen() {
	cout << "\n ======================*======================\n";
	cout << "             -{{{ Menu Screen }}}-\n";
	cout << " =============================================\n";
	cout << " Enter your choice : \n";
	cout << "\tStart Game      ==> s\n";
	cout << "\tExit            ==> e\n";
	cout << "\n =============================================\n";
	cout << "\t----------------> : ";
}
void show_play_screen() {
	cout << "\n ======================*======================\n";
	cout << "             -{{{ Play Screen }}}- \n";
	cout << " =============================================\n";
	cout << " Enter your choice :\n";
	cout << "\tRock            ==> 1\n";
	cout << "\tScissors        ==> 2\n";
	cout << "\tPaper           ==> 3\n";
	cout << "\tMenu            ==> m\n";
	cout << "\tExit            ==> e\n";
	cout << "\n =============================================\n";
	cout << "\t----------------> : ";
}

// Meseges_=========================================================
void msg_welcome() {
	cout << "\n ======================*======================\n";
	cout << " = Welcome to -{ Rock Paper Scissors Game }- =\n";
	cout << " =============================================\n\n";
}
void msg_goodbye(){
	cout << "\n ======================*======================\n";
	cout << " =              Thanks For Playing.          =\n";
	cout << " =============================================\n\n";
}
void msg_wrong_input() {
	cout << "\n ======================*======================\n";
	cout << "                Eroor msage !!!\n";
	cout << " =============================================\n";
	cout << " Your input is wrong???\n";
	cout << " Pleas enter the right input.\n\n";
}

void msg_you_win(string user_input, int roboot_choice) {
	cout << "\n ======================*======================\n";
	cout << "                    Results\n";
	cout << " =============================================\n";
	cout << " Your choice is        --> " << user_input << "\n";
	cout << " Roboot choice is      --> " << roboot_choice << "\n\n";
	cout << " YOU WIN...\n";
	cout << "\n Play again \n";
}
void msg_game_over(string user_input, int roboot_choice) {
	cout << "\n ======================*======================\n";
	cout << "                    Results\n";
	cout << " =============================================\n";
	cout << " Your choice is        --> " << user_input << "\n";
	cout << " Roboot choice is      --> " << roboot_choice << "\n\n";
	cout << " GAME OVER...\n";
	cout << "\n Play again \n";
}
void msg_draw_game(string user_input, int roboot_choice) {
	cout << "\n ======================*======================\n";
	cout << "                    Results\n";
	cout << " =============================================\n";
	cout << " Your choice is        --> " << user_input << "\n";
	cout << " Roboot choice is      --> " << roboot_choice << "\n\n";
	cout << " It's a Draw...\n";
	cout << "\n Play again \n";
}

// Functions_=======================================================
int random_number(int min, int max) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);

	return (rand() % (max - min + 1)) + min;
}

// Main_function_===================================================
int main() {
	// Start_Game_--------------------------------------------------
	enum all_screens current_screen = Menu_screen;
	bool exit = false;
	string user_input;
	system("clear");
	msg_welcome();

	while (exit == false) {
		// Menu_Screen_---------------------------------------------
		if (current_screen == Menu_screen) {
			// Start_Menu_Screen_- - - - - - - - - - - - - - - - - -
			show_menu_screen();
			getline(cin, user_input);
			// Move_to_Play_Screen_- - - - - - - - - - - - - - - - -
			if (user_input == "s") {
				current_screen = Play_screen;
				system("clear");
			}
			// Exit_game_- - - - - - - - - - - - - - - - - - - - - -
			else if (user_input == "e") {
				exit = true;
			}
			// Wrong_input_- - - - - - - - - - - - - - - - - - - - -
			else {	
				system("clear");
				msg_wrong_input(); 
			}
		}
		// Play_Screen_---------------------------------------------
		// 1 = Rock
		// 2 = Scissors
		// 3 = Paper
		else if (current_screen == Play_screen) {
			// Start_Play_Screen_- - - - - - - - - - - - - - - - - -
			show_play_screen();
			getline(cin, user_input);
			int roboot_choice = random_number(1,3);
			system("clear");

			// Move_to_Menu_screen_- - - - - - - - - - - - - - - - -
			if (user_input == "m") current_screen = Menu_screen;

			// Exit_gmae_- - - - - - - - - - - - - - - - - - - - - -
			else if (user_input == "e") exit = true;

			// If_user_win_- - - - - - - - - - - - - - - - - - - - -
			else if (
						(user_input == "1" && roboot_choice == 2) || 
						(user_input == "2" && roboot_choice == 3) || 
						(user_input == "3" && roboot_choice == 1)) 
						{
							msg_you_win(user_input, roboot_choice);
						}

			// If_user_lose_ - - - - - - - - - - - - - - - - - - - -
			else if (
						(user_input == "1" && roboot_choice == 3) || 
						(user_input == "2" && roboot_choice == 1) || 
						(user_input == "3" && roboot_choice == 2)) 
						{
							msg_game_over(user_input, roboot_choice);
						}

			// If_game_draw_ - - - - - - - - - - - - - - - - - - - -
			else if (
						(user_input == "1" && roboot_choice == 1) || 
						(user_input == "2" && roboot_choice == 2) || 
						(user_input == "3" && roboot_choice == 3)) 
						{
							msg_draw_game(user_input, roboot_choice);
						}

			// Wrong_input_- - - - - - - - - - - - - - - - - - - - -
			else { 
				system("clear");
				msg_wrong_input(); 
			}

		}

	}
	
	// Exit_game_-----------------------------------------------------
	system("clear");
	msg_goodbye();
}


