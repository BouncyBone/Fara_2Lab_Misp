#include <iostream>
#include <locale>
#include "modAlphaCipher.h"
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{ 
	try {
		wstring cipherText;
		wstring decryptedText;
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text); // зашифровывание
		if (destructCipherText) // надо "портить"?
			cipherText.front() = tolower(cipherText.front()); // "портим"
		decryptedText = cipher.decrypt(cipherText);
		wcout<<L"key="<<key<<endl;
		wcout<<Text<<endl;
		wcout<<cipherText<<endl;
		wcout<<decryptedText<<endl;
	} 
	catch (const cipher_error & e) {
		wcerr<<"Error: "<<e.what()<<endl;
	}
}
int main(int argc, char **argv)
{ 
	locale loc("ru_RU.UTF-8");
    locale::global(loc);
	check(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",L"Simple");
	check(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",L"");
	check(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",L"ABCD123");
	check(L"The Quick Brown Fox Jumps Over The Lazy Dog",L"SUPER");
	check(L"123",L"ABCD");
	check(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",L"TOPSECRET",true);
return 0;
}