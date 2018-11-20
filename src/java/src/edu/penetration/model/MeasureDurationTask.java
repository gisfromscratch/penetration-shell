/**
 *
 */
package edu.penetration.model;

import java.time.Instant;

/**
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
public class MeasureDurationTask implements ITask {
	
	private final ExecutionTimeCounter counter;
	
	public MeasureDurationTask() {
		counter = new ExecutionTimeCounter();
	}
	
	/* (non-Javadoc)
	 * @see edu.penetration.model.ITask#getName()
	 */
	@Override
	public String getName() {
		return "Measure duration task.";
	}

	/* (non-Javadoc)
	 * @see edu.penetration.model.ITask#execute()
	 */
	@Override
	public void execute() {
		counter.update();
	}

	/* (non-Javadoc)
	 * @see edu.penetration.model.ITask#getCounter()
	 */
	@Override
	public IPerformanceCounter getCounter() {
		return counter;
	}
}
