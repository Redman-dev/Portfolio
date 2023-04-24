using System.Windows;
using System.Windows.Controls;

namespace Media_Player
{
    /// <summary>
    /// Interaction logic for EditMediaTags.xaml
    /// </summary>
    public partial class EditMediaTags : UserControl
    {
        TagLib.File CurrentSong;
        public EditMediaTags()
        {
            InitializeComponent();
        }

        public void BSave_Click(object sender, RoutedEventArgs e)
        {
            if (CurrentSong != null)
            {
                CurrentSong.Tag.Title = TBTitle.Text;
                string[] artists;
                string[] divider = { ", " };
                artists = TBArtist.Text.Split(divider, System.StringSplitOptions.RemoveEmptyEntries);
                CurrentSong.Tag.Performers = artists;
                CurrentSong.Tag.Album = TBAlbum.Text;
                if (uint.TryParse(TBYear.Text, out uint year))
                {
                    CurrentSong.Tag.Year = year;
                } else
                {
                    CurrentSong.Tag.Year = 0;
                }
                //CurrentSong.Save();
                this.Visibility = Visibility.Hidden;
            }
        }

        public void Load_Song(TagLib.File file)
        {
            try
            {
                CurrentSong = file;
                TBTitle.Text = CurrentSong.Tag.Title;
                string[] artists = CurrentSong.Tag.Performers;
                TBArtist.Text = "";
                int count = 0;
                foreach (string artist in artists)
                {
                    count += 1;
                    if (count > 1)
                    {
                        TBArtist.Text += ", ";
                    }
                    TBArtist.Text += artist;
                }
                TBAlbum.Text = CurrentSong.Tag.Album;
                if (CurrentSong.Tag.Year != 0)
                {
                    TBYear.Text = CurrentSong.Tag.Year.ToString();
                }
            } 
            catch (System.NullReferenceException)
            {
                TBTitle.Text = "Error";
                TBArtist.Text = "Error";
                TBAlbum.Text = "Error";
                TBYear.Text = "Error";
            }
            
        }
    }
}
