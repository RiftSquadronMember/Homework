#include <iostream>
#include <windows.h>
#include <vector>
#include <random>
#include <string>
#include <ctime>
#include <cmath>

int main(){
	const int arr_row = 3, arr_col = 3;
	float arr_example[arr_row][arr_col], multiplier = 2, adder = 1;
	int task_choice = -1;

	do { 
		std::cout << "Enter the task number:\n1 - Array multiply\n2 - Array add\n\n=-> "; 
		std::cin >> task_choice;
		system("cls");
	} while (task_choice < 1 || task_choice > 2);

	if (task_choice == 1) {
		std::cout << "Enter the first value of the list\n[it must be int or float value]: ";
		std::cin >> arr_example[0][0];
		for (int i = 0; i < arr_row; i++) {
			for (int k = 0; k < arr_col; k++) {
				if (i > 0 || k > 0) { arr_example[i][k] = arr_example[i][k - 1] * multiplier; }
			}
			if(i !=0){
				arr_example[i][0] = arr_example[i - 1][arr_col - 1] * multiplier;
			}
			
		}
		for (int i = 0; i < arr_row; i++) {
			for (int k = 0; k < arr_col; k++) {
				std::cout <<"\t" << arr_example[i][k];
				/*std::cout << "[ " << i << " : " << k << " ] ";*/
			}
			std::cout << "\n";
		}
	}

	else if (task_choice == 2) {
		std::cout << "Enter the first value of the list\n[it must be int or float value]: ";
		std::cin >> arr_example[0][0];
		for (int i = 0; i < arr_row; i++) {
			for (int k = 0; k < arr_col; k++) {
				if (i > 0 || k > 0) { arr_example[i][k] = arr_example[i][k - 1] + adder; }
			}
			if (i != 0) {
				arr_example[i][0] = arr_example[i - 1][arr_col - 1] + adder;
			}

		}
		for (int i = 0; i < arr_row; i++) {
			for (int k = 0; k < arr_col; k++) {
				std::cout << "\t" << arr_example[i][k];
				/*std::cout << "[ " << i << " : " << k << " ] ";*/
			}
			std::cout << "\n";
		}
	}
	return 0;
}
