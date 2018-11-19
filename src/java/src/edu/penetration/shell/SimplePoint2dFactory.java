/**
 *
 */
package edu.penetration.shell;

import java.util.Random;

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
public class SimplePoint2dFactory implements IObjectFactory {

	private static final Random random;
	
	static {
		random = new Random();
	}
	
	/* (non-Javadoc)
	 * @see edu.penetration.shell.IObjectFactory#create()
	 */
	@Override
	public ICreatableObject create() {
		double x = -180 + (360.0 * random.nextDouble());
		double y = -90 + (180.0 * random.nextDouble());
		int wkid = 4326;
		return new SimplePoint2d(x, y, wkid);
	}

}
