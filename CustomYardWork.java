import javax.swing.JOptionPane;

public class CustomYardWork {

    public static void main(String[] args) {
        String lengthString = JOptionPane.showInputDialog("Enter a length: ");
        int length = Integer.parseInt(lengthString);
        String widthString = JOptionPane.showInputDialog("Enter a width: ");
        int width = Integer.parseInt(widthString);
        JOptionPane.showMessageDialog(null, "You have " + length * width + " square feet to mow");
    }

}
