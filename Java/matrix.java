import java.io.*;//da togliere poi, solo per testare

public class Matrix{
	private  int h;
	private  int l;
	private  Object[] rawMatrix; //va bene definirlo di tipo object

public Matrix(){//volendo si può togliere
     h=0;
	 l=0;
	 rawMatrix =new Object[0];}

public Matrix(int height, int length){
     if(height<=0) {h=1;}
	 if(length<=0) {l=1;}
	 h=height;
	 l=length;
	 rawMatrix =new Object[h*l];//CONVERSIONE NON SICURA
	 for(int i=0;i<l*h;i++){
			 rawMatrix[i]=new Object();//altrementi sarebbe solo reference non inizializzato
			}
	}//ok
	
//I-O PER TEST	
public void Cin(int i)throws java.io.IOException {	
InputStreamReader reader = new InputStreamReader (System.in);
BufferedReader myInput = new BufferedReader (reader);
rawMatrix[i]=myInput.readLine();
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
	  { System.out.print(rawMatrix[i *l + j]+" ");
	  } System.out.print("\n");
	}
} 

public void fillRawMatrix(Object[] ob){
	System.arraycopy(ob,0,rawMatrix,0,h*l);
}


 //metodi final get
 public final int getH(){
	return h;}

public final int getL(){
	return l;}

	
public final static double ObjToDouble(Object o){
	String s1=o.toString();
	return Double.parseDouble(s1);
}
	
	
//come op subscripting, non esiste notazione 	
public final Object getEl(int i)throws IndiceNonCorretto{//ok
  if(i<0 || i>=h*l){throw new IndiceNonCorretto(i,l*h);}
  else return rawMatrix[i];
}

public final void setRawEl(int i,Object t)throws IndiceNonCorretto{//per settare el in subs., ovunque sia riciesta classe base posso mettere sottotipo???
  if(i<0 || i>=h*l){throw new IndiceNonCorretto(i,l*h);}
	//System.out.print("eccezione????");return null;}
  else rawMatrix[i]=t;
 }	


private final static Object[] copyArr(Matrix m){
	Object[] tArr =new Object[m.h*m.l];
	System.arraycopy(m.rawMatrix,0,tArr,0,m.h*m.l);
	return tArr;
}

public final static Object vectProd(Matrix m1, int row, Matrix  m2, int col){
	double sum=0.0;
	 for (int i = 0; i < m2.h; i++){
		 double a=ObjToDouble(m1.rawMatrix[i + m1.l * row]);
		 double b=ObjToDouble(m2.rawMatrix[col + m2.l * i]);
		 sum+=a*b;	 	
	  }
	  return (Object)sum;
}


public final void copy(Matrix m){//non esiste costrutto di default, OK!!
	    h = m.h;
		l = m.l;
		rawMatrix=copyArr(m);	
}	

//distruttore eliminato, non serve

public final boolean sameDim(Matrix m){
	  return (h == m.h && l == m.l);
	}

public final boolean isMultBy(Matrix m){
    if(h==m.l)return true;
	return false;
}
//usp f equals che confronta due stringhe, ok
public final boolean equalsTo(Matrix m){
	
	if(sameDim(m)==false) return false;
	for(int i=0;i<m.h*m.l;i++){
	String s1=rawMatrix[i].toString();
	String s2=m.rawMatrix[i].toString();
	if (s1.equals(s2)==false) {return false;}
	}
	return true;
}


//overloding operatori: non supportati overloading classici 
public  Matrix add(Matrix s)throws DimensioniNonCorrette{//ok
  if ((sameDim(s))==false){
	  throw new DimensioniNonCorrette();
	  }
  else{
	  Matrix temp = new Matrix(s.h,s.l);
	  double c;
	  for (int i = 0; i < s.l *s.h; i++) {
		double a=ObjToDouble(s.rawMatrix[i]);
		double b=ObjToDouble(rawMatrix[i]);
		 c=a+b;
		temp.rawMatrix[i]=(Object)c;
	  }
	  return temp;
}}
	

public Matrix substract(Matrix m)throws DimensioniNonCorrette{//ok
  if ((sameDim(m))==false){
		throw new DimensioniNonCorrette();
	  }
  else{
	  Matrix temp = new Matrix(h, l);
	  double c;
	  for (int i = 0; i < l * h; i++){
		  double a=ObjToDouble(m.rawMatrix[i]);
		double b=ObjToDouble(rawMatrix[i]);
		 c=a-b;
		temp.rawMatrix[i]=(Object)c;
	  }
	  return temp;
}}//compila con double	
	
