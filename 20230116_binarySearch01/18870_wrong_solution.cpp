/*
public class Main {
	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int N = sc.nextInt();
		int[] coordinateArr = new int[N];
		java.util.TreeSet<Integer> coordinateSet = new java.util.TreeSet<>();
		for (int i=0; i<N; i++) {
			int n = sc.nextInt();
			coordinateArr[i] = n;
			coordinateSet.add(n);			
		}
		sc.close();
		java.util.HashMap<Integer, Integer> coordinateMap = new java.util.HashMap<>();
		int idx = 0;
		for (int coordinate:coordinateSet) {
			coordinateMap.put(coordinate, idx);
			idx++;
		}
		int[] resultArr = new int[N];
		for (int i=0; i<N; i++) {
			resultArr[i] = coordinateMap.get(coordinateArr[i]);
		}
		for (int result:resultArr) {
			System.out.print(result);
			System.out.print(' ');
		}		
	}
}
*/