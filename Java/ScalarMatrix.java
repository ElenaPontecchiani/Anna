import java.io.*;
public class ScalarMatrix extends DiagonalMatrix{

public ScalarMatrix(int dim)throws IndiceNonCorretto{
		super(dim);//chiamata costruttore diagonal
	}

public ScalarMatrix(int dim, Object t)throws IndiceNonCorretto{
		super(dim,t);
	}


public final Object Det()throws IndiceNonCorretto{//OK
	double a=ObjToDouble(getEl(0));
	//double b=(double)this.getL();//Double.parseDouble(this.getL());
	 return (Object)Math.pow(a,getL());
	}
	
public static void main2(String [ ] args)throws IndiceNonCorretto{
	ScalarMatrix m= new ScalarMatrix(2);
	try{
	m.Input();}
	catch(IOException e){e.printStackTrace();}
m.fun4();		
}

public void fun4()throws IndiceNonCorretto{
Object q=Det();
System.out.print(q);


}
}