import javax.swing.JOptionPane;

public class Coffee1 {
    public static void main(String[] args) {
        double price = 5.99;
        double tax = 15;
        String InputString;
        InputString = JOptionPane.showInputDialog("What is the weight of the cofee bag (in pounds)?");
        int bagWeight = Integer.parseInt(InputString);
        InputString = JOptionPane.showInputDialog("How many bags did you buy?");
        int bagCount = Integer.parseInt(InputString);
        double totalPrice = Math.round(100 * bagCount * bagWeight * price * (1 + (tax / 100.00))) / 100.00;
        JOptionPane.showMessageDialog(null, "Number of bags sold: " + bagCount +"\nWeight per bag: " + bagWeight + " lb\nPrice Per Pound: $" + price + "\nSales Tax: " + tax + "%\n-----------------------------------\nTotal Price: $" + totalPrice);
    }
}
