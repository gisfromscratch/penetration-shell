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

#include "pch.h"
#include <iostream>

#include "SimplePoint2d.h"
#include "SimplePoint2dFactory.h"

using namespace chrono;
using namespace model;
using namespace std;

int main(int argc, char *args[])
{
	if (1 != argc && 7 != argc)
	{
		cout << "Wrong parameter count!" << endl;
		cout << "\t - o\tNumber of objects" << endl;
		cout << "\t - p\tPause in msec" << endl;
		cout << "\t - r\tNumber of rounds" << endl;
		return -1;
	}
   
	auto objectCount = (long)1e6;
	auto pause = 5000;
	auto rounds = 100;

	for (auto round = 1; round <= rounds; round++)
	{
		cout << "Round " << round << " of " << rounds << "." << endl;

		auto factory = new SimplePoint2dFactory();
		ICreatableObject *first = nullptr;
		ICreatableObject *last = nullptr;
		for (auto objectIndex = 0; objectIndex < objectCount; objectIndex++)
		{
			auto newObject = factory->create();
			if (nullptr == first)
			{
				first = newObject;
			}
			if (nullptr != last)
			{
				last->setNext(newObject);
			}
			last = newObject;
		}
		delete factory;

		for (ICreatableObject *next = first; nullptr != next; last = next, next = next->next(), delete last)
		{
			if (!next->validate())
			{
				cout << "Invalid object found!" << endl;
				break;
			}
		}

		cout << "Pause for " << pause << " msec. . ." << endl;
		this_thread::sleep_for(duration<long, milli>(pause));
	}

	cout << "Done. . ." << endl;
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
