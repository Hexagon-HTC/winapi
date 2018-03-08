/*
 * Copyright 2016 Klemens D. Morgenstern
 * Copyright 2016 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_PRIORITY_CLASS_HPP_INCLUDED_
#define BOOST_WINAPI_PRIORITY_CLASS_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_DESKTOP_SYSTEM

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

BOOST_SYMBOL_IMPORT boost::winapi::DWORD_ BOOST_WINAPI_DETAIL_WINAPI_CC
GetPriorityClass(boost::winapi::HANDLE_ hProcess);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ BOOST_WINAPI_DETAIL_WINAPI_CC
SetPriorityClass(
    boost::winapi::HANDLE_ hProcess,
    boost::winapi::DWORD_ dwPriorityClass);

} // extern "C"
#endif //defined BOOST_WINDOWS_H

namespace boost {
namespace winapi {

#if defined(BOOST_USE_WINDOWS_H)

BOOST_CONSTEXPR_OR_CONST DWORD_ NORMAL_PRIORITY_CLASS_            = NORMAL_PRIORITY_CLASS;
BOOST_CONSTEXPR_OR_CONST DWORD_ IDLE_PRIORITY_CLASS_              = IDLE_PRIORITY_CLASS;
BOOST_CONSTEXPR_OR_CONST DWORD_ HIGH_PRIORITY_CLASS_              = HIGH_PRIORITY_CLASS;
BOOST_CONSTEXPR_OR_CONST DWORD_ REALTIME_PRIORITY_CLASS_          = REALTIME_PRIORITY_CLASS;
BOOST_CONSTEXPR_OR_CONST DWORD_ BELOW_NORMAL_PRIORITY_CLASS_      = BELOW_NORMAL_PRIORITY_CLASS;
BOOST_CONSTEXPR_OR_CONST DWORD_ ABOVE_NORMAL_PRIORITY_CLASS_      = ABOVE_NORMAL_PRIORITY_CLASS;

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
BOOST_CONSTEXPR_OR_CONST DWORD_ PROCESS_MODE_BACKGROUND_BEGIN_    = PROCESS_MODE_BACKGROUND_BEGIN;
BOOST_CONSTEXPR_OR_CONST DWORD_ PROCESS_MODE_BACKGROUND_END_      = PROCESS_MODE_BACKGROUND_END;
#endif

#else // defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ NORMAL_PRIORITY_CLASS_            = 0x20;
BOOST_CONSTEXPR_OR_CONST DWORD_ IDLE_PRIORITY_CLASS_              = 0x40;
BOOST_CONSTEXPR_OR_CONST DWORD_ HIGH_PRIORITY_CLASS_              = 0x80;
BOOST_CONSTEXPR_OR_CONST DWORD_ REALTIME_PRIORITY_CLASS_          = 0x100;
BOOST_CONSTEXPR_OR_CONST DWORD_ BELOW_NORMAL_PRIORITY_CLASS_      = 0x4000;
BOOST_CONSTEXPR_OR_CONST DWORD_ ABOVE_NORMAL_PRIORITY_CLASS_      = 0x8000;

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
BOOST_CONSTEXPR_OR_CONST DWORD_ PROCESS_MODE_BACKGROUND_BEGIN_    = 0x100000;
BOOST_CONSTEXPR_OR_CONST DWORD_ PROCESS_MODE_BACKGROUND_END_      = 0x200000;
#endif

#endif // defined( BOOST_USE_WINDOWS_H )

using ::GetPriorityClass;
using ::SetPriorityClass;

}
}

#endif // BOOST_WINAPI_PARTITION_DESKTOP_SYSTEM

#endif // BOOST_WINAPI_PRIORITY_CLASS_HPP_INCLUDED_
