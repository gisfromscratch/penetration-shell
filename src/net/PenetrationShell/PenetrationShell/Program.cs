using PenetrationShell.Model;
using System;
using System.Threading;

namespace PenetrationShell
{
    class Program
    {
        static void PrintStatistics(ITask task)
        {
            Console.WriteLine(task.Name);
            Console.Write("\t");
            Console.WriteLine(task.Counter.Statistics);
        }

        static long ParseArgumentValue(string name, string[] args, long defaultValue)
        {
            for (int index = 0; index < args.Length; index++)
            {
                var arg = args[index];
                if (0 == arg.CompareTo(name) && index + 1 < args.Length)
                {
                    var value = args[index + 1];
                    if (long.TryParse(value, out long number))
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

        static void Main(string[] args)
        {
            if (0 != args.Length && 6 != args.Length)
            {
                Console.WriteLine(@"Wrong parameter count:");
                Console.WriteLine(@"\t-o\tNumber of objects");
                Console.WriteLine(@"\t-p\tPause in msec");
                Console.WriteLine(@"\t-r\tNumber of rounds");
                return;
            }

            var objectCount = ParseArgumentValue("-o", args, (long)1e6);
            var pause = ParseArgumentValue("-p", args, 5000);
            var rounds = ParseArgumentValue("-r", args, 100);
            for (long round = 1; round <= rounds; round++)
            {
                Console.WriteLine($"Round {round} of {rounds}.");

                var factory = new SimplePoint2dFactory();
                var store = new SimpleObjectStore();
                var createTask = new CreateObjectsTask(factory, store);
                var measureTask = new MeasureDurationTask(@"Measure object creation task.");
                measureTask.Execute();
                for (long objectIndex = 0; objectIndex < objectCount; objectIndex++)
                {
                    createTask.Execute();
                }
                measureTask.Counter.Update();
                PrintStatistics(createTask);
                PrintStatistics(measureTask);

                measureTask = new MeasureDurationTask(@"Measure object validation task.");
                measureTask.Execute();
                var objects = store.Objects;
                ICreatableObject newObject;
                while (null != (newObject = objects.Next))
                {
                    if (!newObject.Validate())
                    {
                        Console.WriteLine(@"Invalid object found!");
                        break;
                    }
                }
                measureTask.Counter.Update();
                PrintStatistics(measureTask);

                Console.WriteLine($"Pause for {pause} msec. . .");
                Thread.Sleep((int)pause);
            }

            Console.WriteLine(@"Done. . .");
        }
    }
}
