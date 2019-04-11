#pragma once
#include<iostream>
#include<string>
#include<algorithm>
//RAII - Resource Acquisition Is Initialization
//When implementing RAII, keep in mind the rule of 5: copy-ctor, move-ctor, copy-assignment, move-assignment, dtor

namespace biginteger {
	class BigInteger {
	public:
		BigInteger() : m_Number(nullptr), m_size (0) {}
		BigInteger(int size) : m_Number(new char[size]), m_size(size){}
		BigInteger(std::string value);
		BigInteger(const BigInteger& number); //copy-ctor
		BigInteger(BigInteger&& number); //move-ctor

		BigInteger&  operator = (const BigInteger& number); //copy-assignment 
		BigInteger&  operator = (BigInteger&& number); //move-assignment 

		BigInteger operator + (BigInteger& number);
		BigInteger operator - (BigInteger& number);

		int GetSize() const {
			return m_size;
		}

		int GetDigit(int& idx) const {
			return static_cast<int>(m_Number[idx] - '0');
		}

		void SetValue(int& idx, int value) const {
			this->m_Number[idx] = '0' + value;
		}

		friend std::ostream& operator<< (std::ostream& out, const biginteger::BigInteger& number)
		{
			int size = number.GetSize();

			for (int i = 0; i < size; ++i) {
				out << number.GetDigit(i);
			}
			out << std::endl;
			return out;
		}

		friend std::istream& operator >> (std::istream& in, biginteger::BigInteger& number) {
			std::string value;

			getline(in, value);
			number = biginteger::BigInteger(value);

			return in;
		}

		~BigInteger(); //dtor
	private:
		char * m_Number;
		int m_size;
	};
}