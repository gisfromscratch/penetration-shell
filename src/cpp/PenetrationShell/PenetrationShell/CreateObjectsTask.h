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

#ifndef CREATEOBJECTSTASK_H
#define CREATEOBJECTSTASK_H

#pragma once

#include "IObjectFactory.h"
#include "IObjectStore.h"
#include "ITask.h"

namespace model
{
	class CreateObjectsTask : ITask
	{
	public:
		CreateObjectsTask(IObjectFactory*, IObjectStore*);
		virtual ~CreateObjectsTask();

	private:
		IObjectFactory *_factory;
		IObjectStore *_store;
	};
}

#endif // !CREATEOBJECTSTASK_H