public class Thread3 implements Runnable{
	private String name;
	private Object prev;
	private Object self;

	private Thread3(String name, Object prev, Object self){
		this.name = name;
		this.prev = prev;
		this.self = self;
	}

	public void run(){
		int count = 10;
		while(count > 0){
			synchronized(prev){
				synchronized(self){
					System.out.print(name);
					count--;
					self.notify();
				}

				try{
					prev.wait();
				}catch(InterruptedException e){
					e.printStackTrace();
				}
			}
		}
	}

	public static void main(String[] args) throws Exception{
		Object a = new Object();
		Object b = new Object();
		Object c = new Object();

		Thread3 t1 = new Thread3("A", c, a);
		Thread3 t2 = new Thread3("B", a, b);
		Thread3 t3 = new Thread3("C", b, c);

		new Thread(t1).start(); Thread.sleep(100);
		new Thread(t2).start(); Thread.sleep(100);
		new Thread(t3).start(); Thread.sleep(100);
	}
}

