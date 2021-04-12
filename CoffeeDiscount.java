import javax.swing.JOptionPane;

public class CoffeeDiscount {
    public static void main(String[] args) {
        double price = 5.99;
        double tax = 15;
        String InputString;
        InputString = JOptionPane.showInputDialog("What is the weight of the cofee bag (in pounds)?");
        int bagWeight = Integer.parseInt(InputString);
        InputString = JOptionPane.showInputDialog("How many bags did you buy?");
        int bagCount = Integer.parseInt(InputString);
        int Discount;
        if (bagCount >= 300) {
            Discount = 30;
        } else if (bagCount >= 200) {
            Discount = 25;
        } else if (bagCount >= 150) {
            Discount = 20;
        } else if (bagCount >= 100) {
            Discount = 15;
        } else if (bagCount >= 50) {
            Discount = 10;
        } else if (bagCount >= 25) {
            Discount = 5;
        } else {
            Discount = 0;
        }
        double totalPrice = Math.round(100 * bagCount * bagWeight * price * (1 + (tax / 100.00))) / 100.00;
        double DiscountAmount = Math.round(100 * totalPrice * Discount / 100) / 100.00;
        double ChargeAmount = Math.round(100 * (totalPrice - DiscountAmount)) / 100.00;
        JOptionPane.showMessageDialog(null, "Number of bags sold: " + bagCount +"\nWeight per bag: " + bagWeight + " lb\nPrice Per Pound: $" + price + "\nSales Tax: " + tax + "%\n-----------------------------------\nTotal Price: $" + totalPrice + "\n Discount (" + Discount + "%): -$" + DiscountAmount + "\n-----------------------------------\nAmount to be charged: $" + ChargeAmount);
    }
}