public Matrix multiply(Matrix m)throws DimensioniNonCorrette{
	  if (isMultBy(m)==false){
		throw new DimensioniNonCorrette();
	  }
	 else{
	  Matrix temp = new Matrix(h, m.l);
	  for (int i = 0; i < temp.h; i++) {
		for (int j = 0; j < temp.l; j++){
		  temp.rawMatrix[i * temp.l + j] = vectProd(this, i, m, j);
		}
	  }
	  return temp;
}}


	
public Matrix multiply(Object t)throws IndiceNonCorretto{
	  Matrix temp = new Matrix(h,l);
	  temp.copy(this);//far copia el!!
	  double b=ObjToDouble(t);
	  for (int i = 0; i < temp.h; i++) {
		  double a=ObjToDouble(temp.rawMatrix[i]);
		  double c=a*b;
		  temp.rawMatrix[i] =(Object)c;
	  }
	  return temp;
}
	
//operazioni generali

public void trasposta(){//ok

	int h1=h;
	Object[] trans =new Object[l*h];
	for (int i = 0; i < h; ++i) {
	  for (int j = 0; j < l; ++j){
		trans[j * h + i] = rawMatrix[i * l + j];}
	  }
	  h=l;l=h1;
	 
	  System.arraycopy(trans,0,rawMatrix,0,h*l);

}

public boolean isInvertible()throws IndiceNonCorretto{
	  return false;
	}
	
public final void fill(Object t){
	  for (int i = 0; i < l * h; i++){
		rawMatrix[i] = t;
	  }
	}//compila
	
		
public final void cut(int row_start, int row_num, int col_start, int col_num){
	  Matrix temp = new Matrix(row_num - row_start, col_num - col_start);
	  int pos = 0;
	  for (int r = row_start; r < row_num; r++) {
		for (int c = col_start; c < col_num; c++){
		  temp.rawMatrix[pos] = rawMatrix[r * l + c];
		  pos++;
		}
	  }
	  h=row_num - row_start;
	  l=col_num - col_start;
	  copyArr(temp);
	  //this = temp;non lo fa:fatto campo per campo
	}	
	
public final void append(Matrix m1)throws DimensioniNonCorrette{
	  if (m1.h != h) {
		throw new DimensioniNonCorrette();
	  }
	  int pos = 0;
	  Matrix temp = new Matrix(m1.h, l + m1.l);
	  for (int r = 0; r < m1.h; r++) {
		for (int c = 0; c < l; c++){
		  temp.rawMatrix[pos] = rawMatrix[r * l + c];
		  pos++;
		}
		for (int c = 0; c < m1.l; c++){
		  temp.rawMatrix[pos] = m1.rawMatrix[r * m1.l + c];
		  pos++;
		}
	  }
	  h=m1.h;
	  l=l + m1.l;
	  copyArr(temp);
}//compila	
	
	
	
	
public final void appendDown(Matrix m1)throws DimensioniNonCorrette, IndiceNonCorretto{
  if(m1.l != l){
		throw new DimensioniNonCorrette();
	  }  
  int pos = 0;
  Matrix temp=new Matrix(h + m1.h,m1.l);
  int i = 0;
  for(; i < l*h; i++){
	  temp.setRawEl(i,getEl(i));
  }
  for(; i < temp.h*temp.l; i++){
	  
	  temp.setRawEl(i,m1.getEl(i-l*h));
  }
	copy(temp);
}
	
public final void swap(int r1, int r2){
	  if (r1 != r2){
		Object temp = 0.0;
		for (int c = 0; c <l; c++){
		  temp = rawMatrix[r1 * l + c];
		  rawMatrix[r1*l+c] = rawMatrix[r2*l+c];
		  rawMatrix[r2*l+c] = temp;
		}
	  }
	}


public final void divRow(int r, Object coeff)throws IndiceNonCorretto{
	 for (int c = 0; c < l; c++){
		 double x=ObjToDouble(rawMatrix[r * l + c]);
		if ( x!= 0.0){
			
		double b=ObjToDouble(coeff);
		setRawEl(r * l + c,(Object)(x/b));
		  
		}
	  }
	  
}
	
	
public final int maxCoeff(int now_row, int now_col){
	  int max = now_row;
	  for (int r = now_row + 1; r < h; r++) {
		  double a=ObjToDouble(rawMatrix[r * l + now_col]);
		  double b=ObjToDouble(rawMatrix[max * l + now_col]);
		if (a> b){
		  max = r;
		}
	  }
	  return max;
}	

	
public final void subRow(int r1, int r2, double coeff){
         if(coeff<=0) {coeff=1;}//rimpiazzare valore default
	  for (int c = 0; c < l; c++){
		  double a=ObjToDouble(rawMatrix[r1 * l + c]);
		  double b=ObjToDouble(rawMatrix[r2 * l + c]);
		rawMatrix[r1 * l + c] =(a-b* coeff);
	  }
	}

