import javax.swing.JOptionPane;

public class CalculatePay {
    public static void main( String[] args ) {
        String InputString = JOptionPane.showInputDialog("What is your hourly pay?");
        float HourlyPR = Float.parseFloat(InputString);
        InputString = JOptionPane.showInputDialog("How many hours have you worked?");
        float HoursW = Float.parseFloat(InputString);
        float GrossPay = HourlyPR * HoursW;
        float WitholdongT = 0.0f;
        if (GrossPay > 0 && GrossPay <= 300.00f)
        {
            WitholdongT = 0.10f * GrossPay;
        }
        else if (GrossPay > 300.00f)
        {
            WitholdongT = 0.12f * GrossPay;
        }
        else
        {
            JOptionPane.showMessageDialog(null, "Something went wrong.");
        }
        float NetPay = GrossPay - WitholdongT;
        JOptionPane.showMessageDialog(null, "Your gross pay is: " + GrossPay + "\nYour witholding tax is: " + WitholdongT + "\nYour net pay is: " + NetPay);
    }
}
    