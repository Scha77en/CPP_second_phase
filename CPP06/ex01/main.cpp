/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:17:09 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/07 11:46:39 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data data = {1, "Data", 99.99, true};

    std::cout << GREEN "Original data address: " MAGENTA << &data << "size = " << sizeof(data) << std::endl;

    // Serialize the Data object
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << BLUE "Serialized data address: " << raw << "size = " << sizeof(raw) << std::endl;

    // Deserialize the raw value back to a Data object pointer
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << GREEN "Deserialized data address: " MAGENTA << deserializedData << "size = " << sizeof(*deserializedData) << std::endl;

    // Verify the deserialized data
    std::cout << YELLOW "Data ID: " << deserializedData->id << std::endl;
    std::cout << "Data Name: " << deserializedData->name << std::endl;
    std::cout << "Data Value: " << deserializedData->value << std::endl;
    std::cout << "Data State: " << deserializedData->state << std::endl;

    // Ensure the deserialized pointer is equal to the original pointer
    if (deserializedData == &data) {
        std::cout << CYAN "Deserialization successful: pointers match." RESET << std::endl;
    } else {
        std::cout << RED "Deserialization failed: pointers do not match." RESET << std::endl;
    }

    return 0;
}
