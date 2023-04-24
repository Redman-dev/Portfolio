using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PROG2500_A2_Chinook.Models
{
    public partial class Track
    {
        public string TrackDetails
        {
            get
            {
                return string.Format("Length: {0} ms\nSize: {1} bytes\nPrice: ${2:N2}", Milliseconds, Bytes, UnitPrice);
            }
        }

        public string FormattedComposer
        {
            get
            {
                return string.Format("Composer: {0}", Composer);
            }
        }
    }
}
