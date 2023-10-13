using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedListNS
{
    public partial class LinkedList<T>
    {
        // Reference to the first node in the list
        private Node<T> head;
        // How many items are currently in the list
        private int count;

        /// <summary>
        /// Creates a new LinkedList
        /// </summary>
        public LinkedList()
        {
            this.head = null;
            this.count = 0;
        }

        /// <summary>
        /// True if the list is empty
        /// </summary>
        public bool Empty
        {
            get { return this.count == 0; }
        }

        /// <summary>
        /// Number of objects in the list
        /// </summary>
        public int Count
        {
            get { return this.count; }
        }

        public T this[int index]
        {
            get { return Get(index); }
        }

        /// <summary>
        /// Add an object to the list at the specified index
        /// </summary>
        /// <param name="index">Index to add object</param>
        /// <param name="item">data to add</param>
        /// <returns>object added</returns>
        public T Add(int index, T item)
        {
            if (index < 0)
            {
                throw new ArgumentOutOfRangeException("Index: " + index);
            }

            if (index > count)
            {
                index = Count;
            }

            Node<T> current = this.head;

            if (this.Empty || index == 0)
            {
                this.head = new Node<T>(item, this.head);
            }
            else
            {
                for (int ix = 0; ix < index - 1; ix++)
                {
                    current = current.Next;
                }

                current.Next = new Node<T>(item, current.Next);
            }

            count++;

            return item;
        }

        /// <summary>
        /// Add an object to the end of the list
        /// </summary>
        /// <param name="item">item to add</param>
        /// <returns>object added</returns>
        public T Add(T item)
        {
            return this.Add(count, item);
        }

        public T Remove(int index)
        {
            if (index < 0)
            {
                throw new ArgumentOutOfRangeException("Index: " + index);
            }

            if (this.Empty)
            {
                throw new ArgumentOutOfRangeException(
                    "Unable to remove from empty (index: " + index + ")");
            }

            if (index >= count)
            {
                index = count - 1;
            }

            Node<T> current = this.head;
            T result;

            if (index ==0)
            {
                result = current.Item;
                this.head = current.Next;
            }
            else
            {
                for (int ix = 0; ix < index-1; ix++)
                {
                    current = current.Next;
                }

                result = current.Next.Item;
                current.Next = current.Next.Next;
            }

            count--;
            return result;
        }

        public void Clear()
        {
            head = null;
            count = 0;
        }

        public int IndexOf(T item)
        {
            Node<T> current = head;

            for (int ix=0; ix<count; ix++)
            {
                if (current.Item.Equals(item))
                {
                    return ix;
                }

                current = current.Next;
            }

            return -1;
        }

        public bool Contains(T item)
        {
            return (IndexOf(item) >= 0);
        }

        public T Get(int index)
        {
            if (index < 0)
            {
                throw new ArgumentOutOfRangeException("Index: " + index);
            }

            if (this.Empty)
            {
                throw new ArgumentOutOfRangeException("Empty list -- Index: " + index);
            }

            if (index >= count)
            {
                index = count - 1;
            }

            Node<T> current = this.head;

            for (int ix = 0; ix < index; ix++)
            {
                current = current.Next;
            }

            return current.Item;
        }
    }
}
