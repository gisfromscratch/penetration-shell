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

#include "CreateObjectsTask.h"
#include "ITask.h"
#include "MeasureDurationTask.h"
#include "SimpleObjectStore.h"
#include "SimplePoint2d.h"
#include "SimplePoint2dFactory.h"

using namespace chrono;
using namespace model;
using namespace std;

static void printStatistics(ITask *task)
{
	cout << task->name() << endl;
	cout << "\t" << task->counter()->statistics() << endl;
}

static long parseArgumentValue(const char *name, int argc, char *args[], long defaultValue)
{
	for (int index = 1; index < argc; index++)
	{
		auto arg = args[index];
		if (0 == strcmp(arg, name) && index + 1 < argc)
		{
			auto value = args[index + 1];
			auto number = atol(value);
			if (0 < number)
			{
				return number;
			}
			else
			{
				return defaultValue;
			}
		}
	}

	return defaultValue;
}

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
   
	auto objectCount = parseArgumentValue("-o", argc, args, (long)2e0);
	auto pause = parseArgumentValue("-p", argc, args, 5000);
	auto rounds = parseArgumentValue("-r", argc, args, 100);
	for (auto round = 1; round <= rounds; round++)
	{
		cout << "Round " << round << " of " << rounds << "." << endl;

		auto factory = new SimplePoint2dFactory();
		auto store = new SimpleObjectStore();
		auto createTask = new CreateObjectsTask(factory, store);
		auto measureTask = new MeasureDurationTask("Measure object creation task.");
		measureTask->execute();
		for (auto objectIndex = 0; objectIndex < objectCount; objectIndex++)
		{
			createTask->execute();
		}
		measureTask->counter()->update();
		printStatistics(createTask);
		printStatistics(measureTask);

		delete measureTask;
		measureTask = new MeasureDurationTask("Measure object validation task.");
		measureTask->execute();
		auto objects = store->objects();
		ICreatableObject *newObject;
		while (nullptr != (newObject = objects->next()))
		{
			if (!newObject->validate())
			{
				cout << "Invalid object found!" << endl;
				break;
			}
		}
		measureTask->counter()->update();
		printStatistics(measureTask);

		// Delete all objects
		ICreatableObject *last = nullptr;
		while (nullptr != (newObject = objects->next()))
		{
			if (nullptr != last)
			{
				delete last;
			}
			last = newObject;
		}
		if (nullptr != last)
		{
			delete last;
		}

		delete objects;
		delete measureTask;
		delete createTask;
		delete store;
		delete factory;

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
