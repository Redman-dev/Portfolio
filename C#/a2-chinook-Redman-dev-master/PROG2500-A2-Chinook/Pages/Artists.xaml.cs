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
    /// Interaction logic for Artists.xaml
    /// </summary>
    public partial class Artists : Page
    {
        ChinookContext _context = new ChinookContext();
        CollectionViewSource artistViewSource = new CollectionViewSource();
        public Artists()
        {
            InitializeComponent();
            _context.Artists.Load();
            string searchTerm = textsearch.Text;

            var query =
                from artist in _context.Artists
                where artist.Name.Contains(searchTerm)
                select artist;

            listArtistSearchResults.Items.Clear();
            foreach (var product in query)
            {
                listArtistSearchResults.Items.Add(product);
            }
        }
        private void SearchButton_Click(object sender, RoutedEventArgs e)
        {
            string searchTerm = textsearch.Text;

            var query =
                from artist in _context.Artists
                where artist.Name.Contains(searchTerm)
                select artist;

            listArtistSearchResults.Items.Clear();
            foreach (var product in query)
            {
                listArtistSearchResults.Items.Add(product);
            }
        }
    }
}
