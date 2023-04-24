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

namespace PROG2500_A2_Chinook
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public Page Home { get; set; }
        public Page Artists { get; set; }
        public Page Albums { get; set; }
        public Page Tracks { get; set; }
        public Page CustomerOrders { get; set; }
        public Page MusicCatalog { get; set; }

        public MainWindow()
        {
            InitializeComponent();
            Home = new Pages.Home();
            Artists = new Pages.Artists();
            Albums = new Pages.Albums();
            Tracks = new Pages.Tracks();
            CustomerOrders = new Pages.CustomerOrders();
            MusicCatalog = new Pages.MusicCatalog();
            mainFrame.NavigationService.Navigate(Home);
        }

        private void HomeButton_Click(object sender, RoutedEventArgs e)
        {
            mainFrame.NavigationService.Navigate(Home);
        }

        private void ArtistsButton_Click(object sender, RoutedEventArgs e)
        {
            mainFrame.NavigationService.Navigate(Artists);
        }

        private void AlbumsButton_Click(object sender, RoutedEventArgs e)
        {
            mainFrame.NavigationService.Navigate(Albums);
        }

        private void TracksButton_Click(object sender, RoutedEventArgs e)
        {
            mainFrame.NavigationService.Navigate(Tracks);
        }

        private void MenuExit_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void CustomerOrdersButton_Click(object sender, RoutedEventArgs e)
        {
            mainFrame.NavigationService.Navigate(CustomerOrders);
        }

        private void MusicCatalogButton_Click(object sender, RoutedEventArgs e)
        {
            mainFrame.NavigationService.Navigate(MusicCatalog);
        }
    }
}
