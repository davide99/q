/*=============================================================================
   Copyright (c) 2014-2023 Joel de Guzman. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_Q_CONCEPTS_HPP_MAY_12_2023)
#define CYCFI_Q_CONCEPTS_HPP_MAY_12_2023

#include <concepts>
#include <iterator>

namespace cycfi::q::concepts
{
   template <typename T>
   concept Arithmetic = std::integral<T> || std::floating_point<T>;
}

#endif

