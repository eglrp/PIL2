//
// NamedEvent.cpp
//
// $Id: //poco/1.4/Foundation/src/NamedEvent.cpp#2 $
//
// Library: Foundation
// Package: Processes
// Module:  NamedEvent
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "NamedEvent.h"

#define PLATEFORM_INCLUDE_SOURCE

#if defined(PIL_OS_FAMILY_WINDOWS) && defined(PIL_WIN32_UTF8)
//#include "NamedEvent_WIN32U.cpp"
#elif defined(PIL_OS_FAMILY_WINDOWS)
#include "NamedEvent_WIN32.cpp"
#elif defined(PIL_ANDROID)
//#include "NamedEvent_Android.cpp"
#elif defined(PIL_OS_FAMILY_UNIX)
#include "NamedEvent_UNIX.cpp"
#else
//#include "NamedEvent_VMS.cpp"
#endif


namespace pi {


NamedEvent::NamedEvent(const std::string& name):
	NamedEventImpl(name)
{
}


NamedEvent::~NamedEvent()
{
}


} // namespace pi
