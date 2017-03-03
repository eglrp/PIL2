//
// RefCountedObject.h
//
// $Id: //poco/1.4/Foundation/include/Poco/RefCountedObject.h#1 $
//
// Library: Foundation
// Package: Core
// Module:  RefCountedObject
//
// Definition of the RefCountedObject class.
//
// Copyright (c) 2004-2009, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_RefCountedObject_INCLUDED
#define Foundation_RefCountedObject_INCLUDED

#include "../Environment.h"
#include "../Debug/Assert.h"

#include "AtomicCounter.h"


namespace pi {


class PIL_API RefCountedObject
	/// A base class for objects that employ
	/// reference counting based garbage collection.
	///
	/// Reference-counted objects inhibit construction
	/// by copying and assignment.
{
public:
	RefCountedObject();
		/// Creates the RefCountedObject.
		/// The initial reference count is one.

	void duplicate() const;
		/// Increments the object's reference count.
		
	void release() const throw();
		/// Decrements the object's reference count
		/// and deletes the object if the count
		/// reaches zero.
		
	int referenceCount() const;
		/// Returns the reference count.

protected:
	virtual ~RefCountedObject();
		/// Destroys the RefCountedObject.

private:
	RefCountedObject(const RefCountedObject&);
	RefCountedObject& operator = (const RefCountedObject&);

	mutable AtomicCounter _counter;
};


//
// inlines
//
inline int RefCountedObject::referenceCount() const
{
	return _counter.value();
}


inline void RefCountedObject::duplicate() const
{
	++_counter;
}


inline void RefCountedObject::release() const throw()
{
	try
	{
		if (--_counter == 0) delete this;
	}
	catch (...)
	{
        pi_assert2(0, "can not release!");
	}
}


} // namespace pi


#endif // Foundation_RefCountedObject_INCLUDED
