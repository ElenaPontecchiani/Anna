public class Matrix{
	private  int h;
	private  int l;
	private  Object[] rawMatrix;

public Matrix(){
     h=0;
	 l=0;
	 rawMatrix =new Object[0];}

public Matrix(int height, int length){
     if(height<=0) {h=1;}
	 if(length<=0) {l=1;}
	 h=height;
	 l=length;
	 rawMatrix =new Object[h*l];
	 for(int i=0;i<l*h;i++)	 rawMatrix[i]=new Object();
	}
	

public void fillRawMatrix(Object[] ob){
	System.arraycopy(ob,0,rawMatrix,0,h*l);
}

public void fill(Object ob){
	for (int i=0;i<h*l;i++) rawMatrix[i]=ob;
}


 public final int getH(){
	return h;}

public final int getL(){
	return l;}

	
public final static double ObjToDouble(Object o){
	String s1=o.toString();
	return Double.parseDouble(s1);
}
	 	
public final Object getEl(int i)throws IndiceNonCorretto{
  if(i<0 || i>=h*l){throw new IndiceNonCorretto(i,l*h);}
  else return rawMatrix[i];
}

public final void setRawEl(int i,Object t)throws IndiceNonCorretto{
  if(i<0 || i>=h*l) throw new IndiceNonCorretto(i,l*h);
  else rawMatrix[i]=t;
 }	


private final static Object vectProd(Matrix m1, int row, Matrix  m2, int col){
	double sum=0.0;
	 for (int i = 0; i < m2.h; i++){
		 double a=ObjToDouble(m1.rawMatrix[i + m1.l * row]);
		 double b=ObjToDouble(m2.rawMatrix[col + m2.l * i]);
		 sum+=a*b;	 	
	  }
	  return (Object)sum;
}

public final void copy(Matrix m){
	    h = m.h;
		l = m.l;
		System.arraycopy(m.rawMatrix,0,rawMatrix,0,m.h*m.l);
}	

public final boolean sameDim(Matrix m){
	  return (h == m.h && l == m.l);
	}

public final boolean isMultBy(Matrix m){
    return (h==m.l);
}

public final boolean equalsTo(Matrix m){
	if(sameDim(m)==false) return false;
	for(int i=0;i<m.h*m.l;i++){
		String s1=rawMatrix[i].toString();
		String s2=m.rawMatrix[i].toString();
		if (s1.equals(s2)==false) {return false;}
	}
	return true;
}


public  Matrix add(Matrix s)throws DimensioniNonCorrette{
  if ((sameDim(s))==false) throw new DimensioniNonCorrette();
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
	}
}
	

public Matrix substract(Matrix m)throws DimensioniNonCorrette{
  if ((sameDim(m))==false) throw new DimensioniNonCorrette();
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
	}
}	
	
public Matrix multiply(Matrix m)throws DimensioniNonCorrette{
	if (isMultBy(m)==false) throw new DimensioniNonCorrette(); 
	else{
	  Matrix temp = new Matrix(h, m.l);
	  for (int i = 0; i < temp.h; i++) {
		for (int j = 0; j < temp.l; j++){
		  temp.rawMatrix[i * temp.l + j] = vectProd(this, i, m, j);
		}
	  }
	  return temp;
	}
}


	
public Matrix multiply(Object t)throws IndiceNonCorretto{
	Matrix temp = new Matrix(h,l);
	temp.copy(this);
	double b=ObjToDouble(t);
	for (int i = 0; i < temp.h; i++) {
		double a=ObjToDouble(temp.rawMatrix[i]);
		double c=a*b;
		temp.rawMatrix[i] =(Object)c;}
	return temp;
}

