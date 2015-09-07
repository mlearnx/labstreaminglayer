//  Copyright (c) 2013 Anton Bikineev
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)

//
// This is a partial header, do not include on it's own!!!
//
// Linear combination for bessel derivatives are defined here
#ifndef BOOST_MATH_SF_DETAIL_BESSEL_DERIVATIVES_LINEAR_HPP
#define BOOST_MATH_SF_DETAIL_BESSEL_DERIVATIVES_LINEAR_HPP

#ifdef _MSC_VER
#pragma once
#endif

namespace lslboost{ namespace math{ namespace detail{

template <class T, class Tag, class Policy>
inline T bessel_j_derivative_linear(T v, T x, Tag tag, Policy pol)
{
   return (lslboost::math::detail::cyl_bessel_j_imp<T>(v-1, x, tag, pol) - lslboost::math::detail::cyl_bessel_j_imp<T>(v+1, x, tag, pol)) / 2;
}

template <class T, class Policy>
inline T bessel_j_derivative_linear(T v, T x, const bessel_int_tag& tag, Policy pol)
{
   return (lslboost::math::detail::cyl_bessel_j_imp<T>(itrunc(v-1), x, tag, pol) - lslboost::math::detail::cyl_bessel_j_imp<T>(itrunc(v+1), x, tag, pol)) / 2;
}

template <class T, class Policy>
inline T sph_bessel_j_derivative_linear(unsigned v, T x, Policy pol)
{
   return (v / x) * lslboost::math::detail::sph_bessel_j_imp<T>(v, x, pol) - lslboost::math::detail::sph_bessel_j_imp<T>(v+1, x, pol);
}

template <class T, class Policy>
inline T bessel_i_derivative_linear(T v, T x, Policy pol)
{
   return (lslboost::math::detail::cyl_bessel_i_imp<T>(v-1, x, pol) + lslboost::math::detail::cyl_bessel_i_imp<T>(v+1, x, pol)) / 2;
}

template <class T, class Tag, class Policy>
inline T bessel_k_derivative_linear(T v, T x, Tag tag, Policy pol)
{
   return (lslboost::math::detail::cyl_bessel_k_imp<T>(v-1, x, tag, pol) + lslboost::math::detail::cyl_bessel_k_imp<T>(v+1, x, tag, pol)) / -2;
}

template <class T, class Policy>
inline T bessel_k_derivative_linear(T v, T x, const bessel_int_tag& tag, Policy pol)
{
   return (lslboost::math::detail::cyl_bessel_k_imp<T>(itrunc(v-1), x, tag, pol) + lslboost::math::detail::cyl_bessel_k_imp<T>(itrunc(v+1), x, tag, pol)) / -2;
}

template <class T, class Tag, class Policy>
inline T bessel_y_derivative_linear(T v, T x, Tag tag, Policy pol)
{
   return (lslboost::math::detail::cyl_neumann_imp<T>(v-1, x, tag, pol) - lslboost::math::detail::cyl_neumann_imp<T>(v+1, x, tag, pol)) / 2;
}

template <class T, class Policy>
inline T bessel_y_derivative_linear(T v, T x, const bessel_int_tag& tag, Policy pol)
{
   return (lslboost::math::detail::cyl_neumann_imp<T>(itrunc(v-1), x, tag, pol) - lslboost::math::detail::cyl_neumann_imp<T>(itrunc(v+1), x, tag, pol)) / 2;
}

template <class T, class Policy>
inline T sph_neumann_derivative_linear(unsigned v, T x, Policy pol)
{
   return (v / x) * lslboost::math::detail::sph_neumann_imp<T>(v, x, pol) - lslboost::math::detail::sph_neumann_imp<T>(v+1, x, pol);
}

}}} // namespaces

#endif // BOOST_MATH_SF_DETAIL_BESSEL_DERIVATIVES_LINEAR_HPP