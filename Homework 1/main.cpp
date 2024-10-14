#include <iostream>
#include <cmath>
#include <windows.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>

const int num_array_size = 20;

void random_values(int num_array[num_array_size]) {
	for (int i = 0; i < num_array_size; i++) {
		num_array[i] = rand() % 27 - 8;
	}}


int min_max_search(int num_array[num_array_size], char type_of) {
	int min = num_array[0], max = num_array[0];
	for (int i = 0; i < num_array_size; i++) {
		if (num_array[i] > max) { max = num_array[i]; }
		if (num_array[i] < min) { min = num_array[i]; }
	}
	if (type_of == '<') { return min; }
	if (type_of == '>') { return max; }
}

void array_out(int num_array[num_array_size]) {
	for (int i = 0; i < num_array_size; i++) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < num_array_size; i++) {
		std::cout << num_array[i] << "\t";
		 
	}
}





int main() {
	srand(time(0));
	int num_array[num_array_size]{}, choice = 0;
	do {
		std::cout << "Enter the number of task\n1 - Random values\n2 - Sum of elements\n3 - Gain\n\n>>> ";
		std::cin >> choice;
		system("cls");
	} while (choice < 1 || choice > 3);


	if (choice == 1) {
		random_values(num_array);
		array_out(num_array);
		std::cout << "\n\n minimum: " << min_max_search(num_array, '<');
		std::cout << "\n maximum: " << min_max_search(num_array, '>');
		std::cout << "\n\n\n";}
	else if (choice == 2) {
		int min_value, max_value, precious_value, answer = 0;

		do {
			random_values(num_array);
			array_out(num_array);
			std::cout << "\n\nFrom id ";
			std::cin >> min_value;
			system("cls");
		} while (min_value < 0 || min_value > num_array_size);
		do {
		array_out(num_array);
		std::cout <<"\n\nFrom id " << min_value << " to id ";
		std::cin >> max_value;
		system("cls");
		} while (max_value < 0||max_value > num_array_size || max_value <= min_value);
		array_out(num_array);
		std::cout << "\n\nFrom id " << min_value << " to id "<< max_value <<"\nAND less then ";
		std::cin >> precious_value;

		for (int i = 0; i < num_array_size; i++) {
			if (i > min_value && i < max_value && num_array[i] < precious_value) {
				answer += num_array[i];}}
		std::cout << "\nSum of all values, that's less then "<< precious_value <<": " << answer << "\n\n";}

	else if (choice == 3) { 
		int all_year_gain[12]{}, min_id, max_id, min_gain = 0, max_gain = 0, min_gain_id = 0, max_gain_id = 0;
		system("cls");
		for (int i = 0; i < 12; i++) {
			for (int k = 0; k < i; k++) {
				std::cout << k+1 <<"\t";
			}
			std::cout << std::endl;
			for (int k = 0; k < i; k++) {
				std::cout << all_year_gain[k] << "\t";
			}
			std::cout<< "\nEnter the gain of the " << i+1 << " month\n>>> ";
			std::cin >> all_year_gain[i];
			system("cls");
		}
		
		do {
			for (int k = 0; k < 12; k++) {
				std::cout << k + 1 << "\t";
			}
			std::cout << std::endl;
			for (int k = 0; k < 12; k++) {
				std::cout << all_year_gain[k] << "\t";
			}
			std::cout << "\nNow enter range from one month to another,\nto calculate total impact\n>>> ";
			std::cout << "From month ";
			std::cin >> min_id;
			system("cls");
		} while (min_id < 1 || min_id > 12);
		do {
			for (int k = 0; k < 12; k++) {
				std::cout << k + 1 << "\t";
			}
			std::cout << std::endl;
			for (int k = 0; k < 12; k++) {
				std::cout << all_year_gain[k] << "\t";
			}
			std::cout << "\nNow enter range from one month to another,\nto calculate total impact\n>>> ";
			std::cout << "From month " << min_id << " to month ";
			std::cin >> max_id;
			system("cls");
		} while (max_id < 1 || max_id > 12 || max_id <= min_id);
		min_gain = all_year_gain[0];
		max_gain = all_year_gain[0];
	

		for (int i = min_id - 1; i < max_id - 1; i++) {
			if (all_year_gain[i] < min_gain) {
				min_gain = all_year_gain[i];
				min_gain_id = i;
			}
			if (all_year_gain[i] > max_gain) {
				max_gain = all_year_gain[i];
				max_gain_id = i;}}

		

		for (int k = 0; k < 12; k++) {
			std::cout << k + 1 << "\t";
		}
		std::cout << std::endl;
		for (int k = 0; k < 12; k++) {
			std::cout << all_year_gain[k] << "\t";
		}
		std::cout << "\n\nMax gain were in " << max_gain_id + 1 << " month, it was, in total "<< max_gain
			<<"\nMin gain were in " << min_gain_id + 1 << " month, it was, in total " << min_gain<< "\n\n\n\n"; }
	return 0;
}
