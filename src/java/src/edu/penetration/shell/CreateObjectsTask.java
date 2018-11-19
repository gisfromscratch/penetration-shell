/**
 *
 */
package edu.penetration.shell;

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
public class CreateObjectsTask implements ITask {

	private final IObjectFactory factory;
	private final IPerformanceCounter counter;
	private ICreatableObject currentObject;
	
	CreateObjectsTask(IObjectFactory factory) {
		this.factory = factory;
		this.counter = new NumberOfObjectsCounter();
	}

	@Override
	public String getName() {
		return "Create objects task.";
	}

	@Override
	public void execute() {
		ICreatableObject last = currentObject;
		currentObject = factory.create();
		if (null != last) {
			last = currentObject;
		}
		counter.update();
	}

	@Override
	public IPerformanceCounter getCounter() {
		return counter;
	}
}