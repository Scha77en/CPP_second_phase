/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:48:57 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/28 15:18:51 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int integer)
{
    typename T::iterator it = std::find(container.begin(), container.end(), integer);
    if (it != container.end())
        return it;
    else
        throw std::runtime_error("No matching value was found in the container");
}

#endif
