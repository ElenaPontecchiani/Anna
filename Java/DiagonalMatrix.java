import java.io.*;
public class DiagonalMatrix extends SquareMatrix{

public DiagonalMatrix (int dim)throws IndiceNonCorretto{//no va bene chiamata cosi
		super(dim);
		this.fill(0);
		for (int i = 0; i < dim; i++){
		setRawEl(i * dim + i, 1);
	  }
}//chiamata a costruttore square matrix
	
public DiagonalMatrix(int dim, Object t)throws IndiceNonCorretto{
	 super(dim);
	 this.fill(0);
	  for (int i = 0; i < dim; i++){
		setRawEl(i * dim + i, t);
	  }
}

public DiagonalMatrix add(DiagonalMatrix s)throws DimensioniNonCorrette,IndiceNonCorretto{//ok
if ((sameDim(s))==false){
throw new DimensioniNonCorrette();}
else{
	  DiagonalMatrix temp = new DiagonalMatrix(this.getL());//giusto??
	  temp.copy(this);
	  for (int i = 0; i < getL(); i++){
		double a=ObjToDouble(temp.getEl(i * getL() + i));
		double b=ObjToDouble(s.getEl(i * getL() + i));
		a+=b;
		temp.setRawEl(i *getL() + i, a);
	  }
	  return temp;
}}

public DiagonalMatrix subtract(DiagonalMatrix s)throws DimensioniNonCorrette,IndiceNonCorretto{
if ((sameDim(s))==false){
throw new DimensioniNonCorrette();}
else{
	  DiagonalMatrix temp = new DiagonalMatrix(getL());//va bene costruzione??
	  temp.copy(this);
	  for (int i = 0; i < getL(); i++){
		double a=ObjToDouble(temp.getEl(i * getL() + i));
		double b=ObjToDouble(s.getEl(i * getL() + i));
		a-=b;
		temp.setRawEl(i * getL() + i, a);
	  }
	  return temp;
}}

public DiagonalMatrix multiply(DiagonalMatrix s)throws DimensioniNonCorrette,IndiceNonCorretto{//ok
if ((sameDim(s))==false){
throw new DimensioniNonCorrette();}
else{
	  DiagonalMatrix temp = new DiagonalMatrix(getL());
	  temp.fill(null);
	  for (int i = 0; i < getL(); i++){
		double a=ObjToDouble(temp.getEl(i * getL() + i));
		double b=ObjToDouble(s.getEl(i * getL() + i));
		a*=b;
		temp.setRawEl(i * getL() + i, a);
	  }
	  return temp;
}}

public DiagonalMatrix multiply(Object t)throws IndiceNonCorretto{//matrix??
	DiagonalMatrix temp = new DiagonalMatrix(getL());
	  temp.copy(this);
	  for (int i = 0; i < getL(); i++){
		double a=ObjToDouble(temp.getEl(i * getL() + i));
		double b=ObjToDouble(t);
		a*=b;
		temp.setRawEl(i * getL() + i, a);
	  }
	  return temp;
}

public Object Det()throws IndiceNonCorretto{
	  double t = 1.0;
	  for (int i = 0; i < getL(); i++){
		double a=ObjToDouble(getEl(i * this.getL() + i));
		t*=a;
		
	  }
	  return (Object)t;
}
	
public void trasposta(){//ok
}



public final void gauss(int col_num)throws IndiceNonCorretto{//ok
	  setDiag(1);
}


public final void gaussJordan(int col_num)throws IndiceNonCorretto{//ok
	  setDiag(1);
}

public final void setDiag(Object t)throws IndiceNonCorretto{//ok
	for (int i = 0; i < getL(); i++){
		setRawEl(i + getL() * i, t);
	  }
}

public static void main1(String [ ] args)throws IndiceNonCorretto{
	DiagonalMatrix m= new DiagonalMatrix(3);
	try{
	m.Input();}
	catch(IOException e){e.printStackTrace();}
m.fun2();		
}

public void fun2()throws IndiceNonCorretto{
/*
gaussJordan(3);*/
Object q=Det();
System.out.print(q);


}


}
