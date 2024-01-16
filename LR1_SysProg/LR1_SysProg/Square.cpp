#include <cmath>

class Square {
private:
	double side = 0;

public:
	//Get � Set side
	double getSide() {
		return side;
	}
	bool setSide(double a) {
		if (a <= 0.0) return false;
		side = a;
		return true;
	}

	// ����� ��� ����������/���������� ������� �� ������������ �������
	void resize(double percent) {
		if (side <= 0) throw ("� �������� ����������� ������ �������!");
		side *= (1 + percent / 100);
	}

	// ����� ��� ���������� ���������
	double calculateP() {
		if (side <= 0) throw ("� �������� ����������� ������ �������!");
		return side * 4;
	}

	// ����� ��� ���������� �������
	double calculateS() {
		if (side <= 0) throw ("� �������� ����������� ������ �������!");
		return side * side;
	}

	// ����� ��� ���������� ���������
	double calculateDiagonal() {
		if (side <= 0) throw ("� �������� ����������� ������ �������!");
		return side * sqrt(2);
	}
};