public void trasposta(){
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
	
		
public final void cut(int row_start, int row_num, int col_start, int col_num){
	Matrix temp = new Matrix(row_num - row_start, col_num - col_start);
	int pos = 0;
	for (int r = row_start; r < row_num; r++) {
		for (int c = col_start; c < col_num; c++){
		  temp.rawMatrix[pos] = rawMatrix[r * l + c];
		  pos++;
		}
	}
	copy(temp);
}	
	
public final void append(Matrix m1)throws DimensioniNonCorrette{
	if (m1.h != h) throw new DimensioniNonCorrette();
	int pos = 0;
	Matrix temp = new Matrix(m1.h, l + m1.l);
	for (int r = 0; r < m1.h; r++){
		for (int c = 0; c < l; c++){
		  temp.rawMatrix[pos] = rawMatrix[r * l + c];
		  pos++;
		}
		for (int c = 0; c < m1.l; c++){
		  temp.rawMatrix[pos] = m1.rawMatrix[r * m1.l + c];
		  pos++;
		}
	}
	copy(temp);
}	
		
public final void appendDown(Matrix m1)throws DimensioniNonCorrette, IndiceNonCorretto{
    if(m1.l != l) throw new DimensioniNonCorrette(); 
    int pos = 0;
    Matrix temp=new Matrix(h + m1.h,m1.l);
    int i = 0;
    for(; i < l*h; i++) temp.setRawEl(i,getEl(i));
    for(; i < temp.h*temp.l; i++) temp.setRawEl(i,m1.getEl(i-l*h));
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
			setRawEl(r * l + c,(Object)(x/b));}
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
         if(coeff<=0) {coeff=1;}
	  for (int c = 0; c < l; c++){
		  double a=ObjToDouble(rawMatrix[r1 * l + c]);
		  double b=ObjToDouble(rawMatrix[r2 * l + c]);
		rawMatrix[r1 * l + c] =(a-b* coeff);
	  }
	}


public void gauss(int col_num)throws IndiceNonCorretto{
  if (col_num == -1) col_num = l;
  int c = 0;
  for(int r = 0; r < h && c < col_num; r++){
    if(ObjToDouble(rawMatrix[r*l+c]) == 0){
      swap(r,maxCoeff(r,c));
      while (ObjToDouble(rawMatrix[maxCoeff(r,c)*l+c])== 0 && c < col_num)
			c++;
    }

    for(int i = r; i < h && c < col_num; i++)
      if(ObjToDouble(rawMatrix[i*l+c]) != 0){
        divRow(i,ObjToDouble(rawMatrix[i*l+c]));
      }


    for(int i = r + 1; i < h && c < col_num; i++)
      if(ObjToDouble(rawMatrix[i*l+c]) != 0)
        subRow(i,r,1);

    approxZero();

    c++;
  }

  for(int r = 0; r < h; r++){
      int minzeroInd = r;
      int minzero = col_num+1;
      for(int i = r; i < h; i++){
          int zeros = 0;
          for(int j = 0; j < c && ObjToDouble(rawMatrix[i*l+j]) == 0; j++){
              zeros++;
          }
          if (zeros < minzero){
              minzero = zeros;
              minzeroInd = i;
          }
      }
      if (minzeroInd != r)
          swap(r,minzeroInd);
  }

}


public void gaussJordan(int col_num)throws IndiceNonCorretto{
  if (col_num == -1) col_num = l;
  gauss(col_num);
  int r = h - 1;
  int rd;
  for(int c = col_num - 1; c >= 0 && r > 0; c--){
    rd = r;
    while( ObjToDouble(rawMatrix[rd*l+c]) != 1 && rd > 0 )
      rd--;
    if (rd > 0){
      for(int i = rd - 1; i >= 0; i--){
        subRow(i,rd,ObjToDouble(rawMatrix[i*l+c]));
      }
      r--;
    }
  }
}

public final void approxZero()throws IndiceNonCorretto{
  for(int i = 0; i < l*h; i++)
    if(Math.abs(ObjToDouble(getEl(i))) < 0.00000001)
	 setRawEl(i,0);
}



public void callMethod(String name, double n){
	if(name.equals("abs")){
		for(int i=0;i<h*l;i++){
			double c=ObjToDouble(rawMatrix[i]);
			rawMatrix[i]=Math.abs(c);}
		return;}	
	if(name.equals("cbrt")){
		for(int i=0;i<h*l;i++){
			double c=ObjToDouble(rawMatrix[i]);
			rawMatrix[i]=Math.cbrt(c);}
		return;}
		
	if(name.equals("log")){
		for(int i=0;i<h*l;i++){
			double c=ObjToDouble(rawMatrix[i]);
			rawMatrix[i]=Math.log(c);}
		return;}
	if(name.equals("log10")){
		for(int i=0;i<h*l;i++){
			double c=ObjToDouble(rawMatrix[i]);
			rawMatrix[i]=Math.log10(c);}
		return;}
	if(name.equals("pow")){
		for(int i=0;i<h*l;i++){
			double c=ObjToDouble(rawMatrix[i]);
			rawMatrix[i]=Math.pow(c,n);}
		return;}
	if(name.equals("sqrt")){
		for(int i=0;i<h*l;i++){
			double c=ObjToDouble(rawMatrix[i]);
			rawMatrix[i]=Math.sqrt(c);}
		return;}
	
	return;	
}

}







