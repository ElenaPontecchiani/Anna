public class IndiceNonCorretto extends Throwable{
	private int in;
	private int max;
	public IndiceNonCorretto(int ii,int m){
		in=ii;max=m;
		System.out.print("indice i"+ii+" non rientra nelle dimensioni dell'array, comprese tra 0 e "+max);}
	
}