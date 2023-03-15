#include <iostream>
#include <windows.h>
#include "IntArray.h"
#include <string>
#include <iomanip>

using namespace std;

#define C 2
#if C==1
//struct Point {
//	int x;
//	int y;
//	friend ostream& operator << (ostream& out, const Point& p) {
//		out << "(" << p.x << ", " << p.y << ")";
//		return out;
//	}
//};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*DynamicArray <int> array{ 7, 6, 4, 7, 9, 1, 2, 3 };
	for (int i = 0; i < 7; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	DynamicArray <Point> point{ Point{1,5}, Point{8,9},Point{0,0} };
	for (int i = 0; i < 3; i++) {
		cout << point[i] << " ";
	}
	cout << endl;*/

	//char ch{ '8' };          // 1 byte
	//char8_t ch8{ u8'8' };    // 1 byte
	//char16_t ch16{ u'8' };   // 2 bytes
	//wchar_t chw{ L'a' };       // 4 bytes

	string name{ "12345" };
	/*char s1 = name.at(0);
	char s2 = name[1];
	cout << s1 << " " << s2;*/

	//char& f = name.front();
	//f = '0';
	//char b = name.back();
	//cout << name.front() << " " << name.back();

	/*const char* pname = name.data();
	cout << pname;*/

	string text = "this is a C++ string";
	/*for (auto it = text.begin(); it < text.end(); it++) {
		cout << *it;
	}
	cout << endl;

	for (auto it = text.rbegin(); it < text.rend(); it++) {
		cout << *it;
	}*/

	/*cout << text << endl;
	cout << text.find ("is") << endl;
	cout << text.find ("is", 4) << endl;
	cout << text.rfind ("is") << endl;
	cout << text.find("is", 4) << endl;
	cout << text.find("strong", 0, 3) << endl;
	cout << text.find("strong") << endl;*/

	/*cout << text << endl;
	cout << text.find_first_of("abc") << endl;
	cout << text.find_last_of("abc") << endl;
	cout << text.find_first_not_of("qerwyerirop[tpkdhsfdaxxv,vbmnvbcvxccx") << endl;*/

	/*string str("next string");
	cout << str << endl;*/
	/*cout << text.assign(str, 3, 4) << endl;
	cout << text.assign(str, 3) << endl;
	cout << text.assign(3, 'a') << endl;*/

	//string str = text;
	//cout << str.erase() << endl;
	//str = text;
	//cout << str.erase(3, 10) << endl;
	//str = text;
	//str.erase(str.begin()+  1);
	//cout << str << endl;
	//str = text;
	//str.erase(str.begin() + 1, str.end() - 3);
	//cout << str << endl;

	//string theStr = "abcdef";
	//string str = text;
	//cout << str.insert(5, theStr) << endl;
	//str = text;
	//cout << str.insert(5, theStr, 2, 3) << endl;
	//str = text;
	//str.insert(str.begin() + 2, 'A');
	//cout << str << endl;

	string theStr = "abcdef";
	/*string str = text;*/
	/*str.replace(10, 3, theStr);
	cout << str << endl;
	str = text;
	str.replace(10, 3, theStr, 2, 2);
	cout << str << endl;
	str = text;
	str.replace(10, 3, "new");
	cout << str << endl;
	str = text;
	str.replace(10, 3, 3, '!');
	cout << str << endl;
	str = text;
	str.replace(str.begin() + 10, str.end() - 7, theStr);
	cout << str << endl;*/

	/*cout << text.substr(5, 9) << endl;
	cout << text.substr(5) << endl;*/

	/*char arr[10]{ 0 };
	text.copy(arr, 8, 5);
	cout << arr;*/

	/*theStr.resize(10, '*');
	cout << theStr;*/

	string str = "abcdef";
	string none;

	/*cout << text.length() << endl;
	cout << text.size() << endl;
	cout << text.capacity() << endl;
	cout << text.max_size() << endl;
	cout << endl;
	cout << str.length() << endl;
	cout << str.capacity() << endl;
	cout << str.max_size() << endl;
	cout << endl;
	cout << none.length() << endl;
	cout << none.capacity() << endl;
	cout << endl;
	text.reserve(8);
	cout << text << endl;
	cout << text.capacity() << endl;
	cout << endl;
	text.shrink_to_fit();
	cout << text.capacity() << endl;*/

	//string text1{ "123" };
	//int num1 = stoi(text1);
	//cout << num1 << endl;

	//text1 = "124.8";
	//float num2 = stof(text1);
	//cout << num2 << endl;

	//string number = to_string(num2) + to_string(num1);
	//cout << number;
}
#elif C == 2

int* findAll(string where, string what, int& count);
int countAll(string where, string what);
template <class T>
void display(T* items, int size);
int* findAllR(string where, string what, int& count);
string toUpr(string text);

int main()
{
	string text{ R"(If you can keep your head when all about you
		Are losing theirsand blaming it on you;
		If you can trust yourself when all men doubt you,
		But make allowance for their doubting too :
		If you can wait and not be tired by waiting,
		Or, being lied about, don't deal in lies,
		Or being hated don't give way to hating,
		And yet don't look too good, nor talk too wise;)" };
	cout << text << endl;

	cout << R"(Search for word " and ")" << endl;
	cout << "case sensitive" << endl;
	int count;
	int* pos = findAll(text, "and", count);
	display(pos, count);
	cout << "case insensitive" << endl;
	pos = findAllR(text, "and", count);
	display(pos, count);
	cout << endl;

}

int* findAll(string where, string what, int& count) {
	count = countAll(where, what);
	if (count == 0) {
		return nullptr;
	}
	int* array = new int[count];
	int pos = -1;
	for (int i = 0; i < count; i++) {
		pos = where.find(what, pos + 1);
		array[i] = pos;
	}
	return array;
}

int countAll(string where, string what) {
	int count = 0;
	int pos = where.find(what);
	while (pos!= string::npos){
		count++;
		pos = where.find(what, pos + 1);
	}
	return count;
}

template <class T>
void display(T* items, int size) {
	for (int i = 0; i < size; i++) {
		cout << setw(8) << items[i];
	}
	cout << endl;
}

int* findAllR(string where, string what, int&count) {
	return findAll(toUpr(where), toUpr(what), count);
}

string toUpr(string text) {
	for (int i = 0; i < text.size(); i++) {
		text[i] = toupper(text[i]);
	}
	return text;
}

#endif