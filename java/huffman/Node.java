/**
* code form tecent 
**/
public class Node{
	char data;
	int weight;
	int left, right, parent;
	public Node(char data, int weight){
		this.data = data;
		this.weight = weight;
	}

	public Node(int weight){
		this.weight = weight;
	}
}