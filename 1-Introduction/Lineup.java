import java.util.*;

class Lineup
{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
		ArrayList<String> v = new ArrayList<>();
		ArrayList<String> incr = new ArrayList<>();
		ArrayList<String> decr = new ArrayList<>();
		for(int i=0; i<n; i++){
			String s = in.next();
			v.add(s);
			incr.add(s);
			decr.add(s);
		}
		Collections.sort(incr);
		Collections.sort(decr, (s1, s2) -> s2.compareTo(s1));
		boolean flg = true;
		for(int i=0; i<n; i++){
			if(!v.get(i).equals(incr.get(i))){
				flg = false;
				break;
			}
		}
		if(flg){
			System.out.println("INCREASING");
			return;
		}
		flg = true;
		for(int i=0; i<n; i++){
			if(!v.get(i).equals(decr.get(i))){
				flg = false;
				break;
			}
		}
		if(flg){
			System.out.println("DECREASING");
			return;
		}
		System.out.println("NEITHER");
	}
}