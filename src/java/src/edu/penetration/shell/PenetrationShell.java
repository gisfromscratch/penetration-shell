package edu.penetration.shell;

import edu.penetration.model.CreateObjectsTask;
import edu.penetration.model.ITask;
import edu.penetration.model.SimplePoint2dFactory;

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
public class PenetrationShell {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		SimplePoint2dFactory factory = new SimplePoint2dFactory();
		ITask task = new CreateObjectsTask(factory);
		
		long count = (long) 1e12;
		for (; 0 < count; count--) {
			task.execute();
		}
		System.out.println(task.getName());
		System.out.print("\t");
		System.out.println(task.getCounter().getStatistics());
		System.out.println("Done ...");
	}
}
