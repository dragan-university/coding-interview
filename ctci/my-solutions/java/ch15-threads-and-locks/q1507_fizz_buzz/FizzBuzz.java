/*
FizzBuzz.java
*/
import java.util.*;
import java.util.concurrent.locks.Lock;

public class FizzBuzz implements Runnable {
    private int count;
    private int maxNumber;
    private Lock numberLock;
    private Lock divBy3Lock;
    private Lock divBy5Lock;

    public FizzBuzz(int maxNumber, Lock numberLock, Lock divBy3Lock, Lock divBy5Lock) {
        this.count = 0;
        this.maxNumber = maxNumber;
        this.numberLock = numberLock;
        this.divBy3Lock = divBy3Lock;
        this.divBy5Lock = divBy5Lock;
    }

    public void run() {
        while (count < maxNumber) {
            numberLock.lock();
            count++;
            if (count%5 == 0) {
                divBy5Lock.unlock();
            } else if (count%3 == 0) {
                divBy3Lock.unlock();
            } else {
                System.out.println(count);
            }
        }
    }
}
