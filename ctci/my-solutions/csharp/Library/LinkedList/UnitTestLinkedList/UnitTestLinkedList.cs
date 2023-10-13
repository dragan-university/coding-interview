using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using LinkedListNS;

namespace UnitTestLinkedList
{
    [TestClass]
    public class LinkedListTests
    {
        [TestMethod]
        public void TestEmptyList()
        {
            // arrange & act
            LinkedList<string> list = new LinkedList<string>();

            // assert
            Assert.IsTrue(list.Empty, "empty list Empty property returns True");
            Assert.AreEqual(0, list.Count, "empty list have Count 0");
        }

        [TestMethod]
        public void TestAddMethod()
        {
            // arrange
            LinkedList<string> list = new LinkedList<string>();

            // act
            list.Add("Test1");
            list.Add("Test2");
            list.Add(1, "Test3");

            // assert
            Assert.AreEqual(3, list.Count, "list has 3 string items");
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException))]
        public void TestRemoveInvalidIndex()
        {
            // arrange
            LinkedList<string> list = new LinkedList<string>();

            // act
            object result = list.Remove(-1);

            // assert
            // none
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException))]
        public void TestRemoveFromEmptyList()
        {
            // arrange
            LinkedList<string> list = new LinkedList<string>();

            // act
            string result = list.Remove(1);
        }

        [TestMethod]
        public void TestRemoveMethod()
        {
            // arrange
            LinkedList<string> list = new LinkedList<string>();
            list.Add("Test1");
            list.Add("Test2");
            list.Add(1, "Test3");

            // act
            string result = list.Remove(1);

            // assert
            Assert.AreEqual(2, list.Count, "list has 2 string items");
            Assert.AreEqual("Test3", result, "Test3 is removed from the list");

            // act
            result = list.Remove(0);

            // assert
            Assert.AreEqual(1, list.Count, "list has 1 string item");
            Assert.AreEqual("Test1", result, "Test1 is removed from the list");

            // act
            result = list.Remove(5);

            // assert
            Assert.AreEqual(0, list.Count, "list is empty");
            Assert.AreEqual("Test2", result, "Test2 is removed from the list");
        }

        [TestMethod]
        public void TestClearMethod()
        {
            // arrange
            LinkedList<string> list = new LinkedList<string>();
            list.Add("Test1");
            list.Add("Test2");
            list.Add(1, "Test3");

            // act
            list.Clear();

            // assert
            Assert.IsTrue(list.Empty, "list is empty");
        }

        [TestMethod]
        public void TestIndexOf()
        {
            // arrange
            LinkedList<string> list = new LinkedList<string>();
            list.Add("Test1");
            list.Add("Test2");
            list.Add(1, "Test3");

            // act
            int result = list.IndexOf("Test3");

            // assert
            Assert.AreEqual(1, result, "index of Test3 is 1");

            // act
            result = list.IndexOf("Test4");

            // assert
            Assert.AreEqual(-1, result, "Test 4 is not in the list");
        }

        [TestMethod]
        public void TestContains()
        {
            // arrange
            LinkedList<string> list = new LinkedList<string>();
            list.Add("Test1");
            list.Add("Test2");
            list.Add(1, "Test3");

            // act
            bool result = list.Contains("Test3");

            // assert
            Assert.IsTrue(result, "Test3 is in the list");

            // act
            result = list.Contains("Test4");

            // assert
            Assert.IsFalse(result, "Test4 is not in the list");
        }

        [TestMethod]
        public void TestGet()
        {
            // arrange
            LinkedList<string> list = new LinkedList<string>();
            list.Add("Test1");
            list.Add("Test2");
            list.Add(1, "Test3");

            // act
            string result1 = list.Get(1);

            // assert
            Assert.AreEqual("Test3", result1, "Test3 is at index 1");

            // act
            string result2 = list[1];

            // assert
            Assert.AreEqual(result1, result2, "Get and indexer return same value for same index");
        }
    }
}
