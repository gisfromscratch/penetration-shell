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

#ifndef SIMPLEPOINT2DREF_H
#define SIMPLEPOINT2DREF_H

#pragma once

#include "DefaultCreatableObjectRef.h"

namespace model
{
	class SimplePoint2dRef : public DefaultCreatableObjectRef
	{
	public:
		SimplePoint2dRef(double, double, int);
		~SimplePoint2dRef();

		string name() const;

		bool validate() const;

		static SimplePoint2dRef& none()
		{
			return _none;
		}

	private:
		static SimplePoint2dRef _none;
		double _x;
		double _y;
		int _wkid;
	};
}

#endif // !SIMPLEPOINT2DREF_H