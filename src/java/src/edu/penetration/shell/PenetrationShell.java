package edu.penetration.shell;

import edu.penetration.model.CreateObjectsTask;
import edu.penetration.model.ICreatableObject;
import edu.penetration.model.IObjectEnumeration;
import edu.penetration.model.IObjectFactory;
import edu.penetration.model.IObjectStore;
import edu.penetration.model.ITask;
import edu.penetration.model.MeasureDurationTask;
import edu.penetration.model.SimpleObjectStore;
import edu.penetration.model.SimplePoint2dFactory;

/**
 * Copyright 2018 Jan Tschada
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
public class PenetrationShell {
	
	private static void printStatistics(ITask task) {
		System.out.println(task.getName());
		System.out.print("\t");
		System.out.println(task.getCounter().getStatistics());
	}

	/**
	 * @param args
	 * @throws InterruptedException
	 */
	public static void main(String[] args) throws InterruptedException {
		final long pause = 5000;
		long rounds = 100;
		for (; 0 < rounds; rounds--) {
			IObjectFactory factory = new SimplePoint2dFactory();
			IObjectStore store = new SimpleObjectStore();
			ITask createTask = new CreateObjectsTask(factory, store);
			ITask measureTask = new MeasureDurationTask();
			measureTask.execute();
			long objectCount = (long) 1e6;
			for (; 0 < objectCount; objectCount--) {
				createTask.execute();
			}
			measureTask.getCounter().update();
			printStatistics(createTask);
			printStatistics(measureTask);

			measureTask = new MeasureDurationTask();
			measureTask.execute();
			IObjectEnumeration objects = store.getObjects();
			ICreatableObject object;
			while (null != (object = objects.next())) {
				if (!object.validate()) {
					System.out.println("Invalid object found!");
					break;
				}
			}
			measureTask.getCounter().update();
			printStatistics(measureTask);
			
			System.out.println("Pause ...");
			Thread.sleep(pause);
		}

		System.out.println("Done ...");
	}
}
