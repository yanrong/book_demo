public class QuickSort{

	private static void exchange(Node[] a, int i, int j){
		Node temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	private static int partition(Node[] a, int low, int high){
		int i = low, j = high + 1;
		int pivotkey = a[low].weight;

		while(true){
			while(a[--j].weight > pivotkey){ if(j == low) break; }
			while(a[++i].weight > pivotkey){ if(i == high) break; }
			if(i >= j) break;
			else exchange(a, low, j);
		}
		exchange(a, low, j);
		return j;
	}

	public static void sort(Node[] a, int low, int high){
		if(high <= low)	return ;

		int j = partition(a, low, high);
		sort(a, low, j - 1);
		sort(a, j + 1, high);
	}

	public static void sort(Node[] a){
		sort(a, 0, a.length -1);
	}
}