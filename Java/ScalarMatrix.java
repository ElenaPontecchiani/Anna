public class ScalarMatrix extends DiagonalMatrix{

public ScalarMatrix(int dim)throws IndiceNonCorretto{
		super(dim);
	}

public ScalarMatrix(int dim, Object t)throws IndiceNonCorretto{
		super(dim,t);
	}


public final Object Det()throws IndiceNonCorretto{
	double a=ObjToDouble(getEl(0));
	 return (Object)Math.pow(a,getL());
	}
}