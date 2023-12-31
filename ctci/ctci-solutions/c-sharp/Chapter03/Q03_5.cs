﻿using System;
using ctci.Contracts;
using ctci.Library;
using System.Collections.Generic;

namespace Chapter03
{
    public class Q03_5 : IQuestion
    {
        class MyQueue<T>
        {
            readonly Stack<T> _stackNewest;
            readonly Stack<T> _stackOldest;

            public MyQueue()
            {
                _stackNewest = new Stack<T>();
                _stackOldest = new Stack<T>();
            }

            public int Size()
            {
                return _stackNewest.Count + _stackOldest.Count;
            }

            public void Enqueue(T value)
            {
                // Push onto stack1
                _stackNewest.Push(value);
            }

            /* Move elements from stackNewest into stackOldest. This is usually done so that we can
             * do operations on stackOldest.
             */
            private void ShiftStacks()
            {
                if (_stackOldest.Count == 0)
                {
                    while (_stackNewest.Count != 0)
                    {
                        _stackOldest.Push(_stackNewest.Pop());
                    }
                }
            }

            public T Peek()
            {
                ShiftStacks();

                // retrieve the oldest item.
                return _stackOldest.Peek(); 
            }

            public T Dequeue()
            {
                ShiftStacks();

                // pop the oldest item.
                return _stackOldest.Pop(); 
            }
        }

        public void Run()
        {
		    var myQueue = new MyQueue<int>();	

            // Let's test our code against a "real" queue
            var testQueue = new Queue<int>();

            for (var i = 0; i < 100; i++) 
            {
			    var choice = AssortedMethods.RandomIntInRange(0, 10);
			
                if (choice <= 5)
                { 
                    // enqueue
                    var element = AssortedMethods.RandomIntInRange(1, 10);
				    testQueue.Enqueue(element);
				    myQueue.Enqueue(element);
                    Console.WriteLine("Enqueued " + element);
			    } 
                else if (testQueue.Count > 0) 
                {
				    var top1 = testQueue.Dequeue();
                    var top2 = myQueue.Dequeue();

				    if (top1 != top2) 
                    { // Check for error
					    Console.WriteLine("******* FAILURE - DIFFERENT TOPS: " + top1 + ", " + top2);
				    } 
				    Console.WriteLine("Dequeued " + top1);
			    }

                if (testQueue.Count == myQueue.Size()) 
                {
				    if (testQueue.Count > 0 && testQueue.Peek() != myQueue.Peek()) 
                    {
					    Console.WriteLine("******* FAILURE - DIFFERENT TOPS: " + testQueue.Peek() + ", " + myQueue.Peek() + " ******");
				    }
			    } 
                else 
                {
				    Console.WriteLine("******* FAILURE - DIFFERENT SIZES ******");
			    }
		    }
        }
    }
}