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
	Random SimplePoint2dFactory::_random = Random();

	SimplePoint2dFactory::SimplePoint2dFactory()
	{
	}

	SimplePoint2dFactory::~SimplePoint2dFactory()
	{
	}

	ICreatableObject* SimplePoint2dFactory::create()
	{
		auto x = -180.0 + (360.0 * _random.nextDouble());
		auto y = -90.0 + (180.0 * _random.nextDouble());
		auto wkid = 4326;
		return new SimplePoint2d(x, y, wkid);
	}
}