public int[] orderRaw(){
	boolean primaZero=false;int [] q=new int[h];
	for(int r=0;r<h;r++){
		q[r]=counZeroInLine(r);
	 }
    
  for(int r=0;r<h;r++){
	  if(q[r]>0){
		  for(int r1=r+1;r1<h;r1++){	 
			  if(q[r]>q[r1]){
				  swap(r,r1);
				  int tt=r1;r1=r;r=tt;
				  int temp=q[r1];
				  q[r1]=q[r];
				  q[r]=temp;
				  r--;
				 }
		   
		  }
	  }
	
  }

	return q; 
}
	
public int counZeroInLine(int r){
	boolean primaZero=false;
	int tot=0;
	for(int i=0;i<l;i++){
			 if((primaZero==true) &&(ObjToDouble(rawMatrix[r*l+i])!=0.0)){primaZero=false;}
			 else{
			 if(ObjToDouble(rawMatrix[r*l+i])==0.0){
				 if(i==0) {primaZero=true;tot++;} 
				 else{if(primaZero==true){tot++;} }
			 }  
		 }
		 }
	return tot;
}	

public void gauss(int col_num)throws IndiceNonCorretto{
	int[]q=orderRaw();//q per ogni riga dice quanti 0 prima di el !=0
	//per prima riga diversa tt zeri: metto a 1 primo el !=0 poi per altre sottaggo alla prima riga
	//controllo che primo el sia 1!
	double coef=1.0; boolean esci=false;
	for(int r=0;((esci==false)&&(r<h));r++){
		if(q[r]!=l)//se non è tutta riga di zeric
		{int in=r*l+q[r];
		 coef=ObjToDouble(rawMatrix[in]); esci=true;}
	}
	 divRow(0, coef);//ok
	for(int r=1;r<h;r++){
			if(q[r]==q[r-1]){//quando iva fatto sub row per slittare
		int in=r*l+q[r];
		double mm=ObjToDouble(rawMatrix[in]);
		subRow(r,r-1,mm);
		q[r]=counZeroInLine(r);}
	if(q[r]<l){
			int in=r*l+q[r];
			divRow(r,ObjToDouble(rawMatrix[in]));//metto piu 1 perche slitto di almeno 1????
			double d=ObjToDouble(rawMatrix[in]);}
		}		
	q=orderRaw();	
}
	
public int searchRow(int col, int rig){
	int r=rig+1;
	for(int i=rig*l+col;i<(h*l)-1;i+=l){
		if(ObjToDouble(rawMatrix[i])==1){return r-1;}
		r++;
	}
return -1;
}

public void gaussJordan(int col_num)throws IndiceNonCorretto{
	  gauss(col_num);
	  boolean unoInColonna=false;
	  for(int i=col_num-1;i>=0;i--){
	  unoInColonna=false;
		for(int r=h-1;r>=0;r--){
		  if((ObjToDouble(rawMatrix[r*l+i])==1.0)&&(unoInColonna==false))
				{unoInColonna=true;}
		  else{  
		  if(((ObjToDouble(rawMatrix[r*l+i])==1.0)&&(unoInColonna=true))||(ObjToDouble(rawMatrix[r*l+i])!=0.0)){
			  int rawSub=searchRow(i,r);//i indice col
			  subRow(r,rawSub,ObjToDouble(rawMatrix[r*l+i]));}
		  }
		 }
	}
}


public final void approxZero()throws IndiceNonCorretto{
  for(int i = 0; i < l*h; i++)
    if(Math.abs(ObjToDouble(getEl(i))) < 0.00000001)
	 setRawEl(i,0);
}
/*
public void gaussJordan(int col_num)throws IndiceNonCorretto{
	  if (col_num == -1) {
		col_num = l;
	  }
	  gauss(col_num);
	  int r = h - 1;
	  int rd;
	  for (int c = col_num - 1; c >= 0 && r > 0; c--) {
		rd = r;
		double a=ObjToDouble(rawMatrix[rd * l + c]);
		while ((a != 1.0 && rd > 0)==true){
		  rd--;
		}
		if (rd > 0){
		  for (int i = rd - 1; i >= 0; i--){ 
			double b=ObjToDouble(rawMatrix[i * l + c]);
			subRow(i, rd, b);//////messa una var a caso per compilare
		  }
		  r--;
		}
	  }
}*/





}
/*
funzioni eliminate nella vs java
	-distruttore
	-clone (non esistono punt in java)
	-cast a matrice di altro tipo

*/









