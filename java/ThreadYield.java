class MyThread extends Thread{
	public MyThread(String name){
		super(name);
	} 

	public void run(){
		for(int i = 1 ; i < 50; i++){
			if((i % 5) == 0){
				System.out.println(this.getName()+ "======" + i);
				this.yield();
			}
		}
	}
}

public class ThreadYield{
	public static void main(String[] args){
		MyThread mt1 = new MyThread("s");
		MyThread mt2 = new MyThread("l");

		mt1.start();
		mt2.start();
	}
}