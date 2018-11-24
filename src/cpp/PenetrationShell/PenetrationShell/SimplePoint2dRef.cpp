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
#include "SimplePoint2dRef.h"

namespace model
{
	SimplePoint2dRef SimplePoint2dRef::_none = SimplePoint2dRef(0, 0, 0);

	SimplePoint2dRef::SimplePoint2dRef(double x, double y, int wkid) : _x(x), _y(y), _wkid(wkid), DefaultCreatableObjectRef(none())
	{
	}

	SimplePoint2dRef::~SimplePoint2dRef()
	{
	}

	string SimplePoint2dRef::name() const
	{
		return "Two dimensional point.";
	}

	bool SimplePoint2dRef::validate() const
	{
		if (4326 == _wkid)
		{
			return (-180 <= _x && _x <= 180 && -90 <= _y && _y <= 90);
		}
		else
		{
			return true;
		}
	}
}