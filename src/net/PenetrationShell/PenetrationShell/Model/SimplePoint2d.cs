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
    internal class SimplePoint2d : DefaultCreatableObject
    {
        internal SimplePoint2d(double x, double y, int wkid)
        {
            X = x;
            Y = y;
            Wkid = wkid;
        }

        public override string Name => @"Two dimensional point";

        private double X { get; set; }

        private double Y { get; set; }

        private int Wkid { get; set; }

        public override bool Validate()
        {
            if (4326 == Wkid)
            {
                return (-180 <= X && X <= 180 && -90 <= Y && Y <= 90);
            }
            return true;
        }
    }
}
