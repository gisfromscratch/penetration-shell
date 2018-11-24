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
#include "SimplePoint2dRefFactory.h"

namespace model
{
	SimplePoint2dRefFactory::SimplePoint2dRefFactory() : _generator(_device()), _distribution(0.0, 1.0)
	{
		_objects.reserve(_capacity);
		_objectIndex = 0;
	}

	SimplePoint2dRefFactory::~SimplePoint2dRefFactory()
	{
		for_each(_objects.begin(), _objects.end(), [] (SimplePoint2dRef *item) { delete item; });
	}

	ICreatableObjectRef& SimplePoint2dRefFactory::create()
	{
		auto x = -180.0 + (360.0 * _distribution(_generator));
		auto y = -90.0 + (180.0 * _distribution(_generator));
		auto wkid = 4326;
		_objects.push_back(new SimplePoint2dRef(x, y, wkid));
		return *_objects[_objectIndex++];
	}
}