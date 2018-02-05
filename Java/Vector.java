import java.io.*;

public class Vector extends Matrix{
public Vector(int height, int length){
	super(height,length);
	}

public final double Euclidean_norm()throws IndiceNonCorretto{//ok
	  double temp = 0.0;
	  for (int i = 0; i < getL() * getH(); i++){
		double a=ObjToDouble(getEl(i));
		temp = temp + Math.pow(a,2);
	  }
	  return Math.sqrt(temp);
}
	
public final void Normalize()throws IndiceNonCorretto{
		double norm = this.Euclidean_norm();
		  for (int i = 0; i < this.getL() * this.getH(); i++){
			  double a=ObjToDouble(getEl(i));
			  double b=a/norm;
			  setRawEl(i, b);
			
		  }
	}

public final boolean isRow(){
	if((getH() == 1)==true) return true;
	return false;
	}

public final boolean isColumn(){
	if(this.isRow()==true) return false;
	return true;
	}

	
public static void main5(String [ ] args)throws IndiceNonCorretto{
	Vector m= new Vector(4,1);
	try{
	m.Input();}
	catch(IOException e){e.printStackTrace();}
m.fun5();		
}

public void fun5()throws IndiceNonCorretto{
Normalize();
Output();//se valori null qualche problema



}
	
	
	
	
}