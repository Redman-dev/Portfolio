import javax.swing.JOptionPane;

public class TableSize {
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
        if (cost != 0.0f)
        {
            InputString = JOptionPane.showInputDialog("Do you want a (l)arge table or a (s)mall table");
            char TableSize = InputString.charAt(0);
            if (TableSize == 'l')
            {
                cost += 35.0f;
            }
            else if (TableSize == 's')
            {
                cost += 0.0f;
            }
            else
            {
                JOptionPane.showMessageDialog(null, "Size not recognised, defaulting to small");
                cost += 0.0f;
            }
        }
        JOptionPane.showMessageDialog(null, "The cost of your table is: " + cost);
    }
}
