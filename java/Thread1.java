class myThread extends Thread{
	private String name;
	public myThread(String name){
		this.name = name;
	}

	public void run(){
		System.out.println(Thread.currentThread().getName() + " Opps thread start"); 
		for(int i = 0; i < 5; i++){
			System.out.println(name +" run" + i);

			try{
				sleep((int ) Math.random() * 10);
			}catch (InterruptedException e){
				e.printStackTrace();
			}
		}
		System.out.println(Thread.currentThread().getName() + " Opps thread stop");
	}
}

public class Thread1 {
	public static void main(String[] args){
		System.out.println(Thread.currentThread().getName()+" main thread start!");
		myThread nth1 = new myThread("A");
		myThread nth2 = new myThread("B");

		nth1.start();
		nth2.start();

		try{
			nth1.join();
			nth2.join();
		}catch(InterruptedException e){
			e.printStackTrace();
		}

		System.out.println(Thread.currentThread().getName()+" main thread endss!");
	}
}
