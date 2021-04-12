public class TestBonCandy {
    public static void main(String[] args) {
        Candy test1 = new Candy();
        Candy test2 = new Candy("Blue", 5);
        BonBons test3 = new BonBons();
        BonBons test4 = new BonBons("Orange", 10, 12.00f, "Chocolate", 500);

        test1.SetColor("Red");
        test1.SetLength(3);
        
        System.out.println(test1.GetColor());
        System.out.println(test1.GetLength());

        test2.Display();

        test3.SetType("Gumdrops");
		test3.SetCalories(400);
		test3.SetLength(6);
		
		System.out.println(test3.GetType());
		System.out.println(test3.GetCalories());
		System.out.println(test3.GetLength());
        System.out.println(test3.GetColor());

        test3.Display();
        test4.Display();
    }
}
