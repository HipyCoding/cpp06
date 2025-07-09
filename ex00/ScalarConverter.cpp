/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 05:50:03 by candrese          #+#    #+#             */
/*   Updated: 2025/07/09 21:50:21 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

typedef enum {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
} InputType;

bool isChar(std::string input) {
	return input.length() == 1 && std::isprint(input[0]);
}

bool isInt(std::string input) {
	if (input[0] == '-' || input[0] == '+') {
		input = input.substr(1);
	}
	
	for (char c : input) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return !input.empty();
}

bool isFloat(std::string input) {
	if (input == "+inff" || input == "-inff" || input == "nanf") {
		return true;
	}
	if (input.back() != 'f' || input.find('.') == std::string::npos) {
		return false;
	}
	if (input[0] == '.') {
		return false;
	}
	std::string numPart = input.substr(0, input.length() - 1);
	if (numPart[0] == '-' || numPart[0] == '+') {
		numPart = numPart.substr(1);
	}
	size_t dotPos = numPart.find('.');
	if (dotPos == std::string::npos) {
		return false;
	}
	std::string beforeDot = numPart.substr(0, dotPos);
	std::string afterDot = numPart.substr(dotPos + 1);
	for (char c : beforeDot) {
		if (!std::isdigit(c)) return false;
	}
	for (char c : afterDot) {
		if (!std::isdigit(c)) return false;
	}
	return !beforeDot.empty() && !afterDot.empty();
}

bool isDouble(std::string input) {
	if (input == "+inf" || input == "-inf" || input == "nan") {
		return true;
	}

	size_t dotPos = input.find('.');
	if (dotPos == std::string::npos || input.back() == '.' || input[0] == '.') {
		return false;
	}

	std::string numPart = input;
	if (numPart[0] == '-' || numPart[0] == '+') {
		numPart = numPart.substr(1);
		dotPos--;
	}

	std::string beforeDot = numPart.substr(0, dotPos);
	std::string afterDot = numPart.substr(dotPos + 1);
	for (char c : beforeDot) {
		if (!std::isdigit(c)) return false;
	}
	for (char c : afterDot) {
		if (!std::isdigit(c)) return false;
	}
	return !beforeDot.empty() && !afterDot.empty();
}

InputType getInputType(std::string input) {
	if (isInt(input)) return INT;
	if (isFloat(input)) return FLOAT;
	if (isDouble(input)) return DOUBLE;
	if (isChar(input)) return CHAR;
	return INVALID;
}

void handleCharInput(std::string input) {
	char ch = input[0];

	std::cout << "char: " << ch << std::endl;
	std::cout << "int: " << static_cast<int>(ch) << std::endl;
	std::cout << "float: " << static_cast<float>(ch) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(ch) << std::endl;
}

void handleIntInput(std::string input) {
	try {
		int num = std::stoi(input);
		
		if (num < 0 || num > 127) {
			std::cout << "char: impossible" << std::endl;
		} else if (num < 32 || num == 127) {
			std::cout << "char: Non displayable" << std::endl;
		} else {
			std::cout << "char: " << static_cast<char>(num) << std::endl;
		}
		
		std::cout << "int: " << num << std::endl;
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "literal: " << input << ", stoi: " << e.what() << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void handleFloatInput(std::string input) {
	try
	{
		float num = std::stof(input);
		
		if (input == "+inff" || input == "-inff" || input == "nanf") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		} else {
			if (num < 0 || num > 127) {
				std::cout << "char: impossible" << std::endl;
			} else if (num < 32 || num == 127) {
				std::cout << "char: Non displayable" << std::endl;
			} else {
				std::cout << "char: " << static_cast<char>(num) << std::endl;
			}
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		}
		
		std::cout << "float: " << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "literal: " << input << ", stof: " << e.what() << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void handleDoubleInput(std::string input) {
	try {
		double num = std::stod(input);
		
		if (input == "+inf" || input == "-inf" || input == "nan") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		} else {
			if (num < 0 || num > 127) {
				std::cout << "char: impossible" << std::endl;
			} else if (num < 32 || num == 127) {
				std::cout << "char: Non displayable" << std::endl;
			} else {
				std::cout << "char: " << static_cast<char>(num) << std::endl;
			}
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		}
		
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << num << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "literal: " << input << ", stod: " << e.what() << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void setupOutput() {
	std::cout << std::fixed << std::setprecision(2);
}

void ScalarConverter::convert(std::string input) {
	if (input.empty()) {
		std::cerr << "Invalid input" << std::endl;
		return;
	}
	
	setupOutput();
	
	InputType type = getInputType(input);
	switch (type) {
		case CHAR:
			handleCharInput(input);
			break;
		case INT:
			handleIntInput(input);
			break;
		case FLOAT:
			handleFloatInput(input);
			break;
		case DOUBLE:
			handleDoubleInput(input);
			break;
		case INVALID:
			std::cerr << "Invalid input" << std::endl;
			break;
	}
}
