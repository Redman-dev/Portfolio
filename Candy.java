public class Candy {
    protected String Color;
    protected int Length;
    protected float Price;

    public String GetColor() { return this.Color; }
	public int GetLength() { return this.Length; }

    public void SetColor( String temp ) { this.Color = temp; }
	public void SetLength( int temp ) { this.Length = temp; this.Price = temp * 0.75f;}

    public Candy() {
		Color = "black";			Length = 2;
		Price = 1.50f;
	}

    public Candy( String a, int b ) {
        Color = a;                  Length = b;
        Price = b * 0.75f;
    }

    public void Display() {
		System.out.println("Candy color: " + Color + 
						   "\nCandy length: " + Length + 
                           "\nCandy price: " + Price);
	}
}
