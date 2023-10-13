/*
Q 15.7 java

FizzBuzz: In a classic problem FizzBuzz you are told to print the numbers from 1 
to N. However, when the number is divisible with 3, print 'Fizz'. When it is
divisible by 5, print 'Buzz'. When it is divisible by 3 and 5, print 'FizzBuzz'.
In this problem, you are asked to do this in a multithreaded way. Implement a
multithreaded version of FizzBuzz with four threads. One thread checks for 
divisibility of 3 and prints 'Fizz'. Another thread is responsible for 
dibisibility of 5 and prints 'Buzz'. A third thread is responsible for 
divisibility with of 3 and 5 and prints 'FizzBuzz'. A fourth thread does the 
numbers. 

Build:
javac <file>.java
Run:
java <file>
*/
import java.util.*;
import java.util.concurrent.locks.Lock;

public class FizzBuzz3 implements Runnable {
    private int count;
    private int maxNumber;
    private Lock numberLock;
    private Lock divBy3Lock;
    private Lock divBy15Lock;

    public FizzBuzz3(int maxNumber, Lock numberLock, Lock divBy3Lock, Lock divBy15Lock) {
        this.count = 0;
        this.maxNumber = maxNumber;
        this.numberLock = numberLock;
        this.divBy3Lock = divBy3Lock;
        this.divBy15Lock = divBy15Lock;
    }

    public void run() {
        while (count < maxNumber) {
            divBy3Lock.lock();
            System.out.println("yuhuuu");
            numberLock.lock();
            count += 3;
            if (count%5 != 0) {
                System.out.println("Buzz");
                numberLock.unlock();
            } else {
                divBy15Lock.unlock();
            }
        }
    }
}
