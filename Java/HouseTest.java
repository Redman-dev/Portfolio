public class HouseTest {
    public static void main(String[] args) {
        //Create 3 objects, one with each constructor
        HouseHold test1 = new HouseHold();//empty constructor
        HouseHold test2 = new HouseHold(4);//occupance constructor
        HouseHold test3 = new HouseHold("25 Apple Ct.", 2, 30000.0f);//all values constructor

        //test income per person
        System.out.println(test3.CalcPerPerson());//should return 1500.0

        //test accessors work
        System.out.println(test2.GetAddress());//should return blank
        System.out.println(test2.GetOccupants());//should return 4
        System.out.println(test2.GetYincome());//should return 0.0

        //test mutators
        test1.SetAddress("3 Orange Rd.");
        test1.SetOccupants(3);
        test1.SetYincome(44500.01f);

        //test display function
        test1.Display();
        //should return the following:
        //Address: 3 Orange Rd.
        //Number of occupants: 3
        //Yearly Income: 44500.01
    }
}
