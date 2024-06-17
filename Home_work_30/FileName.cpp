#include <iostream>
#include <fstream> 
#include <string>


bool overwrite(std::string path, std::string str);


int main() {
	setlocale(LC_ALL, "Russian");

	// Задача 1.
	std::string path = "file.txt";

	std::fstream fs;
	fs.open(path, std::ios::app | std::ios::in);

	if (fs.is_open()) {
		std::cout << "Файл открыт.\n";

		// Запись данных файла
		std::string str;
		while (str != "end") {
			std::cout << "Введите строку -> ";
			std::getline(std::cin, str);
			fs << str << '\n';
			fs.seekg(0, std::ios::beg);

			if (str == "end") {
				break;
			}
		}
		// Чтение данных из файла
		std::cout << "Содержимое файла:\n";
		char sym;
		while (fs.get(sym)) 
			std::cout << sym;
			std::cout << std::endl;
		
		fs.close();
	}
	else
		std::cout << "Ошибка открытия файла.\n";

	//удаление файла.
	if (remove(path.c_str()) == 0) 
		std::cout << "Файл удален.\n";
	else
		std::cout << "Ошибка удаления файла!\n";

	// Задача 2.
	std::string path2 = "file.txt";
	std::string newstr = "Have a good day :)!";

	if (overwrite(path2, newstr)) {
		std::cout << "Замена прошла успешно.\n";
	}
	else
		std::cout << "Файл не существует.\n";

	return 0;
}

bool overwrite(std::string path, std::string str) {
	static std::ofstream fs;
	
	fs.open(path, std::ios::out);

	if (!fs.is_open())
		return false;

	fs << str << '\n';
	
	fs.close();
	return true;

}