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

#ifndef DEFAULTCREATABLEOBJECT_H
#define DEFAULTCREATABLEOBJECT_H

#pragma once

#include "ICreatableObject.h"

namespace model
{
	class DefaultCreatableObject : public ICreatableObject
	{
	public:
		DefaultCreatableObject();
		virtual ~DefaultCreatableObject();

		ICreatableObject* next() const override;

		void setNext(ICreatableObject*) override;

	private:
		ICreatableObject *_next;
	};
}

#endif // !DEFAULTCREATABLEOBJECT_H