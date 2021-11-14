#include <iostream>
#include <ctime>
#include <random>
using namespace std;

#define BOYUT 10000

int main()
{
	void yerdegis(int, int);
	mt19937 generator;
	generator.seed(time(0));
	uniform_int_distribution<uint32_t> rndm(0, 9999999999);
	srand(time(0));
	int arr[BOYUT];
	int temp;
	const clock_t baslangic_zamani = clock();

	for (int i = 0; i < BOYUT; i++) {
		arr[i] = rndm(generator);
	}
	float a = float(clock() - baslangic_zamani);
	//cout << BOYUT << " sayinin rastgele uretimi " << a / CLOCKS_PER_SEC << " sn surdu" << endl;
	cout << BOYUT << " sayinin rastgele uretimi " << a << " ms surdu" << endl;

	//Insertion Sort baslangici

	const clock_t insertion_baslangic = clock();

	for (int i = 1; i < BOYUT; i++) {
		for (int j = i; j >= 0; j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			else break;
		}
	}

	float insertion_zamani = float(clock() - insertion_baslangic);;
	cout << "Insertion Sort calisma suresi: " << insertion_zamani << " ms." << endl;

	//Selection Sort baslangici

	const clock_t selection_baslangic = clock();

	for (int i = 0; i < BOYUT; i++) {
		int min = i;
		for (int j = i + 1; j < BOYUT; j++) {
			if (arr[j] < arr[min]) {
				min = j;
				temp = arr[min];
				arr[min] = arr[i];
				arr[i] = temp;
			}
		}

	}

	float selection_zamani = float(clock() - selection_baslangic);;
	cout << "Selection Sort calisma suresi: " << selection_zamani << " ms." << endl;

	//Bubble Sort baslangici

	const clock_t bubble_baslangic = clock();

	for (int i = BOYUT; i > 1; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}


	float bubble_zamani = float(clock() - bubble_baslangic);;
	cout << "Bubble Sort calisma suresi: " << bubble_zamani << " ms." << endl;

	system("pause");
	return 0;
}

