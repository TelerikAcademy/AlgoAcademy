using System;
using System.Collections.Generic;

internal class Program
{
    private static void Main()
    {
        var messages = new List<string>();
        int numberOfMessages = int.Parse(Console.ReadLine());
        for (int i = 0; i < numberOfMessages; i++)
        {
            messages.Add(Console.ReadLine());
        }

        IMessageRecover messageRecover = new MessageRecoverByBuildingGraph(messages);
        string originalMessage = messageRecover.Recover();
        Console.WriteLine(originalMessage);
    }
}
