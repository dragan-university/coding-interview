using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace question02_01
{
    class Program
    {
        static void Main(string[] args)
        {
            // arrange
            LinkedList<string> list = new LinkedList<string>();
            list.AddFirst("Test1");
            list.AddFirst("Test2");
            list.AddFirst("Test2");
            list.AddFirst("Test1");
            list.AddFirst("Test3");
            list.AddFirst("Test2");
            Console.WriteLine("list has {0} string items", list.Count);

            // act
            DeleteDuplicates<string>(list);

            // assert
            Console.WriteLine("after removing duplicates list has {0} string items", list.Count);

            Console.ReadLine();
        }

        static void DeleteDuplicates<T>(LinkedList<T> list)
        {
            Dictionary<T, bool> uniqueItems = new Dictionary<T, bool>();
            LinkedListNode<T> current = list.First;

            while (current != null)
            {
                LinkedListNode<T> next = current.Next;

                if (uniqueItems.ContainsKey(current.Value))
                {
                    list.Remove(current);
                }
                else
                {
                    uniqueItems.Add(current.Value, true);
                }
                current = next;
            }
        }
    }
}
