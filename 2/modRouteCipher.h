#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
#include <locale>

class modRouteCipher{
private:
	std::vector<int> key;
	int getValidKey(const int& s, const std::wstring& text);
	std::wstring getValidCipherText(const std::wstring & s);
	std::wstring getValidOpenText(const std::wstring & s);
public:
	modRouteCipher(const int& skey, const std::wstring& text); //конструктор для установки ключа
	std::wstring encrypt(const std::wstring& open_text, const int& key); //зашифрование
	std::wstring decrypt(const std::wstring& cypher_text, const int& key);//расшифрование
};
class cipher_error: public std::invalid_argument {
public:
	explicit cipher_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};