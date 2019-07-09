import java.util.Arrays;

public class HuffmanTree{
	int selectStart = 0;
	
	private class HuffmanCode{
		char data;
		String bit;
		public HuffmanCode(char data, String bit){
			this.data = data;
			this.bit = bit;
		}
	}

	private int select(Node[] HT, int range, int rank){
		Node[] copyNodes = Arrays.copyOf(HT, range);
		QuickSort.sort(copyNodes);
		Node target = copyNodes[rank + selectStart];
		for(int j = 0; j < HT.length; j++){
			if(target == HT[j]) return j;
		}

		return -1;
	}

	public Node[] buildTree(Node[] nodes){
		int s1, s2, p;

		int n = nodes.length;
		int m = 2*n - 1;
		Node[] HT = new Node[m];

		for(int i = 0; i < m; i++) HT[i] = new Node(0);
		for(int i = 0; i < n; i++){
			HT[i].data = nodes[i].data;
			HT[i].weight = nodes[i].weight;
		}

		for(int i = n; i < m; i++){
			s1 = select(HT, i, 0);
			s2 = select(HT, i, 1);
			HT[i].left = s1;
			HT[i].right = s2;
			HT[s1].parent = i;
			HT[s2].parent = i;
			HT[i].weight = HT[s1].weight + HT[s2].weight;

			selectStart += 2;
		}
		return HT;
	}

	public HuffmanCode[] encode(Node[] nodes){
		Node[] HT = buildTree(nodes);
		int n = nodes.length;

		HuffmanCode[] HC = new HuffmanCode[n];
		String bit;

		for(int i = 0; i < n; i++){
			bit = "";
			for(int c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent){
				if(HT[f].left == c) bit = "0" + bit;
				else bit = "1" + bit;
			}
			HC[i] = new HuffmanCode(HT[i].data, bit);
		}
		return HC;
	}

	public String decode (Node [] nodes, String code) {
    	String str = "";
    	Node [] HT = buildTree(nodes);
    	int n = HT.length -1;
    	for (int i = 0; i < code.length(); i++) {
      		char c = code.charAt(i);
      		if(c == '1') {
        		n = HT[n].right;
      		}else {
        		n = HT[n].left;
      		}
      		if(HT[n].left == 0) {
        		str += HT[n].data;
        		n = HT.length -1;
      		}
    	}
    	return str;
  	}

  	public static void main (String [] args) {
    	Node [] nodes = new Node[4];
    	nodes[0] = new Node('A',7);
    	nodes[1] = new Node('B',5);
    	nodes[2] = new Node('C',2);
    	nodes[3] = new Node('D',4);
    	HuffmanTree ht = new HuffmanTree();
    	System.out.println(ht.decode(nodes,"010110111"));
  	}
}