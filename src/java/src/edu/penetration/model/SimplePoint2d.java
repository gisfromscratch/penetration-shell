/**
 *
 */
package edu.penetration.model;

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
public class SimplePoint2d extends DefaultCreatableObject {

	private double x;
	private double y;
	private int wkid;
	
	public SimplePoint2d(double x, double y, int wkid) {
		this.x = x;
		this.y = y;
		this.wkid = wkid;
	}
	
	/* (non-Javadoc)
	 * @see edu.penetration.shell.ICreatableObject#getName()
	 */
	@Override
	public String getName() {
		return "Two dimensional point.";
	}

	/* (non-Javadoc)
	 * @see edu.penetration.shell.ICreatableObject#validate()
	 */
	@Override
	public boolean validate() {
		if (4326 == wkid) {
			return (-180 <= x && x <= 180 && -90 <= y && y <= 90);
		}
		return true;
	}
}
