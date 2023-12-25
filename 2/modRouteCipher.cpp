#include "modRouteCipher.h"
#include <sstream>
#include <stdexcept>
#include <ctype.h>
#include <stdio.h>


modRouteCipher::modRouteCipher(const int& skey, const std::wstring& text)
{
	int key = getValidKey(skey, text);
}

std::wstring modRouteCipher::encrypt(const std::wstring& open_text, const int& key){ 
	std::wstring open_text_1 = getValidOpenText(open_text);
	std::wstring cypher_text;
	int key_1 = key;
	for(int i = 0; i < key;i++){ //Столбцы
		for(int x = 0; x<=int (open_text_1.size()/key);x++){ //Строки
			if (key_1 >int (open_text.size())){
				break;
			}
			cypher_text.push_back(open_text_1[key_1-1]);
			key_1+=key;
		}
		key_1=key-i-1;
	}
	return cypher_text;
}


std::wstring modRouteCipher::decrypt(const std::wstring& cypher_text, const int& key){ 
	std::wstring decrypted_text = getValidCipherText(cypher_text);
	int key_1 = key;
	int c = 0;
	for(int i = 0; i < key;i++){ //Столбцы
		for(int x = 0; x<=int (cypher_text.size()/key);x++){ //Строки
			if (key_1 >int (cypher_text.size())){
				break;
			}
			decrypted_text[key_1-1]=cypher_text[c];
			c+=1;
			key_1 += key;
		}
		key_1=key-i -1;
	}
	return decrypted_text;
}

inline int modRouteCipher::getValidKey(const int& key, const std::wstring& text)
{ 
	std::wstring s = std::to_wstring(key);
	for (auto c:s) {
		if (s.empty())
			throw cipher_error("Empty key");
		if (isalpha(c))
			throw cipher_error(("Invalid key "));
		if (c<0)
			throw cipher_error("Ключ должен быть положительным");
		if (key>text.size())
			throw cipher_error("Слишком большое значение ключа");
	}
	return key;
}

inline std::wstring modRouteCipher::getValidOpenText(const std::wstring & s)
{ 
	if (s.empty())
		throw cipher_error("Empty open text");
	return s;
}

inline std::wstring modRouteCipher::getValidCipherText(const std::wstring & s)
{ 
	if (s.empty())
		throw cipher_error("Empty cipher text");
	return s;
}
