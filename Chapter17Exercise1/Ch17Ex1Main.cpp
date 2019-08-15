#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdlib>

using namespace std;

void get_monthly_weights(double weights[], const string months[], int num_months);
double get_total(double * weights, int num_months);

int main()
{
	const int num_months = 12;
	const string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	cout << "Welcome to the Weight Tracker program!\n\n"
		<< "Please enter your weight at the beginning of each month:\n";

	double weights[num_months]{ 0.0 };

	get_monthly_weights(weights, months, num_months);
	for (size_t i = 0; i < num_months; ++i) {
		cout << weights[i] << " ";
	}
	cout << endl;

	double total = get_total(weights, num_months);
	cout << "total = " << total << endl;

	cout << "Average weight: " << total / num_months << endl;
	cout << "Minimum weight: " << *min_element(weights, weights + num_months) << endl;
	cout << "Maximum weight: " << *max_element(weights, weights + num_months) << endl;

	system("pause");
	return 0;
}

void get_monthly_weights(double weights[], const string months[], int num_months) {
	if (weights != nullptr && months != nullptr) {
		for (size_t i = 0; i < num_months; ++i) {
			cout << months[i] << ": ";
			cin >> weights[i];
		}
	}
}

double get_total(double * weights, int num_months) {
	//if (weights) {
	//	double total{ 0.0 };
	//	for (size_t i = 0; i < num_months; ++i) {
	//		total += weights[i];
	//	}
	if(weights != nullptr){
		return accumulate(weights, weights + num_months, 0.0);
		//return total;
	}
	return 0.0;
}