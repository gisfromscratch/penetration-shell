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
#include "SimplePoint2dFactory.h"
#include "SimplePoint2d.h"

namespace model
{
	SimplePoint2dFactory::SimplePoint2dFactory() : _generator(_device()), _distribution(0.0, 1.0)
	{
		_objects = vector<ICreatableObject*>(_capacity);
		initialize(0, _capacity);
		_objectIndex = 0;
		_resizeCount = 0;
	}

	SimplePoint2dFactory::~SimplePoint2dFactory()
	{
	}

	void SimplePoint2dFactory::initialize(const size_t& startIndex, const size_t& count)
	{
		for (auto index = startIndex, lastIndex = startIndex + count - 1; index <= lastIndex; index++)
		{
			_objects[index] = new SimplePoint2d(0, 0, 0);
		}
	}

	void SimplePoint2dFactory::resize(const size_t& newSize)
	{
		_objects.resize(newSize);
		for (auto index = 0; index < newSize; index++)
		{
			_objects.push_back(new SimplePoint2d(0, 0, 0));
		}
	}

	ICreatableObject* SimplePoint2dFactory::create()
	{
		auto x = -180.0 + (360.0 * _distribution(_generator));
		auto y = -90.0 + (180.0 * _distribution(_generator));
		auto wkid = 4326;
		//return new SimplePoint2d(x, y, wkid);

		if (_objects.size() == _objectIndex)
		{
			resize(++_resizeCount * _capacity);
		}
		new (_objects[_objectIndex]) SimplePoint2d(x, y, wkid);
		return _objects[_objectIndex++];
	}
}