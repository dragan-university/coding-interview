import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Solution
{
    public static void main(String[] args) {
        final int maxNumber = 50;
        Lock numberLock = new ReentrantLock();
        Lock divBy3Lock = new ReentrantLock();
        Lock divBy5Lock = new ReentrantLock();
        Lock divBy15Lock = new ReentrantLock();

        divBy3Lock.lock();
        divBy5Lock.lock();
        divBy15Lock.lock();

        FizzBuzz fb = new FizzBuzz(maxNumber, numberLock, divBy3Lock, divBy5Lock);
        FizzBuzz3 fb3 = new FizzBuzz3(maxNumber, numberLock, divBy3Lock, divBy15Lock);
        FizzBuzz5 fb5 = new FizzBuzz5(maxNumber, numberLock, divBy5Lock, divBy15Lock);
        FizzBuzz15 fb15 = new FizzBuzz15(maxNumber, numberLock, divBy15Lock);

        Thread fbt = new Thread(fb);
        Thread fbt3 = new Thread(fb3);
        Thread fbt5 = new Thread(fb5);
        Thread fbt15 = new Thread(fb15);

        fbt.start();
        fbt3.start();
        fbt5.start();
        fbt15.start();
    }
}
