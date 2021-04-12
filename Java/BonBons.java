public class BonBons extends Candy {
    private String Type;
    private int Calories;

    public String GetType() { return this.Type; }
	public int GetCalories() { return this.Calories; }
	
	public void SetType( String temp ) { this.Type = temp; }
	public void SetCalories( int temp ) { this.Calories = temp; }
    public void SetLength( int temp ) { this.Length = temp; this.Price = temp * 2.50f;}

    public BonBons() {
        super();
        Type = "";
        Calories = 0;
    }

    public BonBons( String a, int b ,float c, String d, int e ) {
        super(a, b);
        Price = c;
        Type = d;
        Calories = e;
    }

    public void Display() {
		System.out.println("Candy color: " + Color + 
						   "\nCandy length: " + Length + 
                           "\nCandy price: " + Price +
                           "\nCandy type: " + Type +
                           "\nCandy calories: " + Calories);
	}
}
