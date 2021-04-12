import javax.swing.JOptionPane;

public class Table {
    public static void main( String[] args ) {
        String InputString = JOptionPane.showInputDialog("Choose 1 for pine, 2 for oak, 3 for mahogany");
        int WoodType = Integer.parseInt(InputString);
        float cost = 0.0f;
        if (WoodType == 1)
        {
            cost = 100.0f;
        }
        else if (WoodType == 2)
        {
            cost = 225.0f;
        }
        else if (WoodType == 3)
        {
            cost = 310.0f;
        }
        else
        {
            cost = 0.0f;
        }
        JOptionPane.showMessageDialog(null, "The cost of your table is: " + cost);
    }
}