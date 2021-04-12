import javax.swing.JOptionPane;

public class MyHobby2 {
    public static void main( String[] args ) {
        String InputString;
        int score = 0;
        int wrong = 0;
        char Response;
        while (true) {
            InputString = JOptionPane.showInputDialog("What was Minecrafts original name?\n(a) Cave game tech test\n(b) Bricks and Mortar\n(c) Minetest\n(d) Voxel Cave");
            Response = InputString.charAt(0);
            if (Response == 'a') {
                score += 1;
                JOptionPane.showMessageDialog(null, "Correct!");
                break;
            }else{
                JOptionPane.showMessageDialog(null, "Incorrect, please try again.");
                wrong += 1;
            }
        }
        while (true) {
            InputString = JOptionPane.showInputDialog("What year was the full release of Minecraft: Java Edition?\n(a) 2010\n(b) 2011\n(c) 2012\n(d) 2013");
            Response = InputString.charAt(0);
            if (Response == 'b') {
                score += 1;
                JOptionPane.showMessageDialog(null, "Correct!");
                break;
            }else{
                JOptionPane.showMessageDialog(null, "Incorrect, please try again.");
                wrong += 1;
            }
        }
        while (true) {
            InputString = JOptionPane.showInputDialog("Who was the original creator of Minecraft?\n(a) Jens Bergensten\n(b) Daniel Rosenfeld\n(c) Nathan Adams\n(d) Markus Persson");
            Response = InputString.charAt(0);
            if (Response == 'd') {
                score += 1;
                JOptionPane.showMessageDialog(null, "Correct!");
                break;
            }else{
                JOptionPane.showMessageDialog(null, "Incorrect, please try again.");
                wrong += 1;
            }
        }
        while (true) {
            InputString = JOptionPane.showInputDialog("Where is the headquarters of Mojang Studios?\n(a) United Stated\n(b) United Kingdoms\n(c) Sweden\n(d) Japan");
            Response = InputString.charAt(0);
            if (Response == 'c') {
                score += 1;
                JOptionPane.showMessageDialog(null, "Correct!");
                break;
            }else{
                JOptionPane.showMessageDialog(null, "Incorrect, please try again.");
                wrong += 1;
            }
        }
        while (true) {
            InputString = JOptionPane.showInputDialog("How large is a minecraft chunk?\n(a) 8 x 8\n(b) 16 x 16\n(c) 32 x 32\n(d) 64 x 64");
            Response = InputString.charAt(0);
            if (Response == 'b') {
                score += 1;
                JOptionPane.showMessageDialog(null, "Correct!");
                break;
            }else{
                JOptionPane.showMessageDialog(null, "Incorrect, please try again.");
                wrong += 1;
            }
        }
        JOptionPane.showMessageDialog(null, "You got " + score + " correct and " + (wrong) + " incorrect.");
    }
}
