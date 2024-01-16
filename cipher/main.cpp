#include "AES.h" //для работы с алгоритмом AES

int main ()
{
    bool is_running = true;
    string operation_mode;
    string input_file, output_file, iv_file, password;
    cout << "encode - шифрование с использованием алгоритма AES" << endl;
    cout << "decode- расшифрование с использованием алгоритма AES" << endl;
    do {
        cout << "выберите режим работы: encode/decode -> ";
        cin >> operation_mode;
        if (operation_mode == "encode") {
            cout << "файл для обработки(путь): ";
            cin >> input_file;
            cout << "файл для сохранения результата(путь): ";
            cin >> output_file;
            cout << "пароль: ";
            cin >> password;
            try {
                AlgorithmAES enc(input_file, output_file, password); //создание обьекта клсса AlgorithmAES с параметрами
                enc.encodeAES(enc); //метод для шифрования файла
            }  catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl; // ошибка если исключение типа CryptoPP::Exception
            }
        }
        if (operation_mode == "decode") {
            cout << "файл для обработки(путь): ";
            cin >> input_file;
            cout << "fайл для сохранения результата(путь): ";
            cin >> output_file;
            cout << "файл с вектором инициализации(путь): ";
            cin >> iv_file;
            cout << "пароль: ";
            cin >> password;
            try {
                AlgorithmAES dec(input_file, output_file, password, iv_file);
                dec.decodeAES(dec);
            } catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            } catch (const string & error) {
                cerr << error << endl;
            }
        }
        if (operation_mode == "выйти") {
            is_running = false;
            break;
        }
    } while (is_running != false);

    return 0;
}
