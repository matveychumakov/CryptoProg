#pragma once
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h> //запись в файлы
#include <cryptopp/sha.h> // алгоритмы хэширования
#include <cryptopp/aes.h> // алгоритм AES
#include <cryptopp/base64.h> // код-ие и дек-ие с помощью base64
#include <cryptopp/pwdbased.h> // алгоритмы на основе паролей
#include <cryptopp/filters.h> // обработки данных
#include <cryptopp/osrng.h> //генераторы случайных чисел
#include "cryptopp/modes.h" //виды шифров
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace CryptoPP;

class AlgorithmAES
{
private:
  string filePath_in; //входной файл
  string filePath_out; // выходной файл
  string psw; // пароль
  string filePath_Iv; //вектор 
  string salt = "knxeomfpwslsqwer"; //соль
public:
  AlgorithmAES() = delete; //объекты класса не создадутся без аргументов
  AlgorithmAES(const string& filePath_in, const string& filePath_out, const string& Pass); //конструктор для входных/выходных путей, пароля
  AlgorithmAES(const string& filePath_in, const string& filePath_out, const string& Pass, const string & iv); //расширенный конструктор, уже с вектором инициализации
  void encodeAES (AlgorithmAES enc); //метод для шифрования 
  void decodeAES (AlgorithmAES dec); // для расшифрования
};
