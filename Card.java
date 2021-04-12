public class Card {
	private int Value;
	private String FullCardName;
	private String ImageFileName;
	
	public int GetValue() { return this.Value; }
	public String GetFullCardName() { return this.FullCardName; }
	public String GetImageFileName() { return this.ImageFileName; }
	
	public void SetValue( int temp ) { this.Value = temp; }
	public void SetFullCardName( String temp ) { this.FullCardName = temp; }
	public void SetImageFileName( String temp ) { this.ImageFileName = temp; }

    public Card() {
		Value = 0;			FullCardName = "";
		ImageFileName = "";
	}
	
	public void setCard( int a, String b) {
        FullCardName = " of ";
        ImageFileName = "_";
        if (a >= 1 && a <= 52) {
            switch (a % 13) {
                case 1:
                    if (b == "H" || b == "h") {
                        Value = 11;
                    } else {
                    Value = 1;
                    }
                    FullCardName = "Ace" + FullCardName;
                    ImageFileName = ImageFileName + "ace";
                    break;
                case 2:
                    Value = 2;
                    FullCardName = "Two" + FullCardName;
                    ImageFileName = ImageFileName + "two";
                    break;
                case 3:
                    Value = 3;
                    FullCardName = "Three" + FullCardName;
                    ImageFileName = ImageFileName + "three";
                    break;
                case 4:
                    Value = 4;
                    FullCardName = "Four" + FullCardName;
                    ImageFileName = ImageFileName + "four";
                    break;
                case 5:
                    Value = 5;
                    FullCardName = "Five" + FullCardName;
                    ImageFileName = ImageFileName + "five";
                    break;
                case 6:
                    Value = 6;
                    FullCardName = "Six" + FullCardName;
                    ImageFileName = ImageFileName + "six";
                    break;
                case 7:
                    Value = 7;
                    FullCardName = "Seven" + FullCardName;
                    ImageFileName = ImageFileName + "seven";
                    break;
                case 8:
                    Value = 8;
                    FullCardName = "Eight" + FullCardName;
                    ImageFileName = ImageFileName + "eight";
                    break;
                case 9:
                    Value = 9;
                    FullCardName = "Nine" + FullCardName;
                    ImageFileName = ImageFileName + "nine";
                    break;
                case 10:
                    Value = 10;
                    FullCardName = "Ten" + FullCardName;
                    ImageFileName = ImageFileName + "ten";
                    break;
                case 11:
                    Value = 10;
                    FullCardName = "Jack" + FullCardName;
                    ImageFileName = ImageFileName + "jack";
                    break;
                case 12:
                    Value = 10;
                    FullCardName = "Queen" + FullCardName;
                    ImageFileName = ImageFileName + "queen";
                    break;
                case 0:
                    Value = 10;
                    FullCardName = "King" + FullCardName;
                    ImageFileName = ImageFileName + "king";
                    break;                
                default:
                    break;
            }
            switch (a / 13) {
                case 0:
                    FullCardName = FullCardName + "Spades";
                    ImageFileName = "spades" + ImageFileName;
                    break;
                case 1:
                    FullCardName = FullCardName + "Hearts";
                    ImageFileName = "hearts" + ImageFileName;
                    break;
                case 2:
                    FullCardName = FullCardName + "Clubs";
                    ImageFileName = "clubs" + ImageFileName;
                    break;
                case 3:
                    FullCardName = FullCardName + "Diamonds";
                    ImageFileName = "diamonds" + ImageFileName;
                    break;
                default:
                    break;
            }
            ImageFileName = ImageFileName + ".png";
        }
	}
	
	public void Display() {
		System.out.println("Card value: " + Value + 
						   "\nFull card name: " + FullCardName + 
                           "\nImage Name: " + ImageFileName);
	}
}