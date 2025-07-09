/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:19:16 by candrese          #+#    #+#             */
/*   Updated: 2025/07/09 22:50:14 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data datastruct;
	datastruct.nb = 42;
	datastruct.name = "Chris";
	
	Data* ptr = &datastruct;
	
	std::cout << "\ndatastruct data at: " << ptr << std::endl;
	std::cout << "nb: " << datastruct.nb << ", name: " << datastruct.name << std::endl;
	
	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "Serialized: " << raw << std::endl;
	
	Data* newPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized: " << newPtr << std::endl;
	
	std::cout << "\n------ check if circle worked" << std::endl;
	if (ptr == newPtr) {
		std::cout << "Success! Same pointer returned." << std::endl;
		std::cout << "Data via new pointer - nb: " << newPtr->nb 
					<< ", name: " << newPtr->name << "\n" << std::endl;
	} else {
		std::cout << "Error: Different pointer!\n" << std::endl;
		return 1;
	}

	return 0;
}
