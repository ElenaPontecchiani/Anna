import java.io.*;//da togliere poi, solo per testare
import java.util.*;
import java.awt.*;



public class matrix<T> {//extend number crea problemi con cin, per ora tolto poi rimesso
	private  int h;
	private  int l;
	private  T[] raw_matrix; //va bene definirlo di tipo object

public matrix(){
     h=0;
	 l=0;
	 raw_matrix =(T[])new Object[0];	
	}

public matrix(int height, int length){
     if(height<=0) {h=1;}
	 if(length<=0) {l=1;}
	 h=height;
	 l=length;
	 raw_matrix =(T[])new Object[h*l];//CONVERSIONE NON SICURA
	 for(int i=0;i<l*h;i++){
			 raw_matrix[i]=(T)new Object();//altrementi sarebbe solo reference non inizializzato
			}
	}//ok
	
//I-O PER TEST	
public void Cin(int i)throws java.io.IOException {	
InputStreamReader reader = new InputStreamReader (System.in);
BufferedReader myInput = new BufferedReader (reader);
raw_matrix[i]=(T)myInput.readLine();
return ;}

public void Input()throws java.io.IOException{
try{
	for(int i=0;i<h*l;i++){
		Cin(i);//chiama una volta si e una no con for
		 }
	}
	catch(IOException e){e.printStackTrace();}
}

public  void Output()
{ for (int i = 0; i <h; i++)
	{for (int j = 0; j < l; j++)
	  { System.out.print(raw_matrix[i *l + j]+" ");
	  } System.out.print("\n");
	}
} 
 
 //metodi final get
 public final int getH(){
	return h;}

public final int getL(){
	return l;}
 
//T[] non statico e non può essere richiamato da una f statica
//serve questa f o basta System.arraycopy(m.raw_matrix,0,tArr,0,m.h*m.l)??/*private static Object[] copyArr(matrix<?> m){
	T[] tArr =(T[]) new Object[m.h*m.l];
	//for(int i=0;i<m.h*m.l;i++){tArr[i]=(T)new Object();}//vanno creati esplicitamente altrementi solo reference
  System.arraycopy(m.raw_matrix,0,tArr,0,m.h*m.l);
	  return tArr;
}*/

//qua va messo a double perche non riesce a fare op con T, provato anche con interfaccia
private double VectProd(matrix<?> m1, int row, matrix<?>  m2, int col){
	double sum= 0.0;
	 for (int i = 0; i < m2.h; i++){
		 String s1=m1.raw_matrix[i + m1.l * row].toString();
		 String s2=m2.raw_matrix[col + m2.l * i].toString();
		 double a=Double.parseDouble(s1);
		 double b=Double.parseDouble(s2);
		 sum+=a*b;	  
	  }
	  return sum;
}

/*
public matrix(matrix m){//non testato, non compila
	    h = m.h;
		l = m.l;
		raw_matrix=copyArr(m);
}	
*/
//distruttore eliminato, non serve

public boolean sameDim(matrix<?> m){
	  return (h == m.h && l == m.l);
	}


//usp f equals che confronta due stringhe, ok
public boolean equalsTo(matrix<?> m){
	if(sameDim(m)==false) return false;
	for(int i=0;i<m.h*m.l;i++){
	String s1=raw_matrix[i].toString();
	String s2=m.raw_matrix[i].toString();
	if (s1.equals(s2)==false) {return false;}
	}
	return true;
}


//overloding operatori: non supportati overloading classici 
public  matrix add(matrix<?> s){//ok
	if ((sameDim(s))==false){
	  //Throw///
		System.out.print("Non sommabile vezz");
		System.out.print("\n");
	  }
	  matrix temp = new matrix(s.h,s.l);
	  for (int i = 0; i < s.l *s.h; i++) {
		String s1=s.raw_matrix[i].toString();
		String s2=raw_matrix[i].toString();
		double a=Double.parseDouble(s1);
		double b=Double.parseDouble(s2);
		temp.raw_matrix[i] =a+b;
	  }
	  return temp;
}//compila con double
	

public matrix subtract(matrix<?> m){//ok
	  if ((sameDim(m))==false){
		//Throw///
		System.out.print("Non sommabile vezz");
		System.out.print("\n");
	  }
	  matrix temp = new matrix(h, l);
	  for (int i = 0; i < l * h; i++){
		  String s1=raw_matrix[i].toString();
	String s2=m.raw_matrix[i].toString();
	double dd1=Double.parseDouble(s1);
	double dd2=Double.parseDouble(s2);
		temp.raw_matrix[i] = dd1 - dd2;
	  }
	  return temp;
}//compila con double	
	
