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

namespace PenetrationShell.Model
{
    internal class SimpleObjectStore : IObjectStore
    {
        private ICreatableObject First { get; set; }

        private ICreatableObject Last { get; set; }

        public IObjectEnumeration Objects => new SimpleObjectEnumeration(First);

        public void Add(ICreatableObject newObject)
        {
            if (null == First)
            {
                First = newObject;
            }
            if (null != Last)
            {
                Last.Next = newObject;
            }
            Last = newObject;
        }
    }
}
