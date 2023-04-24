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
    /// Interaction logic for Tracks.xaml
    /// </summary>
    public partial class Tracks : Page
    {
        ChinookContext _context = new ChinookContext();

        public Tracks()
        {
            InitializeComponent();
            _context.Tracks.Load();
            string searchTerm = textsearch.Text;

            var query =
                from track in _context.Tracks
                where track.Name.Contains(searchTerm)
                select track;

            listTrackSearchResults.Items.Clear();
            foreach (var track in query)
            {
                listTrackSearchResults.Items.Add(track);
            }
        }

        private void SearchButton_Click(object sender, RoutedEventArgs e)
        {
            string searchTerm = textsearch.Text;

            var query =
                from track in _context.Tracks
                where track.Name.Contains(searchTerm)
                select track;

            listTrackSearchResults.Items.Clear();
            foreach (var track in query)
            {
                listTrackSearchResults.Items.Add(track);
            }
        }
    }
}
