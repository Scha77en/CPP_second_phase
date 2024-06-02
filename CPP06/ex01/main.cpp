/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:17:09 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/31 20:20:58 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data data = {1, "Test Data", 99.99};

    // Serialize the Data object
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data address: " << raw << std::endl;

    // Deserialize the raw value back to a Data object pointer
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data address: " << deserializedData << std::endl;

    // Verify the deserialized data
    std::cout << "Data ID: " << deserializedData->id << std::endl;
    std::cout << "Data Name: " << deserializedData->name << std::endl;
    std::cout << "Data Value: " << deserializedData->value << std::endl;

    // Ensure the deserialized pointer is equal to the original pointer
    if (deserializedData == &data) {
        std::cout << "Deserialization successful: pointers match." << std::endl;
    } else {
        std::cout << "Deserialization failed: pointers do not match." << std::endl;
    }

    return 0;
}
