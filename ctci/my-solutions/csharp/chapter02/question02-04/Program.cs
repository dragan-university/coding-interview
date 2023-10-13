using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace question02_04
{
    class Program
    {
        static void Main(string[] args)
        {
            LinkedList<int> list = new LinkedList<int>(new int[] {1,7,5,11,4,9});

            foreach (int item in list)
            {
                Console.WriteLine(item);
            }

            list = Partition(list, 6);
            foreach (int item in list)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }

        static LinkedList<int> Partition(LinkedList<int> list, int x)
        {
            LinkedList<int> partitioned = new LinkedList<int>();

            LinkedListNode<int> current = list.First;
            while (current != null)
            {
                if (current.Value < x)
                {
                    partitioned.AddFirst(current.Value);
                }
                else
                {
                    partitioned.AddLast(current.Value);
                }

                current = current.Next;
            }

            return partitioned;
        }
    }
}
