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
	
	private static long parseArgumentValue(String name, String[] args, long defaultValue) {
		for (int index = 0; index < args.length; index++) {
			String arg = args[index];
			if (0 == arg.compareTo(name) && index + 1 < args.length) {
				String value = args[index+1];
				try {
					return Long.parseLong(value);
				} catch (NumberFormatException ex) {
					return defaultValue;
				}
			}
		}
		return defaultValue;
	}

	/**
	 * @param args
	 * @throws InterruptedException
	 */
	public static void main(String[] args) throws InterruptedException {
		if (0 != args.length && 6 != args.length) {
			System.out.println("Wrong parameter count:");
			System.out.println("\t-o\tNumber of objects");
			System.out.println("\t-p\tPause in msec");
			System.out.println("\t-r\tNumber of rounds");
			return;
		}
		
		long objectCount = parseArgumentValue("-o", args, (long) 1e6);
		long pause = parseArgumentValue("-p", args, 5000);
		long rounds = parseArgumentValue("-r", args, 100);
		for (long round = 1; round <= rounds; round++) {
			System.out.println(String.format("Round %d of %d.", round, rounds));
			
			IObjectFactory factory = new SimplePoint2dFactory();
			IObjectStore store = new SimpleObjectStore();
			ITask createTask = new CreateObjectsTask(factory, store);
			ITask measureTask = new MeasureDurationTask("Measure object creation task.");
			measureTask.execute();
			for (long objectIndex = 0; objectIndex < objectCount; objectIndex++) {
				createTask.execute();
			}
			measureTask.getCounter().update();
			printStatistics(createTask);
			printStatistics(measureTask);

			measureTask = new MeasureDurationTask("Measure object validation task.");
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
			
			System.out.println(String.format("Pause for %d msec. . .", pause));
			Thread.sleep(pause);
		}

		System.out.println("Done. . .");
	}
}
