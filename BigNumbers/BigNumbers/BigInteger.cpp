#pragma once
#include"BigInteger.h"

biginteger::BigInteger::BigInteger(const biginteger::BigInteger& number) {
	this->m_Number = new char[number.m_size];
	this->m_size = number.m_size;

	std::copy(number.m_Number, number.m_Number + m_size, this->m_Number);
}

biginteger::BigInteger::BigInteger(std::string value) {
	this->m_size = value.length();
	this->m_Number = new char[this->m_size];
	for (int i = 0; i < this->m_size; ++i)
		this->m_Number[i] = value[i];
}

biginteger::BigInteger::BigInteger(biginteger::BigInteger&& number) {
	this->m_Number = number.m_Number;
	this->m_size = number.m_size;
	//also we can use std::exchange()
	number.m_Number = nullptr;
	number.m_size = 0;
}

biginteger::BigInteger&  biginteger::BigInteger::operator=(const biginteger::BigInteger& number) {
	if (this != &number) {
		if (this->m_size != number.m_size) {
			delete[] this->m_Number;
			this->m_Number = nullptr;
			this->m_size = 0;

			this->m_Number	= new char[number.m_size];
			this->m_size = number.m_size;
		}
		std::copy(number.m_Number, number.m_Number + number.m_size, this->m_Number);
	}

	return *this;
}

biginteger::BigInteger&  biginteger::BigInteger::operator=(biginteger::BigInteger&& number) {
	if (this != &number) {
		delete[] this->m_Number;

		this->m_Number = number.m_Number;
		this->m_size = number.m_size;
		//also we can use std::exchange()
		number.m_Number = nullptr;
		number.m_size = 0;
	}

	return *this;
}

biginteger::BigInteger biginteger::BigInteger::operator+(biginteger::BigInteger& number) {
	int sizeOfResult = std::max(this->m_size, number.m_size) + 1;
	BigInteger result;
	result = BigInteger(sizeOfResult);

	int idx_a = this->m_size - 1;
	int idx_b = number.m_size - 1;
	int idx_r = 0;
	int sum = 0, carry = 0;

	while (idx_a >= 0 && idx_b >= 0) {
		sum = this->GetDigit(idx_a) + number.GetDigit(idx_b) + carry;
		result.SetValue(idx_r, sum % 10);
		carry = sum / 10;

		--idx_a, --idx_b, ++idx_r;
	}

	while (idx_a >= 0) {
		sum = this->m_Number[idx_a] + carry;
		result.m_Number[idx_r] = sum % 10;
		carry = sum / 10;

		--idx_a, ++idx_r;
	}

	while (idx_b >= 0) {
		sum = number.GetDigit(idx_b) + carry;
		result.SetValue(idx_r, sum % 10);
		carry = sum / 10;

		--idx_b, ++idx_r;
	}

	if (carry) {
		result.SetValue(idx_r, carry);
		++idx_r;
	}

	if (idx_r == sizeOfResult)
		result.m_size = sizeOfResult;
	else
		result.m_size = idx_r;

	for (int i = 0; i < result.m_size / 2; ++i)
		std::swap(result.m_Number[i], result.m_Number[result.m_size - i - 1]);

	return result;
}

biginteger::BigInteger biginteger::BigInteger::operator-(biginteger::BigInteger& number) {
	return *this;
}

biginteger::BigInteger::~BigInteger() {

}