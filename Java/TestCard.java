public class TestCard {
    public static void main(String[] args) {
        Card test1 = new Card();
        Card test2 = new Card();

        test2.SetValue(1);
		test2.SetFullCardName("Ace of Spades");
		test2.SetImageFileName("spades_ace.png");
		
		System.out.println(test2.GetValue());
		System.out.println(test2.GetFullCardName());
		System.out.println(test2.GetImageFileName());

        test1.setCard( 27, "h" );

        test1.Display();
    }
}