using Microsoft.EntityFrameworkCore;
using PROG2500_A2_Chinook.Data;
using PROG2500_A2_Chinook.Models;
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
    /// Interaction logic for MusicCatalog.xaml
    /// </summary>
    public partial class MusicCatalog : Page
    {
        ChinookContext _context = new ChinookContext();
        public MusicCatalog()
        {
            InitializeComponent();
            _context.Artists.Load();
            _context.Albums.Load();
            _context.Tracks.Load();
            string searchTerm = textsearch.Text;

            var query =
                from artist in _context.Artists
                where artist.Name.Contains(searchTerm)
                group artist by artist.Name.ToUpper().Substring(0, 1) into newGroup
                select new
                {
                    Index = newGroup.Key,
                    ArtistCount = "(" + newGroup.Count().ToString() + ")",
                    ArtistList = newGroup.ToList<Artist>()
                };

            listCatalogSearchResults.Items.Clear();
            foreach (var customer in query)
            {
                listCatalogSearchResults.Items.Add(customer);
            }
        }
        private void SearchButton_Click(object sender, RoutedEventArgs e)
        {
            string searchTerm = textsearch.Text;

            var query =
                from artist in _context.Artists
                where artist.Name.Contains(searchTerm)
                group artist by artist.Name.ToUpper().Substring(0, 1) into newGroup
                select new
                {
                    Index = newGroup.Key,
                    ArtistCount = "(" + newGroup.Count().ToString() + ")",
                    ArtistList = newGroup.ToList<Artist>()
                };

            listCatalogSearchResults.Items.Clear();
            foreach (var customer in query)
            {
                listCatalogSearchResults.Items.Add(customer);
            }
        }
    }
}
