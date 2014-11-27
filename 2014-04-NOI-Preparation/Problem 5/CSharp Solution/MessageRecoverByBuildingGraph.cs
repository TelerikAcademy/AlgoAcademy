using System;
using System.Collections.Generic;
using System.Text;

public class MessageRecoverByBuildingGraph : IMessageRecover
{
    private const int MaxNodes = 26 + 26; // [A-Z] + [a-z]

    private readonly bool[,] graph;
    private readonly bool[] isNode;
    private readonly IEnumerable<string> messages;

    public MessageRecoverByBuildingGraph(IEnumerable<string> messages)
    {
        this.messages = messages;

        this.graph = new bool[MaxNodes, MaxNodes];
        this.isNode = new bool[MaxNodes];

        this.BuildGraph();
    }

    /// <summary>
    /// Recovers the message using topological sort
    /// </summary>
    /// <returns>The minimum length (and lexicographically smallest) original message</returns>
    public string Recover()
    {
        var originalMessage = new StringBuilder();
        var used = new bool[MaxNodes];

        while (true)
        {
            bool removed = false;

            for (int i = 0; i < MaxNodes; i++)
            {
                if (this.isNode[i] && !used[i])
                {
                    bool hasPrecedence = false;
                    for (int j = 0; j < MaxNodes; j++)
                    {
                        if (this.graph[i, j])
                        {
                            hasPrecedence = true;
                            break;
                        }
                    }

                    if (!hasPrecedence)
                    {
                        originalMessage.Append(this.GetCharByCharId(i));
                        for (int j = 0; j < MaxNodes; j++)
                        {
                            this.graph[i, j] = false;
                            this.graph[j, i] = false;
                        }

                        used[i] = true;
                        removed = true;
                        break;
                    }
                }
            }

            if (!removed)
            {
                break;
            }
        }

        return originalMessage.ToString();
    }

    private void BuildGraph()
    {
        foreach (var message in this.messages)
        {
            this.isNode[this.GetCharId(message[0])] = true;

            for (int i = 1; i < message.Length; i++)
            {
                this.isNode[this.GetCharId(message[i])] = true;
                this.graph[this.GetCharId(message[i]), this.GetCharId(message[i - 1])] = true;
            }
        }
    }

    private int GetCharId(char ch)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            return ch - 'A';
        }

        if (ch >= 'a' && ch <= 'z')
        {
            return ch - 'a' + 26;
        }

        throw new ArgumentOutOfRangeException("ch");
    }

    private char GetCharByCharId(int id)
    {
        if (id < 26)
        {
            return (char)('A' + id);
        }

        if (id < 52)
        {
            return (char)('a' - 26 + id);
        }

        throw new ArgumentOutOfRangeException("id");
    }
}
