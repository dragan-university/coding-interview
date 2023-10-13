/*
FizzBuzz5.java
*/
import java.util.*;
import java.util.concurrent.locks.Lock;

public class FizzBuzz5 implements Runnable {
    private int count;
    private int maxNumber;
    private Lock numberLock;
    private Lock divBy5Lock;
    private Lock divBy15Lock;

    public FizzBuzz5(int maxNumber, Lock numberLock, Lock divBy5Lock, Lock divBy15Lock) {
        this.count = 0;
        this.maxNumber = maxNumber;
        this.numberLock = numberLock;
        this.divBy5Lock = divBy5Lock;
        this.divBy15Lock = divBy15Lock;
    }

    public void run() {
        while (count < maxNumber) {
            divBy5Lock.lock();
            count += 5;
            if (count%3 != 0) {
                System.out.println("Buzz");
                numberLock.unlock();
            } else {
                divBy15Lock.unlock();
            }
        }
    }
}
