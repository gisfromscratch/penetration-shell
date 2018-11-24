/*
 * Copyright 2018 Jan Tschada
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "pch.h"
#include "SimpleObjectRefStore.h"

namespace model
{
	SimpleObjectRefStore::SimpleObjectRefStore(ICreatableObjectRef &none) : _none(none), _first(none), _last(none), _enumIndex(0)
	{
	}

	SimpleObjectRefStore::~SimpleObjectRefStore()
	{
	}

	void SimpleObjectRefStore::add(const ICreatableObjectRef &newObject)
	{
		if (&_none == &_first)
		{
			_first = newObject;
		}
		if (&_none != &_last)
		{
			_last.setNext(newObject);
		}
		_last = newObject;
	}

	IObjectRefEnumeration& SimpleObjectRefStore::objects()
	{
		SimpleObjectRefEnumeration enumeration(_none, _first);
		_enumerations.push_back(enumeration);
		return _enumerations[_enumIndex++];
	}
}