/*
public class Main {
	private static final int ROOT = 1;
    private static int unused = ROOT;
    private static final int MX = 500 * 41 + 5;
    private static boolean[] chk = new boolean[MX];
    private static String[] strArr = new String[MX];
    private static java.util.List<java.util.TreeMap<String, Integer>> nxt = new java.util.ArrayList<>();

    private static void init() {
        for (int i=0; i<MX; i++)
            nxt.add(new java.util.TreeMap<String, Integer>());
        strArr[ROOT] = "";
    }

    private static String whiteSpaces(int length) {
    	StringBuffer sb = new StringBuffer();
    	for (int i=0; i<length; i++) sb.append(' ');
    	return sb.toString();
    }

    private static void insert(String dir) {
    	String[] words = dir.split("\\\\");
    	//System.out.println(java.util.Arrays.toString(words));
    	int cur = ROOT;
    	int depth = 0;
    	for (String word:words) {
    		String newElem = whiteSpaces(depth)+word; //파일 또는 디렉터리의 이름 앞에 깊이에 해당하는 공백을 넣어서 문자열 newElem을 구성한다.
    		if (!nxt.get(cur).containsKey(newElem)) {
    			unused++;
    			nxt.get(cur).put(newElem, unused);
    			strArr[unused] = newElem;
    		}
    		cur = nxt.get(cur).get(newElem);
    		depth++;
    	}
    	chk[cur] = true;


    }

    private static void dfs(int cur) {
    	System.out.println(strArr[cur]);
    	for (java.util.Map.Entry<String, Integer> entry:nxt.get(cur).entrySet()) {
    		dfs(entry.getValue());
    	}
    }

	public static void main(String[] args) {
		init();
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int N = Integer.parseInt(sc.nextLine());
		for (int i=0; i<N; i++) {
			insert(sc.nextLine());
		}
		sc.close();
		for (java.util.Map.Entry<String, Integer> entry:nxt.get(ROOT).entrySet()) {
			dfs(entry.getValue());
		}
	}
}
*/
