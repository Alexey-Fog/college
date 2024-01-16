#include <iostream>
#include <fstream>

using namespace std;

class MyString {
private:
	char* str;
public:
	MyString();

	MyString(const char* s);

	MyString(const MyString &other);

	~MyString();

	void set(const char* s);

	void update(char* path);

	void print() const;
};

int main() {
	setlocale(LC_ALL, "rus");

	printf("Введите имя файла для сохранения: ");
	char myPath[255];

	cin.getline(myPath,255);

	printf("Введите текст: ");
	char myString[255];

	cin.getline(myString,255);

	//cin >> myPath;

	// Default constructor called
	MyString s1;

	// Setting called
	s1.set(myString);

	// Printing called
	s1.print();

	// Updating called
	s1.update(myPath);

	// Printing called
	s1.print();

	/*delete[] myPath;
	delete[] myString;*/
	// Destructor called
	// Destructor called
	// Destructor called
}

MyString::MyString() : str(nullptr) {
	printf("%s\n", "Default constructor called");
}

MyString::MyString(const char * s) {
	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);
	printf("%s\n", "Parametrized constructor called");
}

MyString::MyString(const MyString & other) {
	other.print();
	str = new char[strlen(other.str) + 1];
	strcpy_s(str, strlen(other.str) + 1, other.str);
	printf("%s\n", "Copy constructor called");
}

MyString::~MyString() {
	if (str != nullptr) delete[] str;
	printf("%s\n", "Destructor called");
}

void MyString::set(const char * s) {
	printf("%s\n", "Setting called");
	if (str != nullptr) delete[] str;
	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);
}

void MyString::update(char* path) {
	printf("%s\n", "Updating called");
	if (strlen(str) % 4 == 0) {
		std::ofstream file(path);
		if (file.is_open()) {
			file << str << std::endl;
			const char* newstr = strrchr(str, ' ');
			if (newstr != nullptr && strlen(newstr) > 0) {
				file << newstr << std::endl;
				char* temp = new char[strlen(newstr) + 1];
				strcpy_s(temp, strlen(newstr) + 1, newstr);
				file << temp << std::endl;
				delete[] str;
				str = temp;
			}
			else {
				file << std::endl;
			}
			file.close();
		}
		else {
			std::cout << "Error opening file" << std::endl;
		}
	}
}

void MyString::print() const {
	printf("%s\n", "Printing called");
	if (str != nullptr) {
		printf("%s\n", str);
	}
	else {
		printf("%s\n", "String is empty");
	}
}