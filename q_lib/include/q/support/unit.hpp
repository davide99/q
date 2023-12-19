/*=============================================================================
   Copyright (c) 2014-2023 Joel de Guzman. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_Q_VALUE_HPP_MAY_21_2018)
#define CYCFI_Q_VALUE_HPP_MAY_21_2018

#include <q/support/basic_concepts.hpp>

namespace cycfi::q
{
   namespace concepts
   {
      template <typename A, typename B>
      concept SameUnit = std::same_as<typename A::unit_type, typename B::unit_type>;
   }

   struct direct_unit_type {};
   constexpr static direct_unit_type direct_unit = {};

   ////////////////////////////////////////////////////////////////////////////
   // unit: Unit abstraction and encapsulation
   ////////////////////////////////////////////////////////////////////////////
   template <typename T, typename Derived>
   struct unit
   {
      using derived_type = Derived;
                                    // Temporary constructor. This is not
                                    // marked deprecated because we will use
                                    // this for now.
      constexpr                     unit(T val, direct_unit_type) : rep(val) {}

      constexpr                     unit(T val) : rep(val) {}
      constexpr                     unit(unit const&) = default;
      constexpr                     unit(unit&&) = default;

      constexpr unit&               operator=(unit const&) = default;
      constexpr unit&               operator=(unit&&) = default;

      constexpr derived_type        operator-() const;

      T rep;
   };

   ////////////////////////////////////////////////////////////////////////////
   // Free functions
   ////////////////////////////////////////////////////////////////////////////

   template <typename T, typename Derived>
   constexpr Derived unit<T, Derived>::operator-() const
   {
      return derived_type{-rep, direct_unit};
   }

   ////////////////////////////////////////////////////////////////////////////
   template <typename A, typename B>
   requires concepts::SameUnit<A, B>
   constexpr bool operator<=(A a, B b)
   {
      return a.rep <= b.rep;
   }

   ////////////////////////////////////////////////////////////////////////////
   template <typename A, typename B, typename Derived>
   requires concepts::Arithmetic<B>
   constexpr Derived operator*(unit<A, Derived> a, B b)
   {
      return Derived{a.rep * b, direct_unit};
   }
}

#endif
