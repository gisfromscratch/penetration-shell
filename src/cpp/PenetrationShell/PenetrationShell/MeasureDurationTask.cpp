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
#include "ExecutionTimeCounter.h"
#include "MeasureDurationTask.h"

namespace model
{
	MeasureDurationTask::MeasureDurationTask(const string &name) : _name(name), _counter(new ExecutionTimeCounter())
	{
	}

	MeasureDurationTask::~MeasureDurationTask()
	{
		delete _counter;
	}

	string MeasureDurationTask::name() const
	{
		return _name;
	}

	void MeasureDurationTask::execute()
	{
		_counter->update();
	}

	IPerformanceCounter* MeasureDurationTask::counter() const
	{
		return _counter;
	}
}