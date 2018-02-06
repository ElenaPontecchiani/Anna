import java.io.*;
class Use{
public static void main(String [ ] args)throws DimensioniNonCorrette,IndiceNonCorretto{
//Matrix m1= new Matrix(3,4);   METTERE
//Object ob1=new Object[3*4];	METTERE
//ob1={1,2,0,0,0,1,1,0,1,1,2,3};METTERE
// m1.fillRawMatrix(ob1);		METTERE
//Matrix m2= new Matrix(3,4);	METTERE
//Object ob2=new Object[3*4];	METTERE
//ob1={1,3,4,1,0,1,1,0,1,1,2,3};METTERE
// m2.fillRawMatrix(ob2);		METTERE	
//Matrix m3= new Matrix(2,2);	METTERE
Matrix m4=new Matrix(4,3);//	METTERE
//Object ob4=new Object[4*3];//	METTERE
Object[]ob4 ={2,3,4,1,2,3,0,3,0,0,0,1};//METTERE
// m2.fillRawMatrix(ob2);
m4.fillRawMatrix(ob4);
//	try{
//	m1.Input();
//	m2.Input();
//	m3.Input();
//	m4.Input();
//	}
//	catch(IOException e){e.printStackTrace();}
m4.Output();
m4.gaussJordan(3);
System.out.println("\n");
m4.Output();
//Matrix m10=m1.add(m2);	METTERE

//Matrix m11=m1.substract(m3); METTERE
//Matrix m12=m1.multiply(m4); METTERE
//m4.trasposta(); METTERE
//m4.Output();
//m.fun();
}

/*public void fun(){

*/
}