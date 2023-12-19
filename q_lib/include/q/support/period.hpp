/*=============================================================================
   Copyright (c) 2014-2023 Joel de Guzman. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_Q_PERIOD_HPP_FEBRUARY_21_2018)
#define CYCFI_Q_PERIOD_HPP_FEBRUARY_21_2018

#include <q/support/duration.hpp>
#include <q/support/frequency.hpp>

namespace cycfi::q
{
   struct frequency;

   ////////////////////////////////////////////////////////////////////////////
   struct period : duration
   {
      using duration::duration;
   };
}

#endif
