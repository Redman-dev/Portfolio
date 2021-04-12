import javax.swing.JOptionPane;

public class UserPaycheck {
    public static void main(String[] args) {
        double WitholdingTax = 0.1;
        String HourlyRateString = JOptionPane.showInputDialog("Enter your hourly rate: ");
        double HourlyRate = Double.parseDouble(HourlyRateString);
        String HoursWorkedString = JOptionPane.showInputDialog("Enter your hours worked: ");
        double HoursWorked = Double.parseDouble(HoursWorkedString);
        double GrossPay = Math.round(HourlyRate * HoursWorked * 100.0) / 100.0;
        double TaxAmount =  Math.round(WitholdingTax * HourlyRate * HoursWorked * 100.0) / 100.0;
        double NetPay = Math.round((GrossPay - TaxAmount) * 100.0) / 100.0;
        JOptionPane.showMessageDialog(null, "Your gross pay is: " + GrossPay + "\nYour witholding tax is: " + TaxAmount + "\nYour net pay is: " + NetPay);
    }
}
