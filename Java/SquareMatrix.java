//import java.io.*;
public class SquareMatrix extends Matrix{
public SquareMatrix(int dim){
		super(dim,dim);}
	
public final boolean isSymmetric(){
	 Matrix l=new Matrix(getH(),getL());
	 l.copy(this);
	 l.trasposta();
	 if(equalsTo(l)==true) return true;
	 return false;
}

public final boolean isInvertible()throws IndiceNonCorretto{
	  if(Det() != null) return true;
	  return false;
	}

public final void Inversa()throws IndiceNonCorretto,DimensioniNonCorrette{
		addId();
		gaussJordan(this.getL());
		cut(0, this.getH(), this.getH(), this.getH() * 2);
}

public Object Det()throws IndiceNonCorretto{
	if (this.getH() == 2){
			double a1=ObjToDouble(getEl(0));
			double a2=ObjToDouble(getEl(3));
			double a3=ObjToDouble(getEl(1));
			double a4=ObjToDouble(getEl(2));
			return (Object)(a1* a2 - a3 * a4);
	}
	double det = 0.0;
	int sign;
	for (int i = 0; i < getL(); i++){
		if (i % 2 == 0)	sign = 1;
		else sign = -1;
		double a1=ObjToDouble(getEl(i));
		double a2=ObjToDouble(WithOut(0, i).Det());
		det += a1 * sign * a2;
	}
	return (Object)det;
}

public final SquareMatrix WithOut(int row, int col)throws IndiceNonCorretto{
		SquareMatrix temp = new SquareMatrix(this.getH() - 1);
		int pos = 0;
		for (int r = 0; r < getH(); r++){
			for (int c = 0; c < getL(); c++){
				if (c != col && r != row){
					Object t=getEl(r * this.getL() + c);
					temp.setRawEl(pos++, t);
				}
			}
		}
	return temp;
}

public final void  addId()throws IndiceNonCorretto,DimensioniNonCorrette{
	SquareMatrix temp = new SquareMatrix(getL());
	temp.fill(0);
	for (int i = 0; i < getL() * getL(); i += getL() + 1){
			Object d = 1;
			temp.setRawEl(i, d);}
		this.append(temp);
	}
}