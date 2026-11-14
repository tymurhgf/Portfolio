#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class String {
private:
	shared_ptr<char[]> data;
	int size;
public:
	String() : size(80) {
		data = shared_ptr<char[]>(new char[size]);
		data[0] = '\0'; //Порожній
	}
	String(int size) {
		this->size = size;
		data = shared_ptr<char[]>(new char[size]);
		if (size > 0) data[0] = '\0';
	}
	String(const char* str) {
		int len = 0;
		while (str[len] != '\0') {
			len++;
		}
		this->size = len;
		data = shared_ptr<char[]>(new char[size + 1]);
		for (int i = 0; i < size; ++i) {
			data[i] = str[i];
		}
		data[size] = '\0';
	}
	String(const String& other) {
		this->size = other.size;
		this->data = shared_ptr<char[]>(new char[size + 1]);
		for (int i = 0; i <= size; ++i) {
			this->data[i] = other.data[i];
		}
	}
	String(String&& other) noexcept {
		this->size = other.size;
		this->data = other.data;
		other.size = 0;
	}
	~String() = default;
	String& operator=(const String& other) {
		if (&other == this) return *this;
		this->size = other.size;
		data = shared_ptr<char[]>(new char[size + 1]);
		for (int i = 0; i <= size; ++i) {
			this->data[i] = other.data[i];
		}
		return *this;
	}
	String& operator=(String&& other) noexcept {
		if (&other == this) return *this;
		this->size = other.size;
		this->data = other.data;
		other.size = 0;
		return *this;
	}
	inline int getSize() const {
		return size;
	}
	inline int getFSize() const {
		if (data != nullptr) {
			return size + 1;
		}
		else {
			return 0;
		}
	}
	inline char getData(int i) const {
		return data[i];
	}
	inline const char* getStr() const {
		return data.get();
	}
	void setCh(int i, char c) {
		if (i >= 0 && i < size) {
			data[i] = c;
		}
	}
	void setStr(const char* str) {
		int len = 0;
		while (str[len] != '\0') {
			len++;
		}
		this->size = len;
		data = shared_ptr<char[]>(new char[size + 1]);
		for (int i = 0; i < size; ++i) {
			data[i] = str[i];
		}
		data[size] = '\0';
	}
	void Show() const {
		cout << data.get() << "\n";
	}
};