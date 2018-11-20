/**
 *
 */
package edu.penetration.model;

import java.time.Duration;
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
public class ExecutionTimeCounter implements IPerformanceCounter {

	private Instant start;
	private Instant stop;
	
	/* (non-Javadoc)
	 * @see edu.penetration.model.IPerformanceCounter#getName()
	 */
	@Override
	public String getName() {
		return "Execution time";
	}

	/* (non-Javadoc)
	 * @see edu.penetration.model.IPerformanceCounter#getStatistics()
	 */
	@Override
	public String getStatistics() {
		if (null == start) {
			return "Counter was not started!";
		}
		long seconds = Duration.between(start, stop).toMillis();
		return String.format("%d msec elapsed.", seconds);
	}

	/* (non-Javadoc)
	 * @see edu.penetration.model.IPerformanceCounter#update()
	 */
	@Override
	public void update() {
		if (null == start) {
			start = Instant.now();
		}
		stop = Instant.now();
	}

}
