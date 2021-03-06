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
public abstract class DefaultCreatableObject implements ICreatableObject {

	private ICreatableObject other;
	
	/* (non-Javadoc)
	 * @see edu.penetration.shell.ICreatableObject#getName()
	 */
	@Override
	public abstract String getName();
	
	/* (non-Javadoc)
	 * @see edu.penetration.shell.ICreatableObject#getNext
	 */
	@Override
	public ICreatableObject getNext() {
		return other;
	}

	/* (non-Javadoc)
	 * @see edu.penetration.shell.ICreatableObject#setNext(edu.penetration.shell.ICreatableObject)
	 */
	@Override
	public void setNext(ICreatableObject other) {
		this.other = other;
	}
}
