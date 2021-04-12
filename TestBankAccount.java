public class TestBankAccount {
	public static void main(String[] args) {
		BankAccount test1 = new BankAccount();
		
		BankAccount test2 = new BankAccount("Ryan","Isnor","1 Acorn St.");

		BankAccount test3 = new BankAccount( 5, "Ryan", "Isnor", "1 Acorn St.", 750.33f);

		test1.Display();
		test2.Display();
		test3.Display();
		
		test1.SetAccNum(1);
		test1.SetCuFName("Ethan");
		test1.SetCuLName("Schaller");
		test1.SetCuAddr("12 Apple Dr.");
		test1.SetCuBalance(13.24f);
		
		System.out.println(test1.GetAccNum());
		System.out.println(test1.GetCuFName());
		System.out.println(test1.GetCuLName());
		System.out.println(test1.GetCuAddr());
		System.out.println(test1.GetCuBalance());
	}
}
