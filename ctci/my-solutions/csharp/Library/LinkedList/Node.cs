using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedListNS
{
    public class Node<T>
    {
        // contains the data of the node, what we want to store in the list
        private T item;
        // reference to the next node in the list
        private Node<T> next;

        public Node(T item, Node<T> next)
        {
            this.item = item;
            this.next = next;
        }

        /// <summary>
        /// get/set the data field
        /// </summary>
        public T Item
        {
            get { return this.item; }
            set { this.item = value; }
        }

        /// <summary>
        /// get/set the next field
        /// </summary>
        public Node<T> Next
        {
            get { return this.next; }
            set { this.next = value; }
        }
    }
}
