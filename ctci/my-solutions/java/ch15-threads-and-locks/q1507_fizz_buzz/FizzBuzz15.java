/*
FizzBuzz15.java
*/
import java.util.*;
import java.util.concurrent.locks.Lock;

public class FizzBuzz15 implements Runnable {
    private int count;
    private int maxNumber;
    private Lock numberLock;
    private Lock divBy15Lock;

    public FizzBuzz15(int maxNumber, Lock numberLock, Lock divBy15Lock) {
        this.count = 0;
        this.maxNumber = maxNumber;
        this.numberLock = numberLock;
        this.divBy15Lock = divBy15Lock;
    }

    public void run() {
        while (count < maxNumber) {
            divBy15Lock.lock();
            count += 15;
            System.out.println("FizzBuzz");
            numberLock.unlock();
        }
    }
}
