class myThread2 implements Runnable{
	private String name;
	private int count;
	public myThread2(String name){
		this.name = name;
	}

	public void run() {
		for(int i = 0; i < 5; i++){

			System.out.println(name +" run: " + i);
			try{
				Thread.sleep((int) Math.random() * 10);
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	}
}

public class Thread2{

	public static void main(String[] args){
		new Thread(new myThread2("C")).start();
		new Thread(new myThread2("D")).start();
	}
}
