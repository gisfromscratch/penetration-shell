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

#ifndef SIMPLEPOINT2DFACTORY_H
#define SIMPLEPOINT2DFACTORY_H

#pragma once

#include "pch.h"
#include "IObjectFactory.h"

using namespace std;

namespace model
{
	class SimplePoint2dFactory : public IObjectFactory
	{
	public:
		SimplePoint2dFactory();
		~SimplePoint2dFactory();

		ICreatableObject* create() override;

	private:
		random_device _device;
		mt19937 _generator;
		uniform_real_distribution<double> _distribution;
	};
}

#endif // !SIMPLEPOINT2DFACTORY_H