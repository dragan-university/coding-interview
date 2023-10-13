public class lock_example implements Runnable
{
    private String name;
    private ClassB

    runnable_example(String aName) {
        name = aName;
    }
    public void run() {
        System.out.println("runnable_example " + name + " starting.");

        try {
            while (count < 5) {
                System.out.println(name + ": " + count);
                Thread.sleep(500);
                count++;
            }
        } catch (InterruptedException exc) {
            System.out.println("runnable_example interrupted");
        }

        System.out.println("runnable_example terminating");
    }

    public static void main(String[] args) {
        runnable_example instance = new runnable_example("Dragan");
        Thread thread = new Thread(instance);
        thread.start();

        // waits until above thread counts to 5 (slowly)
        while (instance.count != 5) {
            try {
                Thread.sleep(250);
            } catch (InterruptedException exc) {
                exc.printStackTrace();
            }
        }
    }
}