public matrix multiply(matrix<?> m){
	  if (l != m.h){
		System.out.print("VEzzzzzzzzz");
	  }
	  matrix temp = new matrix(h, m.l);
	  for (int i = 0; i < temp.h; i++) {
		for (int j = 0; j < temp.l; j++){
		  temp.raw_matrix[i * temp.l + j] = VectProd(this, i, m, j);
		}
	  }
	  return temp;
}//compila con double
	
//operazioni generali

public void Trasposta(){
	int h1=h;
	T[] trans =(T[])new Object[l*h];
	for (int i = 0; i < h; ++i) {
	  for (int j = 0; j < l; ++j){
		trans[j * h + i] = raw_matrix[i * l + j];}
	  }
	  h=l;l=h1;
	  raw_matrix=trans;
}//CAMBIATO LEGGERMENTE, COPIA DIM+ RAW MATRIX NON CON ASSEGNAZIONE PERCHè NON PRENDE *THIS=TRANS, compila

public boolean isInvertible(){
	  return false;
	}
	
public final void Fill(T t){
	  for (int i = 0; i < l * h; i++){
		raw_matrix[i] = t;
	  }
	}//compila
	
		
public final void Cut(int row_start, int row_num, int col_start, int col_num){
	  matrix temp = new matrix(row_num - row_start, col_num - col_start);
	  int pos = 0;
	  for (int r = row_start; r < row_num; r++) {
		for (int c = col_start; c < col_num; c++){
		  temp.raw_matrix[pos] = raw_matrix[r * l + c];
		  pos++;
		}
	  }
	  h=row_num - row_start;
	  l=col_num - col_start;
	  raw_matrix=(T[])temp.raw_matrix;
	  //this = temp;non lo fa:fatto campo per campo
	}	
	
public final void Append(matrix<?> m1){
	  if (m1.h != h) {
		System.out.print("PROBLEMA VEZZZ");
	  }
	  int pos = 0;
	  matrix temp = new matrix(m1.h, l + m1.l);
	  for (int r = 0; r < m1.h; r++) {
		for (int c = 0; c < l; c++){
		  temp.raw_matrix[pos] = raw_matrix[r * l + c];
		  pos++;
		}
		for (int c = 0; c < m1.l; c++){
		  temp.raw_matrix[pos] = m1.raw_matrix[r * m1.l + c];
		  pos++;
		}
	  }
	  h=m1.h;
	  l=l + m1.l;
	  raw_matrix=(T[])temp.raw_matrix;
}//compila	
	
	
public final void swap(int r1, int r2){
	  if (r1 != r2){
		T temp = null;
		for (int c = 0; c <l; c++){
		  temp = raw_matrix[r1 * l + c];
		  raw_matrix[r1 * l + c] = raw_matrix[r2 * l + c];
		  raw_matrix[r2 * l + c] = temp;
		}
	  }
	}


public final void divRow(int r, double coeff){
	  for (int c = 0; c < l; c++){
		if (raw_matrix[r * l + c] != null){
			String s1=raw_matrix[r * l + c].toString();
			double a=Double.parseDouble(s1);
		  raw_matrix[r * l + c] = (T)(Object)(a / coeff);
		}
	  }
	  
	}//compila	
	
	
public final int maxCoeff(int now_row, int now_col){
	  int max = now_row;
	  for (int r = now_row + 1; r < h; r++) {
		  String s1=raw_matrix[r * l + now_col].toString();
		  String s2=raw_matrix[max * l + now_col].toString();
		  double a=Double.parseDouble(s1);
		  double b=Double.parseDouble(s2);
		if (a> b){
		  max = r;
		}
	  }
	  return max;
	}	

	
public final void subRow(int r1, int r2, double coeff){
         if(coeff<=0) {coeff=1;}//rimpiazzare valore default
	  for (int c = 0; c < l; c++){
		  String s1=raw_matrix[r1 * l + c].toString();
		  String s2=raw_matrix[r2 * l + c] .toString();
		  double a=Double.parseDouble(s1);
		  double b=Double.parseDouble(s2);
		raw_matrix[r1 * l + c] =(T)(Object)(a-b* coeff);
	  }
	}
	



public static void main(String [ ] args){
	
	matrix m= new matrix(2,3);
	try{
	m.Input();
	}
	catch(IOException e){e.printStackTrace();}


m.Output();
//Object[]q=copyArr(m);
/*
matrix q=new matrix(2,3);
try{
	q.Input();
	}
	catch(IOException e){e.printStackTrace();}

q.Output();

//boolean qq=m.equalsTo(q);//ok

//double prodV=VectProd(m,0,q,0);ok
//System.out.print(prodV);

//Object []ff=copyArr(m);//ok
matrix l=add(q,m);
l.Output();
*/
}

}










