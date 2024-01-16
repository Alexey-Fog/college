#include <cmath>

class Square {
private:
	double side = 0;

public:
	//Get и Set side
	double getSide() {
		return side;
	}
	bool setSide(double a) {
		if (a <= 0.0) return false;
		side = a;
		return true;
	}

	// Метод для увеличения/уменьшения размера на определенный процент
	void resize(double percent) {
		if (side <= 0) throw ("У квадрата отсутствует размер стороны!");
		side *= (1 + percent / 100);
	}

	// Метод для вычисления периметра
	double calculateP() {
		if (side <= 0) throw ("У квадрата отсутствует размер стороны!");
		return side * 4;
	}

	// Метод для вычисления площади
	double calculateS() {
		if (side <= 0) throw ("У квадрата отсутствует размер стороны!");
		return side * side;
	}

	// Метод для вычисления диагонали
	double calculateDiagonal() {
		if (side <= 0) throw ("У квадрата отсутствует размер стороны!");
		return side * sqrt(2);
	}
};