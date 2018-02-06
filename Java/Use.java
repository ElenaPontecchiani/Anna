import java.io.*;
class Use{
public static void main(String [ ] args)throws DimensioniNonCorrette,IndiceNonCorretto{
	Matrix m1= new Matrix(3,4);   	
	Object[]ob1={1,2,0,0,0,1,1,0,1,1,2,3};
	m1.fillRawMatrix(ob1);
		
	Matrix m2= new Matrix(3,4);		
	Object[]ob2 ={1,3,4,1,0,1,1,0,1,1,2,3};
	m2.fillRawMatrix(ob2);	
	
	Matrix m3= new Matrix(3,4);	
	m3=m1.add(m2);	
	
	Matrix m4=new Matrix(4,3);	
	Object[]ob4 ={2,3,4,1,2,3,0,3,0,0,0,1};
	m4.fillRawMatrix(ob4);
	m4.trasposta();
	m4.gaussJordan(3);
	m4.Output();

	SquareMatrix mm1=new SquareMatrix(2);
	Object[]obb1 ={2,1,1,1};
	mm1.fillRawMatrix(obb1);
	boolean bool1=mm1.isSymmetric();
	Object q=mm1.Det();
	//mm1.Inversa();//////////corregere
	
	DiagonalMatrix dm1=new DiagonalMatrix(2);
	Object[]obd1 ={2,0,0,1};
	dm1.fillRawMatrix(obd1);

	DiagonalMatrix dm2=new DiagonalMatrix(2);
	Object[]obd2 ={3,0,0,4};
	dm2.fillRawMatrix(obd2);
	DiagonalMatrix dm3=dm1.multiply(dm2);
	Object q1=dm3.Det();
	dm3.gaussJordan(2);

	ScalarMatrix ds1=new ScalarMatrix(3);
	Object[]obs1 ={2,0,0,0,2,0,0,0,2};
	ds1.fillRawMatrix(obs1);
	Object q2=ds1.Det();
	ds1.gaussJordan(3);

	Vector v=new Vector(6,1);
	Object[]obv1 ={3,4,2,1,6,7};
	v.fillRawMatrix(obv1);
	boolean bool2=v.isColumn();
	v.Normalize();


}


}