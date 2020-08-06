class H2O {
    Semaphore sh, so;

    public H2O() {
        sh = new Semaphore(2);
        so = new Semaphore(0);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		sh.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        so.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        so.acquire(2);
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        sh.release(2);
    }
}