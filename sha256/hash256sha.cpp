#include <cryptopp/cryptlib.h> //главный файл crypto++ для базовых функций
#include <cryptopp/hex.h> // конвертация
#include <cryptopp/files.h> // работа с файлами
#include <cryptopp/sha.h> // алгоритмы хеширования 
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string read_file(string way)
{
    ifstream file(way); //открытие файла
    string line; //хранение строки
    string entry; //вс е содержимое 
    if (file.peek() == EOF) {
        throw runtime_error("файл пустой"); //если файл пуст то ошибка
    }
    while (getline(file, line)) {
        entry += line; //чтение 
    }
    file.close(); //закрытие файла 
    return entry;
}

int main ()
{
    CryptoPP::SHA256 hash; // создание хэш-объекта
    string path = "hash.txt"; // путь до файла
    string FileContent; 
    try {
        FileContent = read_file(path);
    } catch (const runtime_error& e) { //если при чтении ошибка, то пишем об этом
        cout << "ошибка: " << e.what() << endl;
        return 1;
    }

    cout << "содержимое файла: " << FileContent << endl; // содержимое файла

    CryptoPP::FileSource(path.c_str(), true, new CryptoPP::HashFilter(hash, new CryptoPP::HexEncoder(new CryptoPP::FileSink(cout), true))); 
    //чтение из файла в двоичном режиме, фильтр для вычисление хеш значения, преобразование даных в 16-ый формат и вывод 
    cout <<"\n"<< endl;
    return 0;
}
