#include <iostream>
#include <windows.h>
#include <vector>
#include <random>
#include <string>
#include <ctime>
#include <cmath>



void text_visualise(std::string text, int avg_speed) {
	for (int i = 0; i < text.length(); i++) {
		std::cout << text[i];
		if (text[i] == ',') {
			Sleep(700);
		}
		else if (text[i] == '.') {
			Sleep(1500);
		}
		else { Sleep(avg_speed); }
	}
}





int main(){

	bool task_selected = false;

	int task_to_run = -1, user_choice = -1, input_value = -1;




	std::setlocale(LC_ALL, "Russian");
	srand(time(0));
	std::string text_welcome = "Guten abent, what task you would like to run?",
		error_wrong_num = "You choose the wrong number, try again",
		choose_tasks_text = "\n\nSelect the task:\n1 - Luck\n2 - Change places\n3 - Max value\n0 - Terminate process",
		task_one_introdution = "Enter the six digit value",
		task_two_introdution = "Enter the four digit value",
		task_three_introdution = "Enter seven values, separated by a enter\n\n",
		task_answer = "";








	std::cout << "Hello world\n\n\n";


	text_visualise(text_welcome, 25);


	while (true) {

		text_visualise(choose_tasks_text, 25);
		std::cout << "\n>>> ";
		std::cin >> task_to_run;

		if (task_to_run > 0 && task_to_run <= 3) {

			if (task_to_run == 1){
				std::string value;

				bool num_is_correct = false;

				int values[6], blank = 0;




				//Forgive me, please, i did this abomination (1'st task), when i was young and stupid

				while (num_is_correct == false) {
					text_visualise(task_one_introdution, 25);
					while (value.length() < 6 || value.length() > 6) {
						std::cout << ">>> ";
						std::cin >> value;
						if (value.length() < 6 || value.length() > 6) { text_visualise("Error has occured, looks like you entered the wrong value, try again", 15); }
					}
					for (int i = 0; i < 6; i++) {
						if (value[i] == '1') { values[i] = 1; }
						else if (value[i] == '2') { values[i] = 2; }
						else if (value[i] == '3') { values[i] = 3; }
						else if (value[i] == '4') { values[i] = 4; }
						else if (value[i] == '5') { values[i] = 5; }
						else if (value[i] == '6') { values[i] = 6; }
						else if (value[i] == '7') { values[i] = 7; }
						else if (value[i] == '8') { values[i] = 8; }
						else if (value[i] == '9') { values[i] = 9; }
						else if (value[i] == '0') { values[i] = 0; blank++; }
					}
					if (blank == 6) { num_is_correct = false; }
					else if (blank < 6) { num_is_correct = true; }
				}
				std::cout << std::endl;
				if ((values[0] + values[1] + values[2]) == (values[3] + values[4] + values[5])) {
					task_answer = "It is the lucky value!";
				}
				else{ task_answer = "It is NOT the lucky one, i'm sorry."; }
				text_visualise(task_answer, 25);
			}



			else if (task_to_run == 2) {
				text_visualise(task_two_introdution, 25);
				bool selected = false;

				float num1 = 0, num2 = 0;


				while (selected == false) {
					std::cout << "\n>>> ";
					std::cin >> input_value;
					if (input_value / 1000 >= 1 and input_value / 1000 < 10) {
						selected = true;
					}
					else { text_visualise("Error has occured, looks like you entered the wrong value, try again", 15); }
				}
				num1 = (input_value - input_value % 100) / 100;
				num2 = input_value % 100;
				std::cout << num2;
				std::cout << num1;

				




			}
			else if (task_to_run == 3) {
				bool right_value = false;
				int num_array[7]{}, max_value;
				text_visualise(task_three_introdution, 15);
				for (int i = 0; i < 7; i++) {
					std::cout << i+1 << "/7 - >>> ";
					std::cin >> num_array[i];
				}
				max_value = num_array[0];
				for (int i = 0; i < 8; i++) {
					if (num_array[i] > max_value) {
						max_value = num_array[i];
					}
				}
				text_visualise("\n\nMax value is ", 15);
				std::cout << max_value;


			}


		}
		else if (task_to_run == 0) {
			return 0;
		}
		else {
			text_visualise(error_wrong_num, 25);
		}


	}
	return 0;
}
