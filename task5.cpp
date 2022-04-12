#include <iostream>
using namespace std;
double* srznak(double** mat, int height, int width) {
	int s;
	double* mas = new double[height];
	for (int i = 0; i < height; i++) {
		s = 0;
		for (int j = 0; j < width; j++) {
			s += mat[i][j];
		}
		mas[i] = s / double(width);
	}
	return mas;
}
int main() {
	int height, widht;
	cin >> height >> widht;
	double** mat = new double* [height];
	for (int i = 0; i < height; i++) {
		mat[i] = new double[widht];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < widht; j++) {
			cin >> mat[i][j];
		}
	}
	double* mas = srznak(mat, height, widht);
	for (int i = 0; i < height; i++) {
		cout << mas[i] << " ";
	}
}
