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
#include "CreateObjectsTask.h"
#include "NumberOfObjectsCounter.h"

namespace model
{
	CreateObjectsTask::CreateObjectsTask(IObjectFactory *factory, IObjectStore *store) : _factory(factory), _store(store), _counter(new NumberOfObjectsCounter())
	{
	}

	CreateObjectsTask::~CreateObjectsTask()
	{
		delete _counter;
	}

	string CreateObjectsTask::name() const
	{
		return "Create objects task.";
	}

	void CreateObjectsTask::execute()
	{
		auto newObject = _factory->create();
		_store->add(newObject);
		_counter->update();
	}

	IPerformanceCounter* CreateObjectsTask::counter() const
	{
		return nullptr;// _counter;
	}
}