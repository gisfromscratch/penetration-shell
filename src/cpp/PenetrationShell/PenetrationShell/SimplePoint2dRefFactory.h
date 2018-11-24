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

#ifndef SIMPLEPOINT2DREFFACTORY_H
#define SIMPLEPOINT2DREFFACTORY_H

#pragma once

#include "pch.h"
#include "IObjectRefFactory.h"
#include "SimplePoint2dRef.h"

using namespace std;

namespace model
{
	class SimplePoint2dRefFactory : public IObjectRefFactory
	{
	public:
		SimplePoint2dRefFactory();
		~SimplePoint2dRefFactory();

		ICreatableObjectRef& create() override;

	private:
		random_device _device;
		mt19937 _generator;
		uniform_real_distribution<double> _distribution;

		const size_t _capacity = 100000;
		vector<SimplePoint2dRef*> _objects;
		size_t _objectIndex;
	};
}

#endif // !SIMPLEPOINT2DREFFACTORY_H