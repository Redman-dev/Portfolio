using System;
using System.ComponentModel.Design.Serialization;
using System.IO;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using Microsoft.Win32;

namespace Media_Player
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        bool Playing;
        EditMediaTags Form;
        TagLib.File tagFile;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void OpenFile_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog fileDlg = new OpenFileDialog();
            fileDlg.Filter = "MP3 Files (*.mp3)|*.mp3| All files (*.*)|*.*";
            if (fileDlg.ShowDialog() == true)
            {
                LoadSong(fileDlg.FileName);
            }
        }

        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void LoadSong(string filename)
        {
            tagFile = TagLib.File.Create(filename);
            MediaPlayer.Source = new System.Uri(filename);

            Refresh();

            //https://stackoverflow.com/questions/17904184/using-taglib-to-display-the-cover-art-in-a-image-box-in-wpf#:~:text=System.Drawing.Image%20currentImage%20%3D%20null%3B%20%2F%2F%20In%20method%20onclick,currentImage.GetThumbnailImage%20%28100%2C100%2C%20null%2C%20System.IntPtr.Zero%29%3B%20%7D%20ms.Close%20%28%29%3B%20%7D
            if (tagFile.Tag.Pictures.Length > 0)
            {
                TagLib.IPicture pic = tagFile.Tag.Pictures[0];
                MemoryStream ms = new MemoryStream(pic.Data.Data);
                ms.Seek(0, SeekOrigin.Begin);
                BitmapImage bitmap = new BitmapImage();
                bitmap.BeginInit();
                bitmap.StreamSource = ms;
                bitmap.EndInit();
                DefaultImage.Source = bitmap;
            }
            DispatcherTimer SongProgressCheck = new DispatcherTimer();
            SongProgressCheck.Tick += new EventHandler(SongProgressCheck_Tick);
            SongProgressCheck.Interval = new TimeSpan(0, 0, 0, 0, 300);
            SongProgressCheck.Start();
        }

        private void SongProgressCheck_Tick(object sender, EventArgs e)
        {
            if ((STimeline.Value < MediaPlayer.Position.TotalMilliseconds) && (MediaPlayer.Position.TotalMilliseconds < STimeline.Value + 500))
            {
                STimeline.Value = MediaPlayer.Position.TotalMilliseconds;
            }
        }

        //https://learn.microsoft.com/en-us/dotnet/desktop/wpf/graphics-multimedia/how-to-control-a-mediaelement-play-pause-stop-volume-and-speed?view=netframeworkdesktop-4.8
        private void BStop_Click(object sender, RoutedEventArgs e)
        {
            MediaPlayer.Stop();
            Playing = false;
            STimeline.Value = 0;
        }

        private void Refresh()
        {
            TBTitle.Text = "Title: ";
            TBArtist.Text = "Artist: ";
            TBAlbum.Text = "Album: ";
            string[] artists = tagFile.Tag.Performers;
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
            string album = tagFile.Tag.Album;
            TBAlbum.Text += album;
            string title = tagFile.Tag.Title;
            TBTitle.Text += title;
            if (tagFile.Tag.Year != 0)
            {
                TBAlbum.Text += " (" + tagFile.Tag.Year + ")";
            }
        }

        private void EditFile_Click(object sender, RoutedEventArgs e)
        {
            if (Form == null)
            {
                Form = new EditMediaTags();
                Grid.SetRow(Form, 1);
                grid1.Children.Add(Form);
                Form.VerticalAlignment = VerticalAlignment.Top;
                Form.SetValue(Panel.ZIndexProperty, 1);
                Form.IsVisibleChanged += new DependencyPropertyChangedEventHandler(Form_IsVisibleChanged);
            }
            Form.Load_Song(tagFile);
            Form.Visibility = Visibility.Visible;
        }

        private void BPausePlay_Click(object sender, RoutedEventArgs e)
        {
            if (Playing == true)
            {
                MediaPlayer.Pause();
            }
            else
            {
                MediaPlayer.Play();
                MediaPlayer.Volume = (double)SVolume.Value;
            }
            Playing = !Playing;
        }
        private void MenuPause_Click(object sender, RoutedEventArgs e)
        {
            MediaPlayer.Pause();
            Playing = false;
        }

        private void MenuPlay_Click(object sender, RoutedEventArgs e)
        {
            MediaPlayer.Play();
            Playing = true;
        }

        private void ChangeMediaVolume(object sender, RoutedPropertyChangedEventArgs<double> args)
        {
            MediaPlayer.Volume = (double)SVolume.Value;
        }

        private void Element_MediaOpened(object sender, EventArgs e)
        {
            STimeline.Maximum = MediaPlayer.NaturalDuration.TimeSpan.TotalMilliseconds;
        }

        private void Element_MediaEnded(object sender, EventArgs e)
        {
            STimeline.Value = 0;
            MediaPlayer.Stop();
            Playing = false;
        }

        private void STimeline_DragCompleted(object sender, System.Windows.Controls.Primitives.DragCompletedEventArgs e)
        {
            int SliderValue = (int)STimeline.Value;
            TimeSpan ts = new TimeSpan(0, 0, 0, 0, SliderValue);
            MediaPlayer.Position = ts;
        }

        private void Form_IsVisibleChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            if (Form.Visibility == Visibility.Hidden)
            {
                Refresh();

                try
                {
                    tagFile.Save();
                }
                catch (System.IO.IOException)
                {
                    TimeSpan ts = MediaPlayer.Position;
                    Uri song = MediaPlayer.Source;
                    MediaPlayer.Source = null;
                    Thread.Sleep(50);
                    tagFile.Save();
                    Thread.Sleep(50);
                    MediaPlayer.Source = song;
                    MediaPlayer.Position = ts;
                }
            }
        }
    }
}
