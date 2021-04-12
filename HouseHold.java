public class HouseHold {
    //Variable declaration, these are the variable names and types this object uses
    private String Address;
    private int Occupants;
    private float Yincome;

    //accessor functions returns value of variable called
    public String GetAddress() { return this.Address; }
	public int GetOccupants() { return this.Occupants; }
    public float GetYincome() { return this.Yincome; }

    //mutators, allow for changing value of variable type, returns nothing
    public void SetAddress( String temp ) { this.Address = temp; }
	public void SetOccupants( int temp ) { this.Occupants = temp; }
    public void SetYincome(float temp ) { this.Yincome = temp; }

    //Constrructors
    //Empty constructor, gives all variables default values
    public HouseHold() {
		this.Address = "";			this.Occupants = 1;
		this.Yincome = 0.0f;
	}

    //1 input constructor, sets occupants based on input but rest is set to default like empty constructor
    public HouseHold( int a ) {
		this.Address = "";			this.Occupants = a;
		this.Yincome = 0.0f;
	}

    //3 input constructor, all values are set at cretion
    public HouseHold( String a, int b, float c ) {
		this.Address = a;			this.Occupants = b;
		this.Yincome = c;
	}

    //Calculates the income per person in the household
    public float CalcPerPerson() {
        return ( this.Yincome / (float) this.Occupants );
    }

    //Display function
    public void Display() {
		System.out.println("Address: " + this.Address + 
						   "\nNumber of occupants: " + this.Occupants + 
                           "\nYearly Income: " + this.Yincome);
	}
}
