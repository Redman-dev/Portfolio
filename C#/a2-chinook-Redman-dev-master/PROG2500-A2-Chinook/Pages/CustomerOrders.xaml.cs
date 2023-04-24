using Microsoft.EntityFrameworkCore;
using PROG2500_A2_Chinook.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace PROG2500_A2_Chinook.Pages
{
    /// <summary>
    /// Interaction logic for CustomerOrders.xaml
    /// </summary>
    public partial class CustomerOrders : Page
    {
        ChinookContext _context = new ChinookContext();
        public CustomerOrders()
        {
            InitializeComponent();
            _context.Customers.Load();
            _context.Invoices.Load();
            _context.InvoiceLines.Load();
            string searchTerm = textsearch.Text;

            var query =
                from customer in _context.Customers
                where (customer.FirstName + ' ' + customer.LastName).Contains(searchTerm)
                select customer;

            listCustomerSearchResults.Items.Clear();
            foreach (var customer in query)
            {
                listCustomerSearchResults.Items.Add(customer);
            }
        }

        private void SearchButton_Click(object sender, RoutedEventArgs e)
        {
            string searchTerm = textsearch.Text;

            var query =
                from customer in _context.Customers
                where (customer.FirstName + ' ' + customer.LastName).Contains(searchTerm)
                select customer;

            listCustomerSearchResults.Items.Clear();
            foreach (var customer in query)
            {
                listCustomerSearchResults.Items.Add(customer);
            }
        }
    }
}
