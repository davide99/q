/*=============================================================================
   Copyright (c) 2022 Joel de Guzman. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_Q_FLOAT_CONVERT_HPP_SEPTEMBER_20_2022)
#define CYCFI_Q_FLOAT_CONVERT_HPP_SEPTEMBER_20_2022

#include <cstdint>

namespace cycfi::q
{
   ////////////////////////////////////////////////////////////////////////////
   // Conversion to and from float -1.0 to 1.0 range, from offset binary
   // samples coming from the ADC and going to DACs.
   //
   // Input range checking is not performed.
   ////////////////////////////////////////////////////////////////////////////

   template <typename T, int resolution>
   constexpr float to_float(T s)
   {
      assert(s >= 0 || s < resolution); //Invalid range
      constexpr float half_resolution = resolution / 2.0f;
      return (s / half_resolution) - 1.0f;
   }
}

#endif
