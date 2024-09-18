#include <iostream>
#include <windows.h>
#include <vector>
#include <random>
#include <string>
#include <ctime>
#include <cmath>


int main(){



	std::setlocale(LC_ALL, "Russian");
	srand(time(0));


	int user_choice = 0, task_selection = 0;
	bool choice_made = false, task_ended = false;
	
	std::string homeworks[]{ "[04.09.24]","[11.09.24]"};


	std::string homework_material1[]{ "Cow" };
	std::string homework_material2[]{ "Time to airport", "Scooter cost", "Fuel consumption" };
	
	std::vector<std::vector<std::string>> homework_materials = {
		{ "Cow" },
		{ "Time to airport", "Scooter cost", "Fuel consumption" }
	};



	while (choice_made != true) {
		user_choice = 0;
		task_selection = 0;
		std::cout << "Choose what homework you want to launch\nor write \"0\" to go back\n\n";
		Sleep(500);
		for (int i = 0; i != size(homeworks); i++) {
			Sleep(100);
			std::cout << i + 1 << " - " << homeworks[i];
			if (i == size(homeworks) - 1) { std::cout << "(latest)\n\n>>> "; }
			else { std::cout << std::endl; }
		}
		std::cin >> user_choice;
		if (user_choice > 0 && user_choice <= size(homeworks)) {
			std::cout << "\nOpening " << homeworks[user_choice - 1] << " homework";
			Sleep(500);
			task_ended = false;
			while (task_ended != true) {
				std::cout << "\n\n";
				for (int i = 0; i != size(homework_materials[user_choice - 1]); i++) {
					Sleep(100);
					std::cout << i + 1 << " - " << homework_materials[user_choice - 1][i] << std::endl;
				}

				std::cout << "\n>>> ";
				std::cin >> task_selection;

				if (task_selection == 0) {
					choice_made = false;
					task_ended = true;
				}

				if (user_choice == 1) {
					if (task_selection == 1) {
						int a = rand() % (10 - 30 + 1) + 10;
						std::string phrase;
						std::string b = "_";

						if (a < 18) { phrase = "Я не муве по Польски"; }
						if (a >= 18 && a <= 24) { phrase = "Э, СЛУЖИВЫЙ?! ЭТО НАША ТОЧКА!"; }
						if (a > 24) { phrase = "Хайр ми, плиз, май ворк\n\tас а программер ис рили хард"; }


						for (int i = 0; i < 80; i++) {
							if (i == 40) {
								std::cout << "\n<<<\t" << phrase << "\t >>> \n";

							}
							std::cout << b;
						}
						std::cout << "\n\t\t\t\\ /\n\t\t\t \\|_"
							<< "  ^__^\n\t\t\t      (00)\\_______"
							<< "\n\t\t\t      (__)\\\t  )\\/\\"
							<< "\n\t\t\t\t  ||----w |"
							<< "\n\t\t\t\t  ||     ||";
					}
					else { std::cout << "\nWrong number, try again\n"; }
				}
					


				else if (user_choice == 2) {
					if (task_selection == 1){

						int distance = -1, time_left = -1;
						bool distance_entered = false, time_entered = false;

							while (distance_entered == false) {
								std::cout << "\nENTER A DISTANCE TO AIRPORT IN KILOMETERS! FAST!\n\n>>> ";
								std::cin >> distance;
								if (distance > 0){ std::cout << "\nYES, NOW ENTER THE TIME IN MINUTES!\n\n>>> ";
								distance_entered = true;
								}
								else if(distance == 0){ std::cout << "\nErm, you're already on the airport, bruh "; }
								else{ std::cout << "\n liar liar, pants on fire, reenter the distance "; }
							}
							while (time_entered == false) {
								std::cin >> time_left;
								if (time_left > 0) {
									std::cout << "\nWell, cool, you must drive on the minimal " << round(distance/(time_left/60) )
										<< "km/h,\nto make your way to the airport before the plane will fly away\n";
									time_entered = true;
								}
								else if (time_left == 0) { std::cout << "\nWell, you must teleport yourself right into the plane right now\n";
								time_entered = true;
								}
								else { std::cout << "\n you can not enter this value, try again "; }
							}
					}



					else if (task_selection == 2) {




						int first_hour = -1, first_minute = -1, first_second = -1, second_hour = -1, second_minute = -1, second_second = -1;
						float minutes_of_ride = 0, seconds_to_count;
						bool first_entered = false, second_entered = false;
						std::cout << "Enter the first time you've stepped on the scooter\n";
						while (first_hour < 0 || first_hour > 24) {
							std::cout << "\nHour >>> ";
							std::cin >> first_hour;
						}
						while (first_minute < 0 || first_minute > 60) {
							std::cout << "\nMinute >>> ";
							std::cin >> first_minute;
						}
						while (first_second < 0 || first_second > 60) {
							std::cout << "\nSecond >>> ";
							std::cin >> first_second;
						}


						std::cout << "\nNow enter the time when you ended your ride\n";
						while (second_hour < 0 || second_hour > 24) {
							std::cout << "\nHour >>> ";
							std::cin >> second_hour;
						}
						while (second_minute < 0 || second_minute > 60) {
							std::cout << "\nMinute >>> ";
							std::cin >> second_minute;
						}
						while (second_second < 0 || second_second > 60) {
							std::cout << "\nSecond >>> ";
							std::cin >> second_second;
						}



						while (first_hour != second_hour || first_minute != second_minute || first_second != second_second) {
							if (first_second == 59) { first_second = -1; first_minute++;minutes_of_ride += 1;}
							if (first_minute == 60) { first_minute = 0; first_hour++; }
							if (first_hour == 24) { first_hour = 0; }
							first_second++;

							seconds_to_count = first_second;
							minutes_of_ride = minutes_of_ride + remainder(seconds_to_count /100, 2);
						}
						std::cout << "Total cost: "<< minutes_of_ride * 2 << std::endl;
						
					}
					




					else if (task_selection == 3) {
						float distance = -1, consumption = -1, type_1 = -1, type_2 = -1, type_3 = -1,cost_type_1, cost_type_2, cost_type_3;



						std::cout << "\nEnter the distance in kilometers you're ridin' for\n\n>>> ";
						while (distance < 1) {
							std::cin >> distance;
						}
						std::cout << "\nEnter the consumption of your car\n[LITERS per 100 kilometers]\n\n>>> ";
						while (consumption < 1) {
							std::cin >> consumption;
						}



						std::cout << "\nEnter the cost of first fuel[single liter]\n\n>>> ";

						while (type_1 < 1) {
							std::cin >> type_1;
						}
						std::cout << "\nEnter the cost of second fuel[single liter]\n\n>>> ";
						while (type_2 < 1) {
							std::cin >> type_2;
						}
						std::cout << "\nEnter the cost of third fuel[single liter]\n\n>>> ";
						while (type_3 < 1) {
							std::cin >> type_3;
						}
						std::cout
							<< "___________________________________________\n"
							<< "|                  Fuel                   |\n"
							<< "|_________________________________________|\n"
							<< "|   Mark    | Cost per liter | Total cost |\n"
							<< "|-----------|----------------|------------|\n"
							<< "|   first   |   " << type_1 << "          |   " << ((consumption / 100) * distance) * type_1 << " |\n"
							<< "|           |                |            |\n"
							<< "|  second   |   " << type_2 << "          |   " << ((consumption / 100) * distance) * type_2 << " |\n"
							<< "|           |                |            |\n"
							<< "|   third   |   " << type_3 << "          |   " << ((consumption / 100) * distance) * type_3 << " |\n"
							<< "|___________|________________|____________|\n";
							
							







					}



					else { std::cout << "\nWrong number, try again\n"; }
				}

				





				
				}
		



		
		
				

















		}
		else if (user_choice == 0) {
			choice_made = true;
			task_ended = true;
		}
		else { std::cout << "\nWrong number, try again\n";
		user_choice = 0;
		task_selection = 0; 
		}
	}
	return 0;
}