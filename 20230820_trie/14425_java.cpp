/*
public class Main {

	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int N, M;
		String[] NM = sc.nextLine().split("\\s");
		N = Integer.parseInt(NM[0]);
		M = Integer.parseInt(NM[1]);

		java.util.Set<String> stringSet = new java.util.HashSet<>(N);
		for (int i=0; i<N; i++) {
			stringSet.add(sc.nextLine());
		}
		String[] stringArr = new String[M];
		for (int i=0; i<M; i++) {
			stringArr[i] = sc.nextLine();
		}
		sc.close();
		int numMatches = 0;
		for (String str:stringArr) {
			if (stringSet.contains(str)) {
				numMatches++;
			}
		}
		System.out.println(numMatches);
	}

}
*/
