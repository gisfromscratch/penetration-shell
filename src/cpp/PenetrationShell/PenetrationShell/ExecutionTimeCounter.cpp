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

namespace model
{
	ExecutionTimeCounter::ExecutionTimeCounter() : _running(false), _stopped(false)
	{
	}

	ExecutionTimeCounter::~ExecutionTimeCounter()
	{
	}

	string ExecutionTimeCounter::name() const
	{
		return "Execution time";
	}

	string ExecutionTimeCounter::statistics() const
	{
		if (_stopped)
		{
			ostringstream buffer;
			buffer << duration_cast<milliseconds>(_end - _start).count();
			buffer << " msec elapsed.";
			return buffer.str();
		}
		else
		{
			return "Timer was never stopped!";
		}
	}

	void ExecutionTimeCounter::update()
	{
		if (!_running)
		{
			_start = system_clock::now();
			_running = true;
		}
		else
		{
			_end = system_clock::now();
			_stopped = true;
			_running = false;
		}
	}
}