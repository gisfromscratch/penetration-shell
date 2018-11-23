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

#ifndef EXECUTIONTIMECOUNTER_H
#define EXECUTIONTIMECOUNTER_H

#pragma once

#include "pch.h"
#include "IPerformanceCounter.h"

using namespace chrono;

namespace model
{
	class ExecutionTimeCounter : IPerformanceCounter
	{
	public:
		ExecutionTimeCounter();
		~ExecutionTimeCounter();

		string name() const override;

		string statistics() const override;

		void update() override;

	private:
		bool _running;
		bool _stopped;
		system_clock::time_point _start;
		system_clock::time_point _end;
	};
}

#endif // !EXECUTIONTIMECOUNTER_H