public class BankAccount {
	private int AccNum;
	private String CuFName;
	private String CuLName;
	private String CuAddr;
	private float CuBalance;
	
	public int GetAccNum() { return this.AccNum; }
	public String GetCuFName() { return this.CuFName; }
	public String GetCuLName() { return this.CuLName; }
	public String GetCuAddr() { return this.CuAddr; }
	public float GetCuBalance() { return this.CuBalance; }
	
	public void SetAccNum( int temp ) { this.AccNum = temp; }
	public void SetCuFName( String temp ) { this.CuFName = temp; }
	public void SetCuLName( String temp ) { this.CuLName = temp; }
	public void SetCuAddr( String temp ) { this.CuAddr = temp; }
	public void SetCuBalance( float temp ) { this.CuBalance = temp; }
	
	public BankAccount() {
		AccNum = 2;			CuFName = "empty";
		CuLName = "empty";	CuAddr = "empty";
		CuBalance = 2;
	}
	
	public BankAccount( int a, String b, String c, String d, float e ) {
		AccNum = a;			CuFName = b;
		CuLName = c;	CuAddr = d;
		CuBalance = e;
	}
	
	public BankAccount( String b, String c, String d) {
		AccNum = 2;			CuFName = b;
		CuLName = c;	CuAddr = d;
		CuBalance = 2;
	}
	
	public void Display() {
		System.out.println("Account number: " + AccNum + 
						   "\nFirst Name: " + CuFName + "\nLast Name: " + CuLName + 
						   "\nAddress: " + CuAddr + "\nBalance: " + CuBalance);
	}
}