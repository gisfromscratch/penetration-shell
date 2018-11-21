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

#pragma once

#ifndef ICREATABLEOBJECT_H
#define ICREATABLEOBJECT_H

#include "pch.h"

using namespace std;

namespace model
{
	class ICreatableObject
	{
	public:
		ICreatableObject();
		virtual ~ICreatableObject();

		virtual string name() const = 0;

		virtual ICreatableObject* next() const = 0;

		virtual void setNext(ICreatableObject*) = 0;

		virtual bool validate() const = 0;
	};
}

#endif // !ICREATABLEOBJECT_H