import javax.swing.JOptionPane;

public class FourToGo {
    public static void main( String[] args ) {
        String InputString;
        int InputInteger;
        JankyFix: while (true) {
            InputString = JOptionPane.showInputDialog("Enter 1, 2, 3 or 4");
            try {
                InputInteger = Integer.parseInt(InputString);
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Something went wrong, input was not 1, 2, 3, or 4");
                continue;
            }
            switch (InputInteger) {
                case 1:
                    JOptionPane.showMessageDialog(null, "Thank You");
                    break;
                case 2:
                    JOptionPane.showMessageDialog(null, "Thank You");
                    break;
                case 3:
                    JOptionPane.showMessageDialog(null, "Thank You");
                    break;
                case 4:
                    break JankyFix;
                default:
                    JOptionPane.showMessageDialog(null, "Something went wrong, input was not 1, 2, 3, or 4");
                    break;
            }

        }
    }
}
